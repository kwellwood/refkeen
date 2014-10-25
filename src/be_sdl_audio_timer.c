#include "SDL.h"
#include "be_cross.h"
#include "be_sdl.h"
#include "opl/dbopl.h"

#define PC_PIT_RATE 1193182

static SDL_mutex* g_sdlCallbackMutex = NULL;
static SDL_AudioSpec g_sdlAudioSpec;
static bool g_sdlAudioSubsystemUp = false;
static uint32_t g_sdlSampleOffsetInSound, g_sdlSamplePerPart;
static void (*g_sdlCallbackSDFuncPtr)(void) = 0;

// Used for filling with samples from alOut (alOut_lLw), in addition
// to SD_SDL_CallBack (because waits between/after AdLib writes are expected)

#define OPL_NUM_OF_SAMPLES 512
#define OPL_SAMPLE_RATE 49716

static int16_t g_sdlALOutSamples[OPL_NUM_OF_SAMPLES];
static uint32_t g_sdlALOutSamplesStart = 0, g_sdlALOutSamplesEnd = 0;

// Sample rate conversion (from the OPL orate of ~49716Hz to mixing rate):
// For each one out of 49716 AdLib samples, tells how many times it should be repeated for the sake of conversion.
static int g_sdlALSampleRateConvTable[OPL_SAMPLE_RATE];
// Current location in the convertsion process;
static int g_sdlALSampleRateConvCurrIndex; // Index to g_sdlALSampleRateConvTable
static int g_sdlALSampleRateConvCounter; // Counter for current cell of g_sdlALSampleRateConvTable

//#define BE_SDL_ENABLE_LOW_PASS_FILTERING 1
#ifdef BE_SDL_ENABLE_LOW_PASS_FILTERING
// Used for low-pass filtering
static float g_sdlALLastSampleForFiltering;
static float g_sdlALFilteringAlpha;
#endif

// PC Speaker current status
static bool g_sdlPCSpeakerOn = false;
static int16_t g_sdlCurrentBeepSample;
static uint32_t g_sdlBeepHalfCycleCounter, g_sdlBeepHalfCycleCounterUpperBound;

// PIT timer divisor
static uint32_t g_sdlScaledTimerDivisor;

// A few variables used for timing measurements (PC_PIT_RATE units per second)
static uint64_t g_sdlLastPITTickTime;


// A PRIVATE TimeCount variable we store
// (SD_GetTimeCount/SD_SetTimeCount should be called instead)
static uint32_t g_sdlTimeCount;

static void BEL_SDL_CallBack(void *unused, Uint8 *stream, int len);
static inline bool YM3812Init(int numChips, int clock, int rate);

void BE_SDL_InitAudio(void)
{
	if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0)
	{
		BE_Cross_LogMessage(BE_LOG_MSG_WARNING, "SDL audio system initialization failed,\n%s\n", SDL_GetError());
	}
	else
	{
		g_sdlAudioSpec.freq = g_refKeenCfg.sndSampleRate;
		g_sdlAudioSpec.format = AUDIO_S16;
		g_sdlAudioSpec.channels = 1;
		// Under wine, small buffer sizes cause a lot of crackling, so
		// we doublt the buffer size. This will result in a tiny amount
		// (~10ms) of extra lag on windows, but it's a price I'm
		// prepared to pay to not have my ears explode.
#ifdef _WIN32
		g_sdlAudioSpec.samples = 1024;
#else
		g_sdlAudioSpec.samples = 512;
#endif
		g_sdlAudioSpec.callback = BEL_SDL_CallBack;
		g_sdlAudioSpec.userdata = NULL;
		if (SDL_OpenAudio(&g_sdlAudioSpec, NULL))
		{
			BE_Cross_LogMessage(BE_LOG_MSG_WARNING, "Cannot open SDL audio device,\n%s\n", SDL_GetError());
			SDL_QuitSubSystem(SDL_INIT_AUDIO);
		}
		else
		{
			g_sdlCallbackMutex = SDL_CreateMutex();
			if (!g_sdlCallbackMutex)
			{
				BE_Cross_LogMessage(BE_LOG_MSG_ERROR, "Cannot create recursive mutex for SDL audio callback,\n%s\nClosing SDL audio subsystem\n", SDL_GetError());
				SDL_CloseAudio();
				SDL_QuitSubSystem(SDL_INIT_AUDIO);
				g_sdlAudioSubsystemUp = false;
			}
			else
			{
				g_sdlAudioSubsystemUp = true;
			}
		}
		
		if (YM3812Init(1, 3579545, OPL_SAMPLE_RATE))
		{
			BE_Cross_LogMessage(BE_LOG_MSG_WARNING, "Preparation of emulated OPL chip has failed\n");
		}
		else
		{
			if (g_sdlAudioSpec.freq != OPL_SAMPLE_RATE)
			{
				// The some of all entries should be g_sdlAudioSpec.freq,
				// "uniformly" distributed over g_sdlALSampleRateConvTable
				for (int i = 0; i < OPL_SAMPLE_RATE; ++i)
				{
					// Using uint64_t cause an overflow is possible
					g_sdlALSampleRateConvTable[i] = ((uint64_t)(i+1)*(uint64_t)g_sdlAudioSpec.freq/OPL_SAMPLE_RATE)-(uint64_t)i*(uint64_t)g_sdlAudioSpec.freq/OPL_SAMPLE_RATE;
				}
#ifdef BE_SDL_ENABLE_LOW_PASS_FILTERING
				// Low-pass filtering can help in such a case
				if (g_sdlAudioSpec.freq < OPL_SAMPLE_RATE)
				{
					g_sdlALLastSampleForFiltering = 0.0;
					float RC = 1.0f/(2.0f*3.14159265358979f*g_sdlAudioSpec.freq);
					float dt = 1.0f/(float)OPL_SAMPLE_RATE;
					g_sdlALFilteringAlpha = dt/(RC + dt);
				}
#endif
			}
		}
	}
}

void BE_SDL_ShutdownAudio(void)
{
	if (g_sdlAudioSubsystemUp)
	{
		SDL_DestroyMutex(g_sdlCallbackMutex);
		g_sdlCallbackMutex = NULL;
		SDL_CloseAudio();
		SDL_QuitSubSystem(SDL_INIT_AUDIO);
		g_sdlAudioSubsystemUp = false;
	}
}

void BE_SDL_StartAudioSDService(void (*funcPtr)(void))
{
	if (g_sdlAudioSubsystemUp)
	{
		g_sdlCallbackSDFuncPtr = funcPtr;
		SDL_PauseAudio(0);
	}
}

void BE_SDL_StopAudioSDService(void)
{
	if (g_sdlAudioSubsystemUp)
	{
		SDL_PauseAudio(1);
		g_sdlCallbackSDFuncPtr = 0;
	}
}

void BE_SDL_LockAudioRecursively(void)
{
	if (g_sdlAudioSubsystemUp)
	{
		SDL_LockMutex(g_sdlCallbackMutex);
	}
}

void BE_SDL_UnlockAudioRecursively(void)
{
	if (g_sdlAudioSubsystemUp)
	{
		SDL_UnlockMutex(g_sdlCallbackMutex);
	}
}

// Frequency is about 1193182Hz/spkVal
void BE_SDL_PCSpeakerOn(uint16_t spkVal)
{
	if (g_sdlAudioSubsystemUp)
	{
		g_sdlPCSpeakerOn = true;
		g_sdlCurrentBeepSample = 0;
		g_sdlBeepHalfCycleCounter = 0;
		g_sdlBeepHalfCycleCounterUpperBound = g_sdlAudioSpec.freq * spkVal;
	}
}

void BE_SDL_PCSpeakerOff(void)
{
	if (g_sdlAudioSubsystemUp)
	{
		g_sdlPCSpeakerOn = false;
	}
}

void BE_SDL_BSound(uint16_t frequency)
{
	SDL_LockMutex(g_sdlCallbackMutex); // RECURSIVE lock
	BE_SDL_PCSpeakerOn(PC_PIT_RATE/(uint32_t)frequency);
	SDL_UnlockMutex(g_sdlCallbackMutex); // RECURSIVE unlock
}

void BE_SDL_BNoSound(void)
{
	SDL_LockMutex(g_sdlCallbackMutex); // RECURSIVE lock
	BE_SDL_PCSpeakerOff();
	SDL_UnlockMutex(g_sdlCallbackMutex); // RECURSIVE unlock
}

/*******************************************************************************
OPL emulation, powered by dbopl from DOSBox and using bits of code from Wolf4SDL
*******************************************************************************/

Chip oplChip;

static inline bool YM3812Init(int numChips, int clock, int rate)
{
	DBOPL_InitTables();
	Chip__Chip(&oplChip);
	Chip__Setup(&oplChip, rate);
	return false;
}

static inline void YM3812Write(Chip *which, Bit32u reg, Bit8u val)
{
	Chip__WriteReg(which, reg, val);
}

static inline void YM3812UpdateOne(Chip *which, int16_t *stream, int length)
{
	Bit32s buffer[512 * 2];
	int i;

	// length is at maximum samplesPerMusicTick = param_samplerate / 700
	// so 512 is sufficient for a sample rate of 358.4 kHz (default 44.1 kHz)
	if(length > 512)
		length = 512;
#if 0
	if(which->opl3Active)
	{
		Chip__GenerateBlock3(which, length, buffer);

		// GenerateBlock3 generates a number of "length" 32-bit stereo samples
		// so we need to convert them to 16-bit mono samples
		for(i = 0; i < length; i++)
		{
			// Scale volume and pick one channel
			Bit32s sample = 2*buffer[2*i];
			if(sample > 16383) sample = 16383;
			else if(sample < -16384) sample = -16384;
			stream[i] = sample;
		}
	}
	else
#endif
	{
		Chip__GenerateBlock2(which, length, buffer);

		// GenerateBlock2 generates a number of "length" 32-bit mono samples
		// so we only need to convert them to 16-bit mono samples
		for(i = 0; i < length; i++)
		{
			// Scale volume
			Bit32s sample = 2*buffer[i];
			if(sample > 16383) sample = 16383;
			else if(sample < -16384) sample = -16384;
			stream[i] = (int16_t) sample;
		}
	}
}

// Drop-in replacement for id_sd.c:alOut
void BE_SDL_ALOut(uint8_t reg,uint8_t val)
{
	if (g_sdlAudioSubsystemUp)
	{
		SDL_LockMutex(g_sdlCallbackMutex); // RECURSIVE lock

		// FIXME: The original code for alOut adds 6 reads of the
		// register port after writing to it (3.3 microseconds), and
		// then 35 more reads of register port after writing to the
		// data port (23 microseconds).
		//
		// It is apparently important for a portion of the fuse
		// breakage sound at the least. For now a hack is implied.
		YM3812Write(&oplChip, reg, val);
		// Hack comes with a "magic number"
		// that appears to make it work better
		int length = OPL_SAMPLE_RATE / 10000;
		// Circular buffer, shouldn't be too long...
		if (length > OPL_NUM_OF_SAMPLES - g_sdlALOutSamplesEnd)
		{
			YM3812UpdateOne(&oplChip, &g_sdlALOutSamples[g_sdlALOutSamplesEnd], OPL_NUM_OF_SAMPLES - g_sdlALOutSamplesEnd);
			length -= (OPL_NUM_OF_SAMPLES - g_sdlALOutSamplesEnd);
			g_sdlALOutSamplesEnd = 0;
		}
		if (length)
		{
			YM3812UpdateOne(&oplChip, &g_sdlALOutSamples[g_sdlALOutSamplesEnd], length);
			g_sdlALOutSamplesEnd += length;
		}

		SDL_UnlockMutex(g_sdlCallbackMutex); // RECURSIVE unlock
	}
}

/************************************************************************
PC Speaker emulation; The function mixes audio
into an EXISTING stream (of OPL sound data)
ASSUMPTION: The speaker is outputting sound (PCSpeakerUpdateOne == true).
************************************************************************/
static inline void PCSpeakerUpdateOne(int16_t *stream, int length)
{
	for (int loopVar = 0; loopVar < length; loopVar++, stream++)
	{
		*stream = (*stream + g_sdlCurrentBeepSample) / 2; // Mix
		g_sdlBeepHalfCycleCounter += 2 * PC_PIT_RATE;
		if (g_sdlBeepHalfCycleCounter >= g_sdlBeepHalfCycleCounterUpperBound)
		{
			g_sdlBeepHalfCycleCounter %= g_sdlBeepHalfCycleCounterUpperBound;
			// 32767 - too loud
			g_sdlCurrentBeepSample = 24575-g_sdlCurrentBeepSample;
		}
	}
}

#ifdef BE_SDL_ENABLE_LOW_PASS_FILTERING
// Within g_sdlALOutSamplesStart
static void BEL_SDL_ALDoLowPassFilter(uint32_t start, int len)
{
	uint32_t end = (start+len)%OPL_NUM_OF_SAMPLES;
	if (start <= end)
	{
		for (; start != end; ++start)
		{
			g_sdlALLastSampleForFiltering = (1.0f-g_sdlALFilteringAlpha)*g_sdlALLastSampleForFiltering + g_sdlALFilteringAlpha*(float)(g_sdlALOutSamples[start]);
			g_sdlALOutSamples[start] = g_sdlALLastSampleForFiltering;
		}
	}
	else
	{
		for (; start != OPL_NUM_OF_SAMPLES; ++start)
		{
			g_sdlALLastSampleForFiltering = (1.0f-g_sdlALFilteringAlpha)*g_sdlALLastSampleForFiltering + g_sdlALFilteringAlpha*(float)(g_sdlALOutSamples[start]);
			g_sdlALOutSamples[start] = g_sdlALLastSampleForFiltering;
		}
		// Wrap around
		for (start = 0; start != end; ++start)
		{
			g_sdlALLastSampleForFiltering = (1.0f-g_sdlALFilteringAlpha)*g_sdlALLastSampleForFiltering + g_sdlALFilteringAlpha*(float)(g_sdlALOutSamples[start]);
			g_sdlALOutSamples[start] = g_sdlALLastSampleForFiltering;
		}

	}
}
#endif

// BIG BIG FIXME: This is the VERY(?) wrong place to call the OPL emulator, etc!
static void BEL_SDL_CallBack(void *unused, Uint8 *stream, int len)
{
	int16_t *currSamplePtr = (int16_t *)stream;
	uint32_t currNumOfSamples;
	bool isPartCompleted;
#if SDL_VERSION_ATLEAST(1,3,0)
	memset(stream, 0, len);
#endif
	//////////////////////////////////
	SDL_LockMutex(g_sdlCallbackMutex); // RECURSIVE lock
	//////////////////////////////////
	
	while (len)
	{
		if (!g_sdlSampleOffsetInSound)
		{
			// FUNCTION VARIABLE (TODO any need to use a var?)
			g_sdlCallbackSDFuncPtr();
		}
		// Now generate sound
		isPartCompleted = (len >= 2*(g_sdlSamplePerPart-g_sdlSampleOffsetInSound));
		currNumOfSamples = isPartCompleted ? (g_sdlSamplePerPart-g_sdlSampleOffsetInSound) : (len/2);
		/*** AdLib (including hack for alOut delays) ***/
		// Relatively simple case
		if (g_sdlAudioSpec.freq == OPL_SAMPLE_RATE)
		{
			uint32_t noOfALSamplesAvailable = (g_sdlALOutSamplesEnd-g_sdlALOutSamplesStart) % OPL_NUM_OF_SAMPLES; // Circular buffer
			if (noOfALSamplesAvailable <= currNumOfSamples)
			{
				// Copy sound generated by alOut
				if (noOfALSamplesAvailable > 0)
				{
					if (g_sdlALOutSamplesStart < g_sdlALOutSamplesEnd)
					{
						memcpy(currSamplePtr, &g_sdlALOutSamples[g_sdlALOutSamplesStart], 2*noOfALSamplesAvailable);
					}
					else // Circular buffer wrapping
					{
						memcpy(currSamplePtr, &g_sdlALOutSamples[g_sdlALOutSamplesStart], 2*(OPL_NUM_OF_SAMPLES-g_sdlALOutSamplesStart));
						memcpy(currSamplePtr+(OPL_NUM_OF_SAMPLES-g_sdlALOutSamplesStart), g_sdlALOutSamples, 2*g_sdlALOutSamplesEnd);
					}
				}
				// Generate what's left
				if (currNumOfSamples-noOfALSamplesAvailable > 0)
				{
					YM3812UpdateOne(&oplChip, currSamplePtr+noOfALSamplesAvailable, currNumOfSamples-noOfALSamplesAvailable);
				}
				// Finally update these
				g_sdlALOutSamplesStart = g_sdlALOutSamplesEnd = 0;
			}
			else
			{
				// Already generated enough by alOut, to be copied
				if (g_sdlALOutSamplesStart+currNumOfSamples <= OPL_NUM_OF_SAMPLES)
				{
					memcpy(currSamplePtr, &g_sdlALOutSamples[g_sdlALOutSamplesStart], 2*currNumOfSamples);
				}
				else // Circular buffer wrapping
				{
					memcpy(currSamplePtr, &g_sdlALOutSamples[g_sdlALOutSamplesStart], 2*(OPL_NUM_OF_SAMPLES-g_sdlALOutSamplesStart));
					memcpy(currSamplePtr+(OPL_NUM_OF_SAMPLES-g_sdlALOutSamplesStart), g_sdlALOutSamples, 2*currNumOfSamples-2*(OPL_NUM_OF_SAMPLES-g_sdlALOutSamplesStart));
				}
				g_sdlALOutSamplesStart += currNumOfSamples;
				g_sdlALOutSamplesStart %= OPL_NUM_OF_SAMPLES;
			}
		}
		else // g_sdlAudioSpec.freq != OPL_SAMPLE_RATE so we should interpolate
		{
			int16_t *currCopiedALSamplePtr = currSamplePtr;
			int16_t *copiedALSamplesEnd = currSamplePtr+currNumOfSamples;
#ifdef BE_SDL_ENABLE_LOW_PASS_FILTERING
			// If we need to apply a low-pass filter, first calculate how much AL samples should we process
			if (g_sdlAudioSpec.freq < OPL_SAMPLE_RATE)
			{
				int16_t *copiedALStart = currCopiedALSamplePtr;
				int alInputLen = 0;
				// Should still be good to use similar interpolation for silence;
				// But first we want to copy these table counters
				int alSampleRateConvCounterLocal = g_sdlALSampleRateConvCounter;
				int alSampleRateConvCurrIndexLocal = g_sdlALSampleRateConvCurrIndex;
				while (copiedALStart < copiedALSamplesEnd)
				{
					if (!alSampleRateConvCounterLocal)
					{
						++alInputLen;
					}
					// Take AL sample and store in output buffer
					if (alSampleRateConvCounterLocal < g_sdlALSampleRateConvTable[alSampleRateConvCurrIndexLocal])
					{
						++alSampleRateConvCounterLocal;
						++copiedALStart;
					}
					// Time to go to next AL silence sample
					if (alSampleRateConvCounterLocal >= g_sdlALSampleRateConvTable[alSampleRateConvCurrIndexLocal])
					{
						alSampleRateConvCounterLocal = 0;
						++alSampleRateConvCurrIndexLocal;
						alSampleRateConvCurrIndexLocal %= OPL_SAMPLE_RATE;
					}
				}
				BEL_SDL_ALDoLowPassFilter(g_sdlALOutSamplesStart, alInputLen);
			}
#endif
			// Go over AL samples generated so far and interpolate
			while ((g_sdlALOutSamplesStart != g_sdlALOutSamplesEnd) && (currCopiedALSamplePtr < copiedALSamplesEnd))
			{
				// Take AL sample and store in output buffer
				if (g_sdlALSampleRateConvCounter < g_sdlALSampleRateConvTable[g_sdlALSampleRateConvCurrIndex])
				{
					++g_sdlALSampleRateConvCounter;
					*(currCopiedALSamplePtr++) = g_sdlALOutSamples[g_sdlALOutSamplesStart];
				}
				// Time to go to next AL sample
				if (g_sdlALSampleRateConvCounter >= g_sdlALSampleRateConvTable[g_sdlALSampleRateConvCurrIndex])
				{
					g_sdlALSampleRateConvCounter = 0;
					++g_sdlALSampleRateConvCurrIndex;
					g_sdlALSampleRateConvCurrIndex %= OPL_SAMPLE_RATE;
					++g_sdlALOutSamplesStart;
					g_sdlALOutSamplesStart %= OPL_NUM_OF_SAMPLES;
				}
			}
			// Need to generate extra AdLib silence?
			if (currCopiedALSamplePtr < copiedALSamplesEnd)
			{
				int16_t *copiedALStart = currCopiedALSamplePtr;
				int alInputLen = 0;
				// Should still be good to use similar interpolation for silence;
				// But first we want to copy these table counters
				int alSampleRateConvCounterLocal = g_sdlALSampleRateConvCounter;
				int alSampleRateConvCurrIndexLocal = g_sdlALSampleRateConvCurrIndex;
				while (copiedALStart < copiedALSamplesEnd)
				{
					if (!alSampleRateConvCounterLocal)
					{
						++alInputLen;
					}
					// Take AL sample and store in output buffer
					if (alSampleRateConvCounterLocal < g_sdlALSampleRateConvTable[alSampleRateConvCurrIndexLocal])
					{
						++alSampleRateConvCounterLocal;
						++copiedALStart;
					}
					// Time to go to next AL silence sample
					if (alSampleRateConvCounterLocal >= g_sdlALSampleRateConvTable[alSampleRateConvCurrIndexLocal])
					{
						alSampleRateConvCounterLocal = 0;
						++alSampleRateConvCurrIndexLocal;
						alSampleRateConvCurrIndexLocal %= OPL_SAMPLE_RATE;
					}
				}
				// Finally we know how many (new) samples should be generated
				// But just to prevent buffer overflow (shouldn't happen in a "proper" situation)...
				g_sdlALOutSamplesStart = 0;
				// Just in case (SHOULDN'T HAPPEN)
				alInputLen = (alInputLen > OPL_NUM_OF_SAMPLES) ? OPL_NUM_OF_SAMPLES : alInputLen;
				//
				YM3812UpdateOne(&oplChip, g_sdlALOutSamples, alInputLen);
#ifdef BE_SDL_ENABLE_LOW_PASS_FILTERING
				if (g_sdlAudioSpec.freq < OPL_SAMPLE_RATE)
				{
					BEL_SDL_ALDoLowPassFilter(0, alInputLen);
				}
#endif
				// Repeat the above loop, but with the global counter variables and, storing silence
				while (currCopiedALSamplePtr < copiedALSamplesEnd)
				{
					// Take AL sample and store in output buffer
					if (g_sdlALSampleRateConvCounter < g_sdlALSampleRateConvTable[g_sdlALSampleRateConvCurrIndex])
					{
						++g_sdlALSampleRateConvCounter;
						*(currCopiedALSamplePtr++) = g_sdlALOutSamples[g_sdlALOutSamplesStart];
					}
					if (g_sdlALSampleRateConvCounter >= g_sdlALSampleRateConvTable[g_sdlALSampleRateConvCurrIndex])
					// Time to go to next AL silence sample
					{
						g_sdlALSampleRateConvCounter = 0;
						++g_sdlALSampleRateConvCurrIndex;
						g_sdlALSampleRateConvCurrIndex %= OPL_SAMPLE_RATE;
						++g_sdlALOutSamplesStart;
						//No need to do this here now
						//g_sdlALOutSamplesStart %= OPL_NUM_OF_SAMPLES;
					}
				}
				// DON'T FORGET THESE!
				g_sdlALOutSamplesStart = g_sdlALOutSamplesEnd = 0;
			}
		}
		// PC Speaker
		if (g_sdlPCSpeakerOn)
			PCSpeakerUpdateOne(currSamplePtr, currNumOfSamples);
		// We're done for now
		currSamplePtr += currNumOfSamples;
		g_sdlSampleOffsetInSound += currNumOfSamples;
		len -= 2*currNumOfSamples;
		// End of part?
		if (g_sdlSampleOffsetInSound >= g_sdlSamplePerPart)
		{
			g_sdlSampleOffsetInSound = 0;
		}
	}

	////////////////////////////////////
	SDL_UnlockMutex(g_sdlCallbackMutex); // RECURSIVE unlock
	////////////////////////////////////
}

// Here, the actual rate is about 1193182Hz/speed
// NOTE: isALMusicOn is irrelevant for Keen Dreams (even with its music code)
void BE_SDL_SetTimer(uint16_t speed, bool isALMusicOn)
{
	g_sdlSamplePerPart = (int32_t)speed * g_sdlAudioSpec.freq / PC_PIT_RATE;
	// In the original code, the id_sd.c:SDL_t0Service callback
	// is responsible for incrementing TimeCount at a given rate
	// (~70Hz), although the rate in which the service itself is
	// 560Hz with music on and 140Hz otherwise.
	g_sdlScaledTimerDivisor = isALMusicOn ? (speed*8) : (speed*2);
}

uint32_t BE_SDL_GetTimeCount(void)
{
	// FIXME: What happens when SDL_GetTicks() reaches the upper bound?
	// May be challenging to fix... A proper solution should
	// only work with *differences between SDL_GetTicks values*.
	uint64_t currPitTicks = (uint64_t)(SDL_GetTicks()) * PC_PIT_RATE / 1000;
	uint32_t ticksToAdd = (currPitTicks - g_sdlLastPITTickTime) / g_sdlScaledTimerDivisor;
	g_sdlLastPITTickTime += ticksToAdd * g_sdlScaledTimerDivisor;
	g_sdlTimeCount += ticksToAdd;
	return g_sdlTimeCount;
}

void BE_SDL_SetTimeCount(uint32_t newcount)
{
	g_sdlTimeCount = newcount;
}
