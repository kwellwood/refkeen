/* Catacomb 3-D Source Code
 * Copyright (C) 1993-2014 Flat Rock Software
 * Copyright (C) 2014-2024 NY00123
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

// ID_VW_A.C
// PORTED FROM ASM

#include "id_heads.h"

REFKEEN_NS_B

// setting to 0 causes setscreen and waitvbl
// to skip waiting for VBL (for timing things)

// NOTE: Moved to id_vw.h
// #define WAITFORVBL 1

//============================================================================


id0_unsigned_t shiftdata0[] = {
	    0,    1,    2,    3,    4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
	   14,   15,   16,   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,   27,
	   28,   29,   30,   31,   32,   33,   34,   35,   36,   37,   38,   39,   40,   41,
	   42,   43,   44,   45,   46,   47,   48,   49,   50,   51,   52,   53,   54,   55,
	   56,   57,   58,   59,   60,   61,   62,   63,   64,   65,   66,   67,   68,   69,
	   70,   71,   72,   73,   74,   75,   76,   77,   78,   79,   80,   81,   82,   83,
	   84,   85,   86,   87,   88,   89,   90,   91,   92,   93,   94,   95,   96,   97,
	   98,   99,  100,  101,  102,  103,  104,  105,  106,  107,  108,  109,  110,  111,
	  112,  113,  114,  115,  116,  117,  118,  119,  120,  121,  122,  123,  124,  125,
	  126,  127,  128,  129,  130,  131,  132,  133,  134,  135,  136,  137,  138,  139,
	  140,  141,  142,  143,  144,  145,  146,  147,  148,  149,  150,  151,  152,  153,
	  154,  155,  156,  157,  158,  159,  160,  161,  162,  163,  164,  165,  166,  167,
	  168,  169,  170,  171,  172,  173,  174,  175,  176,  177,  178,  179,  180,  181,
	  182,  183,  184,  185,  186,  187,  188,  189,  190,  191,  192,  193,  194,  195,
	  196,  197,  198,  199,  200,  201,  202,  203,  204,  205,  206,  207,  208,  209,
	  210,  211,  212,  213,  214,  215,  216,  217,  218,  219,  220,  221,  222,  223,
	  224,  225,  226,  227,  228,  229,  230,  231,  232,  233,  234,  235,  236,  237,
	  238,  239,  240,  241,  242,  243,  244,  245,  246,  247,  248,  249,  250,  251,
	  252,  253,  254,  255
};

id0_unsigned_t shiftdata1[] = {
	    0,32768,    1,32769,    2,32770,    3,32771,    4,32772,    5,32773,    6,32774,
	    7,32775,    8,32776,    9,32777,   10,32778,   11,32779,   12,32780,   13,32781,
	   14,32782,   15,32783,   16,32784,   17,32785,   18,32786,   19,32787,   20,32788,
	   21,32789,   22,32790,   23,32791,   24,32792,   25,32793,   26,32794,   27,32795,
	   28,32796,   29,32797,   30,32798,   31,32799,   32,32800,   33,32801,   34,32802,
	   35,32803,   36,32804,   37,32805,   38,32806,   39,32807,   40,32808,   41,32809,
	   42,32810,   43,32811,   44,32812,   45,32813,   46,32814,   47,32815,   48,32816,
	   49,32817,   50,32818,   51,32819,   52,32820,   53,32821,   54,32822,   55,32823,
	   56,32824,   57,32825,   58,32826,   59,32827,   60,32828,   61,32829,   62,32830,
	   63,32831,   64,32832,   65,32833,   66,32834,   67,32835,   68,32836,   69,32837,
	   70,32838,   71,32839,   72,32840,   73,32841,   74,32842,   75,32843,   76,32844,
	   77,32845,   78,32846,   79,32847,   80,32848,   81,32849,   82,32850,   83,32851,
	   84,32852,   85,32853,   86,32854,   87,32855,   88,32856,   89,32857,   90,32858,
	   91,32859,   92,32860,   93,32861,   94,32862,   95,32863,   96,32864,   97,32865,
	   98,32866,   99,32867,  100,32868,  101,32869,  102,32870,  103,32871,  104,32872,
	  105,32873,  106,32874,  107,32875,  108,32876,  109,32877,  110,32878,  111,32879,
	  112,32880,  113,32881,  114,32882,  115,32883,  116,32884,  117,32885,  118,32886,
	  119,32887,  120,32888,  121,32889,  122,32890,  123,32891,  124,32892,  125,32893,
	  126,32894,  127,32895
};

id0_unsigned_t shiftdata2[] = {
	    0,16384,32768,49152,    1,16385,32769,49153,    2,16386,32770,49154,    3,16387,
	32771,49155,    4,16388,32772,49156,    5,16389,32773,49157,    6,16390,32774,49158,
	    7,16391,32775,49159,    8,16392,32776,49160,    9,16393,32777,49161,   10,16394,
	32778,49162,   11,16395,32779,49163,   12,16396,32780,49164,   13,16397,32781,49165,
	   14,16398,32782,49166,   15,16399,32783,49167,   16,16400,32784,49168,   17,16401,
	32785,49169,   18,16402,32786,49170,   19,16403,32787,49171,   20,16404,32788,49172,
	   21,16405,32789,49173,   22,16406,32790,49174,   23,16407,32791,49175,   24,16408,
	32792,49176,   25,16409,32793,49177,   26,16410,32794,49178,   27,16411,32795,49179,
	   28,16412,32796,49180,   29,16413,32797,49181,   30,16414,32798,49182,   31,16415,
	32799,49183,   32,16416,32800,49184,   33,16417,32801,49185,   34,16418,32802,49186,
	   35,16419,32803,49187,   36,16420,32804,49188,   37,16421,32805,49189,   38,16422,
	32806,49190,   39,16423,32807,49191,   40,16424,32808,49192,   41,16425,32809,49193,
	   42,16426,32810,49194,   43,16427,32811,49195,   44,16428,32812,49196,   45,16429,
	32813,49197,   46,16430,32814,49198,   47,16431,32815,49199,   48,16432,32816,49200,
	   49,16433,32817,49201,   50,16434,32818,49202,   51,16435,32819,49203,   52,16436,
	32820,49204,   53,16437,32821,49205,   54,16438,32822,49206,   55,16439,32823,49207,
	   56,16440,32824,49208,   57,16441,32825,49209,   58,16442,32826,49210,   59,16443,
	32827,49211,   60,16444,32828,49212,   61,16445,32829,49213,   62,16446,32830,49214,
	   63,16447,32831,49215
};

id0_unsigned_t shiftdata3[] = {
	    0, 8192,16384,24576,32768,40960,49152,57344,    1, 8193,16385,24577,32769,40961,
	49153,57345,    2, 8194,16386,24578,32770,40962,49154,57346,    3, 8195,16387,24579,
	32771,40963,49155,57347,    4, 8196,16388,24580,32772,40964,49156,57348,    5, 8197,
	16389,24581,32773,40965,49157,57349,    6, 8198,16390,24582,32774,40966,49158,57350,
	    7, 8199,16391,24583,32775,40967,49159,57351,    8, 8200,16392,24584,32776,40968,
	49160,57352,    9, 8201,16393,24585,32777,40969,49161,57353,   10, 8202,16394,24586,
	32778,40970,49162,57354,   11, 8203,16395,24587,32779,40971,49163,57355,   12, 8204,
	16396,24588,32780,40972,49164,57356,   13, 8205,16397,24589,32781,40973,49165,57357,
	   14, 8206,16398,24590,32782,40974,49166,57358,   15, 8207,16399,24591,32783,40975,
	49167,57359,   16, 8208,16400,24592,32784,40976,49168,57360,   17, 8209,16401,24593,
	32785,40977,49169,57361,   18, 8210,16402,24594,32786,40978,49170,57362,   19, 8211,
	16403,24595,32787,40979,49171,57363,   20, 8212,16404,24596,32788,40980,49172,57364,
	   21, 8213,16405,24597,32789,40981,49173,57365,   22, 8214,16406,24598,32790,40982,
	49174,57366,   23, 8215,16407,24599,32791,40983,49175,57367,   24, 8216,16408,24600,
	32792,40984,49176,57368,   25, 8217,16409,24601,32793,40985,49177,57369,   26, 8218,
	16410,24602,32794,40986,49178,57370,   27, 8219,16411,24603,32795,40987,49179,57371,
	   28, 8220,16412,24604,32796,40988,49180,57372,   29, 8221,16413,24605,32797,40989,
	49181,57373,   30, 8222,16414,24606,32798,40990,49182,57374,   31, 8223,16415,24607,
	32799,40991,49183,57375
};

id0_unsigned_t shiftdata4[] = {
	    0, 4096, 8192,12288,16384,20480,24576,28672,32768,36864,40960,45056,49152,53248,
	57344,61440,    1, 4097, 8193,12289,16385,20481,24577,28673,32769,36865,40961,45057,
	49153,53249,57345,61441,    2, 4098, 8194,12290,16386,20482,24578,28674,32770,36866,
	40962,45058,49154,53250,57346,61442,    3, 4099, 8195,12291,16387,20483,24579,28675,
	32771,36867,40963,45059,49155,53251,57347,61443,    4, 4100, 8196,12292,16388,20484,
	24580,28676,32772,36868,40964,45060,49156,53252,57348,61444,    5, 4101, 8197,12293,
	16389,20485,24581,28677,32773,36869,40965,45061,49157,53253,57349,61445,    6, 4102,
	 8198,12294,16390,20486,24582,28678,32774,36870,40966,45062,49158,53254,57350,61446,
	    7, 4103, 8199,12295,16391,20487,24583,28679,32775,36871,40967,45063,49159,53255,
	57351,61447,    8, 4104, 8200,12296,16392,20488,24584,28680,32776,36872,40968,45064,
	49160,53256,57352,61448,    9, 4105, 8201,12297,16393,20489,24585,28681,32777,36873,
	40969,45065,49161,53257,57353,61449,   10, 4106, 8202,12298,16394,20490,24586,28682,
	32778,36874,40970,45066,49162,53258,57354,61450,   11, 4107, 8203,12299,16395,20491,
	24587,28683,32779,36875,40971,45067,49163,53259,57355,61451,   12, 4108, 8204,12300,
	16396,20492,24588,28684,32780,36876,40972,45068,49164,53260,57356,61452,   13, 4109,
	 8205,12301,16397,20493,24589,28685,32781,36877,40973,45069,49165,53261,57357,61453,
	   14, 4110, 8206,12302,16398,20494,24590,28686,32782,36878,40974,45070,49166,53262,
	57358,61454,   15, 4111, 8207,12303,16399,20495,24591,28687,32783,36879,40975,45071,
	49167,53263,57359,61455
};

id0_unsigned_t shiftdata5[] = {
	    0, 2048, 4096, 6144, 8192,10240,12288,14336,16384,18432,20480,22528,24576,26624,
	28672,30720,32768,34816,36864,38912,40960,43008,45056,47104,49152,51200,53248,55296,
	57344,59392,61440,63488,    1, 2049, 4097, 6145, 8193,10241,12289,14337,16385,18433,
	20481,22529,24577,26625,28673,30721,32769,34817,36865,38913,40961,43009,45057,47105,
	49153,51201,53249,55297,57345,59393,61441,63489,    2, 2050, 4098, 6146, 8194,10242,
	12290,14338,16386,18434,20482,22530,24578,26626,28674,30722,32770,34818,36866,38914,
	40962,43010,45058,47106,49154,51202,53250,55298,57346,59394,61442,63490,    3, 2051,
	 4099, 6147, 8195,10243,12291,14339,16387,18435,20483,22531,24579,26627,28675,30723,
	32771,34819,36867,38915,40963,43011,45059,47107,49155,51203,53251,55299,57347,59395,
	61443,63491,    4, 2052, 4100, 6148, 8196,10244,12292,14340,16388,18436,20484,22532,
	24580,26628,28676,30724,32772,34820,36868,38916,40964,43012,45060,47108,49156,51204,
	53252,55300,57348,59396,61444,63492,    5, 2053, 4101, 6149, 8197,10245,12293,14341,
	16389,18437,20485,22533,24581,26629,28677,30725,32773,34821,36869,38917,40965,43013,
	45061,47109,49157,51205,53253,55301,57349,59397,61445,63493,    6, 2054, 4102, 6150,
	 8198,10246,12294,14342,16390,18438,20486,22534,24582,26630,28678,30726,32774,34822,
	36870,38918,40966,43014,45062,47110,49158,51206,53254,55302,57350,59398,61446,63494,
	    7, 2055, 4103, 6151, 8199,10247,12295,14343,16391,18439,20487,22535,24583,26631,
	28679,30727,32775,34823,36871,38919,40967,43015,45063,47111,49159,51207,53255,55303,
	57351,59399,61447,63495
};

id0_unsigned_t shiftdata6[] = {
	    0, 1024, 2048, 3072, 4096, 5120, 6144, 7168, 8192, 9216,10240,11264,12288,13312,
	14336,15360,16384,17408,18432,19456,20480,21504,22528,23552,24576,25600,26624,27648,
	28672,29696,30720,31744,32768,33792,34816,35840,36864,37888,38912,39936,40960,41984,
	43008,44032,45056,46080,47104,48128,49152,50176,51200,52224,53248,54272,55296,56320,
	57344,58368,59392,60416,61440,62464,63488,64512,    1, 1025, 2049, 3073, 4097, 5121,
	 6145, 7169, 8193, 9217,10241,11265,12289,13313,14337,15361,16385,17409,18433,19457,
	20481,21505,22529,23553,24577,25601,26625,27649,28673,29697,30721,31745,32769,33793,
	34817,35841,36865,37889,38913,39937,40961,41985,43009,44033,45057,46081,47105,48129,
	49153,50177,51201,52225,53249,54273,55297,56321,57345,58369,59393,60417,61441,62465,
	63489,64513,    2, 1026, 2050, 3074, 4098, 5122, 6146, 7170, 8194, 9218,10242,11266,
	12290,13314,14338,15362,16386,17410,18434,19458,20482,21506,22530,23554,24578,25602,
	26626,27650,28674,29698,30722,31746,32770,33794,34818,35842,36866,37890,38914,39938,
	40962,41986,43010,44034,45058,46082,47106,48130,49154,50178,51202,52226,53250,54274,
	55298,56322,57346,58370,59394,60418,61442,62466,63490,64514,    3, 1027, 2051, 3075,
	 4099, 5123, 6147, 7171, 8195, 9219,10243,11267,12291,13315,14339,15363,16387,17411,
	18435,19459,20483,21507,22531,23555,24579,25603,26627,27651,28675,29699,30723,31747,
	32771,33795,34819,35843,36867,37891,38915,39939,40963,41987,43011,44035,45059,46083,
	47107,48131,49155,50179,51203,52227,53251,54275,55299,56323,57347,58371,59395,60419,
	61443,62467,63491,64515
};

id0_unsigned_t shiftdata7[] = {
	    0,  512, 1024, 1536, 2048, 2560, 3072, 3584, 4096, 4608, 5120, 5632, 6144, 6656,
	 7168, 7680, 8192, 8704, 9216, 9728,10240,10752,11264,11776,12288,12800,13312,13824,
	14336,14848,15360,15872,16384,16896,17408,17920,18432,18944,19456,19968,20480,20992,
	21504,22016,22528,23040,23552,24064,24576,25088,25600,26112,26624,27136,27648,28160,
	28672,29184,29696,30208,30720,31232,31744,32256,32768,33280,33792,34304,34816,35328,
	35840,36352,36864,37376,37888,38400,38912,39424,39936,40448,40960,41472,41984,42496,
	43008,43520,44032,44544,45056,45568,46080,46592,47104,47616,48128,48640,49152,49664,
	50176,50688,51200,51712,52224,52736,53248,53760,54272,54784,55296,55808,56320,56832,
	57344,57856,58368,58880,59392,59904,60416,60928,61440,61952,62464,62976,63488,64000,
	64512,65024,    1,  513, 1025, 1537, 2049, 2561, 3073, 3585, 4097, 4609, 5121, 5633,
	 6145, 6657, 7169, 7681, 8193, 8705, 9217, 9729,10241,10753,11265,11777,12289,12801,
	13313,13825,14337,14849,15361,15873,16385,16897,17409,17921,18433,18945,19457,19969,
	20481,20993,21505,22017,22529,23041,23553,24065,24577,25089,25601,26113,26625,27137,
	27649,28161,28673,29185,29697,30209,30721,31233,31745,32257,32769,33281,33793,34305,
	34817,35329,35841,36353,36865,37377,37889,38401,38913,39425,39937,40449,40961,41473,
	41985,42497,43009,43521,44033,44545,45057,45569,46081,46593,47105,47617,48129,48641,
	49153,49665,50177,50689,51201,51713,52225,52737,53249,53761,54273,54785,55297,55809,
	56321,56833,57345,57857,58369,58881,59393,59905,60417,60929,61441,61953,62465,62977,
	63489,64001,64513,65025
};

id0_unsigned_t *shifttabletable[8] = {
	shiftdata0,shiftdata1,shiftdata2,shiftdata3,
	shiftdata4,shiftdata5,shiftdata6,shiftdata7
};

id0_unsigned_t linedelta;

//============================================================================


//IFE GRMODE-CGAGR
//INCLUDE	"ID_VW_AC.ASM"
//ENDIF

//IFE GRMODE-EGAGR
//INCLUDE	"ID_VW_AE.ASM"
//ENDIF

//IFE GRMODE-VGAGR
//INCLUDE	"ID_VW_AV.ASM"
//ENDIF

//============================================================================
//
//                           MISC VIDEO ROUTINES
//
//============================================================================

//========
//
// VW_WaitVBL (id0_int_t number)
//
//========

// NOTE: Moved to id_vw.h as an inline implementation calling backend function

#if 0
void VW_WaitVBL(id0_int_t number)
{
if WAITFORVBL				; skip wait if profiling

	mov	dx,STATUS_REGISTER_1

	mov	cx,[number]

waitvbl1:
	in	al,dx
	test	al,00001000b	;look for vbl
	jnz	waitvbl1

waitvbl2:
	in	al,dx
	test	al,00001000b	;look for vbl
	jz	waitvbl2

	loop	waitvbl1

endif
}
#endif

//===========================================================================


//=========================================================
//
// Name:	VW_VideoID
//
// Function:	Detects the presence of various video subsystems
//
// id0_int_t VideoID;
//
// Subsystem ID values:
// 	 0  = (none)
// 	 1  = MDA
// 	 2  = CGA
// 	 3  = EGA
// 	 4  = MCGA
// 	 5  = VGA
// 	80h = HGC
// 	81h = HGC+
// 	82h = Hercules InColor
//
//=========================================================

cardtype VW_VideoID (void)
{
	return VGAcard;
}

REFKEEN_NS_E
