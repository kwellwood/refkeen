// This header MUST be included early, so macros can be properly used

#ifndef _REFKEEN_CONFIG_H_
#define _REFKEEN_CONFIG_H_

// BIG ***FIXME*** - Should probably be externally generated instead
#include "SDL_endian.h"
#if SDL_BYTEORDER == SDL_LIL_ENDIAN
#define REFKEEN_ARCH_LITTLE_ENDIAN
#elif SDL_BYTEORDER == SDL_BIG_ENDIAN
#define REFKEEN_ARCH_BIG_ENDIAN
#endif

// Note: There may be multiple platform definitions at once,
// say REFKEEN_PLATFORM_ANDROID/EMSCRIPTEN and REFKEEN_PLATFORM_UNIX.

#ifdef _WIN32 // Should also cover _WIN64
#define REFKEEN_PLATFORM_WINDOWS
#endif

#ifdef __APPLE__
#include "TargetConditionals.h"
#if (!defined TARGET_OS_IPHONE) && (!defined TARGET_IPHONE_SIMULATOR)
#define REFKEEN_PLATFORM_OSX
#endif
#endif

#if (defined ANDROID) || (defined __ANDROID__)
#define REFKEEN_PLATFORM_ANDROID
#endif

#ifdef EMSCRIPTEN
#define REFKEEN_PLATFORM_EMSCRIPTEN
#endif

#if (defined __unix__) || (defined __unix) || (defined unix)
#define REFKEEN_PLATFORM_UNIX
#endif

#ifndef REFKEEN_PLATFORM_EMSCRIPTEN
#define REFKEEN_CONFIG_THREADS
#endif

#endif // REFKEEN_CONFIG_H
