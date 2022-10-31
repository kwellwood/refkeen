/* Wolfenstein 3D Source Code
 * Copyright (C) 1993-1996 id Software, Inc.
 *
 * This file is part of Wolfenstein 3D.
 *
 * Wolfenstein 3D is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * Wolfenstein 3D is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * As an addendum, you can further use the Wolfenstein 3D Source Code under
 * the terms of the limited use software license agreement for Wolfenstein 3D.
 * See id-wolf3d.txt for these terms.
 */

// New file used for preparing and converting pointers to states

#include "wl_def.h"

#ifdef REFKEEN_VER_WL1AP14
REFKEEN_NS_B

// List of all states
extern statetype s_player;
extern statetype s_attack;
extern statetype s_rocket;
extern statetype s_smoke1;
extern statetype s_smoke2;
extern statetype s_smoke3;
extern statetype s_smoke4;
extern statetype s_boom1;
extern statetype s_boom2;
extern statetype s_boom3;
extern statetype s_grdstand;
extern statetype s_grdpath1;
extern statetype s_grdpath1s;
extern statetype s_grdpath2;
extern statetype s_grdpath3;
extern statetype s_grdpath3s;
extern statetype s_grdpath4;
extern statetype s_grdpain;
extern statetype s_grdpain1;
extern statetype s_grdshoot1;
extern statetype s_grdshoot2;
extern statetype s_grdshoot3;
extern statetype s_grdchase1;
extern statetype s_grdchase1s;
extern statetype s_grdchase2;
extern statetype s_grdchase3;
extern statetype s_grdchase3s;
extern statetype s_grdchase4;
extern statetype s_grddie1;
extern statetype s_grddie2;
extern statetype s_grddie3;
extern statetype s_grddie4;
extern statetype s_blinkychase1;
extern statetype s_blinkychase2;
extern statetype s_inkychase1;
extern statetype s_inkychase2;
extern statetype s_pinkychase1;
extern statetype s_pinkychase2;
extern statetype s_clydechase1;
extern statetype s_clydechase2;
extern statetype s_dogpath1;
extern statetype s_dogpath1s;
extern statetype s_dogpath2;
extern statetype s_dogpath3;
extern statetype s_dogpath3s;
extern statetype s_dogpath4;
extern statetype s_dogjump1;
extern statetype s_dogjump2;
extern statetype s_dogjump3;
extern statetype s_dogjump4;
extern statetype s_dogjump5;
extern statetype s_dogchase1;
extern statetype s_dogchase1s;
extern statetype s_dogchase2;
extern statetype s_dogchase3;
extern statetype s_dogchase3s;
extern statetype s_dogchase4;
extern statetype s_dogdie1;
extern statetype s_dogdie2;
extern statetype s_dogdie3;
extern statetype s_dogdead;
extern statetype s_ofcstand;
extern statetype s_ofcpath1;
extern statetype s_ofcpath1s;
extern statetype s_ofcpath2;
extern statetype s_ofcpath3;
extern statetype s_ofcpath3s;
extern statetype s_ofcpath4;
extern statetype s_ofcpain;
extern statetype s_ofcpain1;
extern statetype s_ofcshoot1;
extern statetype s_ofcshoot2;
extern statetype s_ofcshoot3;
extern statetype s_ofcchase1;
extern statetype s_ofcchase1s;
extern statetype s_ofcchase2;
extern statetype s_ofcchase3;
extern statetype s_ofcchase3s;
extern statetype s_ofcchase4;
extern statetype s_ofcdie1;
extern statetype s_ofcdie2;
extern statetype s_ofcdie3;
extern statetype s_ofcdie4;
extern statetype s_ofcdie5;
extern statetype s_mutstand;
extern statetype s_mutpath1;
extern statetype s_mutpath1s;
extern statetype s_mutpath2;
extern statetype s_mutpath3;
extern statetype s_mutpath3s;
extern statetype s_mutpath4;
extern statetype s_mutpain;
extern statetype s_mutpain1;
extern statetype s_mutshoot1;
extern statetype s_mutshoot2;
extern statetype s_mutshoot3;
extern statetype s_mutshoot4;
extern statetype s_mutchase1;
extern statetype s_mutchase1s;
extern statetype s_mutchase2;
extern statetype s_mutchase3;
extern statetype s_mutchase3s;
extern statetype s_mutchase4;
extern statetype s_mutdie1;
extern statetype s_mutdie2;
extern statetype s_mutdie3;
extern statetype s_mutdie4;
extern statetype s_mutdie5;
extern statetype s_ssstand;
extern statetype s_sspath1;
extern statetype s_sspath1s;
extern statetype s_sspath2;
extern statetype s_sspath3;
extern statetype s_sspath3s;
extern statetype s_sspath4;
extern statetype s_sspain;
extern statetype s_sspain1;
extern statetype s_ssshoot1;
extern statetype s_ssshoot2;
extern statetype s_ssshoot3;
extern statetype s_ssshoot4;
extern statetype s_ssshoot5;
extern statetype s_ssshoot6;
extern statetype s_ssshoot7;
extern statetype s_ssshoot8;
extern statetype s_ssshoot9;
extern statetype s_sschase1;
extern statetype s_sschase1s;
extern statetype s_sschase2;
extern statetype s_sschase3;
extern statetype s_sschase3s;
extern statetype s_sschase4;
extern statetype s_ssdie1;
extern statetype s_ssdie2;
extern statetype s_ssdie3;
extern statetype s_ssdie4;
extern statetype s_bossstand;
extern statetype s_bosschase1;
extern statetype s_bosschase1s;
extern statetype s_bosschase2;
extern statetype s_bosschase3;
extern statetype s_bosschase3s;
extern statetype s_bosschase4;
extern statetype s_bossdie1;
extern statetype s_bossdie2;
extern statetype s_bossdie3;
extern statetype s_bossdie4;
extern statetype s_bossshoot1;
extern statetype s_bossshoot2;
extern statetype s_bossshoot3;
extern statetype s_bossshoot4;
extern statetype s_bossshoot5;
extern statetype s_bossshoot6;
extern statetype s_bossshoot7;
extern statetype s_bossshoot8;
extern statetype s_gretelstand;
extern statetype s_gretelchase1;
extern statetype s_gretelchase1s;
extern statetype s_gretelchase2;
extern statetype s_gretelchase3;
extern statetype s_gretelchase3s;
extern statetype s_gretelchase4;
extern statetype s_greteldie1;
extern statetype s_greteldie2;
extern statetype s_greteldie3;
extern statetype s_greteldie4;
extern statetype s_gretelshoot1;
extern statetype s_gretelshoot2;
extern statetype s_gretelshoot3;
extern statetype s_gretelshoot4;
extern statetype s_gretelshoot5;
extern statetype s_gretelshoot6;
extern statetype s_gretelshoot7;
extern statetype s_gretelshoot8;
extern statetype s_schabbstand;
extern statetype s_schabbchase1;
extern statetype s_schabbchase1s;
extern statetype s_schabbchase2;
extern statetype s_schabbchase3;
extern statetype s_schabbchase3s;
extern statetype s_schabbchase4;
extern statetype s_schabbdeathcam;
extern statetype s_schabbdie1;
extern statetype s_schabbdie2;
extern statetype s_schabbdie3;
extern statetype s_schabbdie4;
extern statetype s_schabbdie5;
extern statetype s_schabbdie6;
extern statetype s_schabbshoot1;
extern statetype s_schabbshoot2;
extern statetype s_needle1;
extern statetype s_needle2;
extern statetype s_needle3;
extern statetype s_needle4;
extern statetype s_giftstand;
extern statetype s_giftchase1;
extern statetype s_giftchase1s;
extern statetype s_giftchase2;
extern statetype s_giftchase3;
extern statetype s_giftchase3s;
extern statetype s_giftchase4;
extern statetype s_giftdeathcam;
extern statetype s_giftdie1;
extern statetype s_giftdie2;
extern statetype s_giftdie3;
extern statetype s_giftdie4;
extern statetype s_giftdie5;
extern statetype s_giftdie6;
extern statetype s_giftshoot1;
extern statetype s_giftshoot2;
extern statetype s_fatstand;
extern statetype s_fatchase1;
extern statetype s_fatchase1s;
extern statetype s_fatchase2;
extern statetype s_fatchase3;
extern statetype s_fatchase3s;
extern statetype s_fatchase4;
extern statetype s_fatdeathcam;
extern statetype s_fatdie1;
extern statetype s_fatdie2;
extern statetype s_fatdie3;
extern statetype s_fatdie4;
extern statetype s_fatdie5;
extern statetype s_fatdie6;
extern statetype s_fatshoot1;
extern statetype s_fatshoot2;
extern statetype s_fatshoot3;
extern statetype s_fatshoot4;
extern statetype s_fatshoot5;
extern statetype s_fatshoot6;
extern statetype s_fakestand;
extern statetype s_fakechase1;
extern statetype s_fakechase1s;
extern statetype s_fakechase2;
extern statetype s_fakechase3;
extern statetype s_fakechase3s;
extern statetype s_fakechase4;
extern statetype s_fakedie1;
extern statetype s_fakedie2;
extern statetype s_fakedie3;
extern statetype s_fakedie4;
extern statetype s_fakedie5;
extern statetype s_fakedie6;
extern statetype s_fakeshoot1;
extern statetype s_fakeshoot2;
extern statetype s_fakeshoot3;
extern statetype s_fakeshoot4;
extern statetype s_fakeshoot5;
extern statetype s_fakeshoot6;
extern statetype s_fakeshoot7;
extern statetype s_fakeshoot8;
extern statetype s_fakeshoot9;
extern statetype s_fire1;
extern statetype s_fire2;
extern statetype s_mechastand;
extern statetype s_mechachase1;
extern statetype s_mechachase1s;
extern statetype s_mechachase2;
extern statetype s_mechachase3;
extern statetype s_mechachase3s;
extern statetype s_mechachase4;
extern statetype s_mechadie1;
extern statetype s_mechadie2;
extern statetype s_mechadie3;
extern statetype s_mechadie4;
extern statetype s_mechashoot1;
extern statetype s_mechashoot2;
extern statetype s_mechashoot3;
extern statetype s_mechashoot4;
extern statetype s_mechashoot5;
extern statetype s_mechashoot6;
extern statetype s_hitlerchase1;
extern statetype s_hitlerchase1s;
extern statetype s_hitlerchase2;
extern statetype s_hitlerchase3;
extern statetype s_hitlerchase3s;
extern statetype s_hitlerchase4;
extern statetype s_hitlerdeathcam;
extern statetype s_hitlerdie1;
extern statetype s_hitlerdie2;
extern statetype s_hitlerdie3;
extern statetype s_hitlerdie4;
extern statetype s_hitlerdie5;
extern statetype s_hitlerdie6;
extern statetype s_hitlerdie7;
extern statetype s_hitlerdie8;
extern statetype s_hitlerdie9;
extern statetype s_hitlerdie10;
extern statetype s_hitlershoot1;
extern statetype s_hitlershoot2;
extern statetype s_hitlershoot3;
extern statetype s_hitlershoot4;
extern statetype s_hitlershoot5;
extern statetype s_hitlershoot6;
extern statetype s_bjrun1;
extern statetype s_bjrun1s;
extern statetype s_bjrun2;
extern statetype s_bjrun3;
extern statetype s_bjrun3s;
extern statetype s_bjrun4;
extern statetype s_bjjump1;
extern statetype s_bjjump2;
extern statetype s_bjjump3;
extern statetype s_bjjump4;
extern statetype s_deathcam;

void RefKeen_FillObjStatesWithDOSPointers_WL1(void)
{
	s_player.compatdospointer = 0x181C;
	s_attack.compatdospointer = 0x182C;
	s_rocket.compatdospointer = 0x1B0A;
	s_smoke1.compatdospointer = 0x1B1A;
	s_smoke2.compatdospointer = 0x1B2A;
	s_smoke3.compatdospointer = 0x1B3A;
	s_smoke4.compatdospointer = 0x1B4A;
	s_boom1.compatdospointer = 0x1B5A;
	s_boom2.compatdospointer = 0x1B6A;
	s_boom3.compatdospointer = 0x1B7A;
	s_grdstand.compatdospointer = 0x1B8A;
	s_grdpath1.compatdospointer = 0x1B9A;
	s_grdpath1s.compatdospointer = 0x1BAA;
	s_grdpath2.compatdospointer = 0x1BBA;
	s_grdpath3.compatdospointer = 0x1BCA;
	s_grdpath3s.compatdospointer = 0x1BDA;
	s_grdpath4.compatdospointer = 0x1BEA;
	s_grdpain.compatdospointer = 0x1BFA;
	s_grdpain1.compatdospointer = 0x1C0A;
	s_grdshoot1.compatdospointer = 0x1C1A;
	s_grdshoot2.compatdospointer = 0x1C2A;
	s_grdshoot3.compatdospointer = 0x1C3A;
	s_grdchase1.compatdospointer = 0x1C4A;
	s_grdchase1s.compatdospointer = 0x1C5A;
	s_grdchase2.compatdospointer = 0x1C6A;
	s_grdchase3.compatdospointer = 0x1C7A;
	s_grdchase3s.compatdospointer = 0x1C8A;
	s_grdchase4.compatdospointer = 0x1C9A;
	s_grddie1.compatdospointer = 0x1CAA;
	s_grddie2.compatdospointer = 0x1CBA;
	s_grddie3.compatdospointer = 0x1CCA;
	s_grddie4.compatdospointer = 0x1CDA;
	s_blinkychase1.compatdospointer = 0x1CEA;
	s_blinkychase2.compatdospointer = 0x1CFA;
	s_inkychase1.compatdospointer = 0x1D0A;
	s_inkychase2.compatdospointer = 0x1D1A;
	s_pinkychase1.compatdospointer = 0x1D2A;
	s_pinkychase2.compatdospointer = 0x1D3A;
	s_clydechase1.compatdospointer = 0x1D4A;
	s_clydechase2.compatdospointer = 0x1D5A;
	s_dogpath1.compatdospointer = 0x1D6A;
	s_dogpath1s.compatdospointer = 0x1D7A;
	s_dogpath2.compatdospointer = 0x1D8A;
	s_dogpath3.compatdospointer = 0x1D9A;
	s_dogpath3s.compatdospointer = 0x1DAA;
	s_dogpath4.compatdospointer = 0x1DBA;
	s_dogjump1.compatdospointer = 0x1DCA;
	s_dogjump2.compatdospointer = 0x1DDA;
	s_dogjump3.compatdospointer = 0x1DEA;
	s_dogjump4.compatdospointer = 0x1DFA;
	s_dogjump5.compatdospointer = 0x1E0A;
	s_dogchase1.compatdospointer = 0x1E1A;
	s_dogchase1s.compatdospointer = 0x1E2A;
	s_dogchase2.compatdospointer = 0x1E3A;
	s_dogchase3.compatdospointer = 0x1E4A;
	s_dogchase3s.compatdospointer = 0x1E5A;
	s_dogchase4.compatdospointer = 0x1E6A;
	s_dogdie1.compatdospointer = 0x1E7A;
	s_dogdie2.compatdospointer = 0x1E8A;
	s_dogdie3.compatdospointer = 0x1E9A;
	s_dogdead.compatdospointer = 0x1EAA;
	s_ofcstand.compatdospointer = 0x1EBA;
	s_ofcpath1.compatdospointer = 0x1ECA;
	s_ofcpath1s.compatdospointer = 0x1EDA;
	s_ofcpath2.compatdospointer = 0x1EEA;
	s_ofcpath3.compatdospointer = 0x1EFA;
	s_ofcpath3s.compatdospointer = 0x1F0A;
	s_ofcpath4.compatdospointer = 0x1F1A;
	s_ofcpain.compatdospointer = 0x1F2A;
	s_ofcpain1.compatdospointer = 0x1F3A;
	s_ofcshoot1.compatdospointer = 0x1F4A;
	s_ofcshoot2.compatdospointer = 0x1F5A;
	s_ofcshoot3.compatdospointer = 0x1F6A;
	s_ofcchase1.compatdospointer = 0x1F7A;
	s_ofcchase1s.compatdospointer = 0x1F8A;
	s_ofcchase2.compatdospointer = 0x1F9A;
	s_ofcchase3.compatdospointer = 0x1FAA;
	s_ofcchase3s.compatdospointer = 0x1FBA;
	s_ofcchase4.compatdospointer = 0x1FCA;
	s_ofcdie1.compatdospointer = 0x1FDA;
	s_ofcdie2.compatdospointer = 0x1FEA;
	s_ofcdie3.compatdospointer = 0x1FFA;
	s_ofcdie4.compatdospointer = 0x200A;
	s_ofcdie5.compatdospointer = 0x201A;
	s_mutstand.compatdospointer = 0x202A;
	s_mutpath1.compatdospointer = 0x203A;
	s_mutpath1s.compatdospointer = 0x204A;
	s_mutpath2.compatdospointer = 0x205A;
	s_mutpath3.compatdospointer = 0x206A;
	s_mutpath3s.compatdospointer = 0x207A;
	s_mutpath4.compatdospointer = 0x208A;
	s_mutpain.compatdospointer = 0x209A;
	s_mutpain1.compatdospointer = 0x20AA;
	s_mutshoot1.compatdospointer = 0x20BA;
	s_mutshoot2.compatdospointer = 0x20CA;
	s_mutshoot3.compatdospointer = 0x20DA;
	s_mutshoot4.compatdospointer = 0x20EA;
	s_mutchase1.compatdospointer = 0x20FA;
	s_mutchase1s.compatdospointer = 0x210A;
	s_mutchase2.compatdospointer = 0x211A;
	s_mutchase3.compatdospointer = 0x212A;
	s_mutchase3s.compatdospointer = 0x213A;
	s_mutchase4.compatdospointer = 0x214A;
	s_mutdie1.compatdospointer = 0x215A;
	s_mutdie2.compatdospointer = 0x216A;
	s_mutdie3.compatdospointer = 0x217A;
	s_mutdie4.compatdospointer = 0x218A;
	s_mutdie5.compatdospointer = 0x219A;
	s_ssstand.compatdospointer = 0x21AA;
	s_sspath1.compatdospointer = 0x21BA;
	s_sspath1s.compatdospointer = 0x21CA;
	s_sspath2.compatdospointer = 0x21DA;
	s_sspath3.compatdospointer = 0x21EA;
	s_sspath3s.compatdospointer = 0x21FA;
	s_sspath4.compatdospointer = 0x220A;
	s_sspain.compatdospointer = 0x221A;
	s_sspain1.compatdospointer = 0x222A;
	s_ssshoot1.compatdospointer = 0x223A;
	s_ssshoot2.compatdospointer = 0x224A;
	s_ssshoot3.compatdospointer = 0x225A;
	s_ssshoot4.compatdospointer = 0x226A;
	s_ssshoot5.compatdospointer = 0x227A;
	s_ssshoot6.compatdospointer = 0x228A;
	s_ssshoot7.compatdospointer = 0x229A;
	s_ssshoot8.compatdospointer = 0x22AA;
	s_ssshoot9.compatdospointer = 0x22BA;
	s_sschase1.compatdospointer = 0x22CA;
	s_sschase1s.compatdospointer = 0x22DA;
	s_sschase2.compatdospointer = 0x22EA;
	s_sschase3.compatdospointer = 0x22FA;
	s_sschase3s.compatdospointer = 0x230A;
	s_sschase4.compatdospointer = 0x231A;
	s_ssdie1.compatdospointer = 0x232A;
	s_ssdie2.compatdospointer = 0x233A;
	s_ssdie3.compatdospointer = 0x234A;
	s_ssdie4.compatdospointer = 0x235A;
	s_bossstand.compatdospointer = 0x236A;
	s_bosschase1.compatdospointer = 0x237A;
	s_bosschase1s.compatdospointer = 0x238A;
	s_bosschase2.compatdospointer = 0x239A;
	s_bosschase3.compatdospointer = 0x23AA;
	s_bosschase3s.compatdospointer = 0x23BA;
	s_bosschase4.compatdospointer = 0x23CA;
	s_bossdie1.compatdospointer = 0x23DA;
	s_bossdie2.compatdospointer = 0x23EA;
	s_bossdie3.compatdospointer = 0x23FA;
	s_bossdie4.compatdospointer = 0x240A;
	s_bossshoot1.compatdospointer = 0x241A;
	s_bossshoot2.compatdospointer = 0x242A;
	s_bossshoot3.compatdospointer = 0x243A;
	s_bossshoot4.compatdospointer = 0x244A;
	s_bossshoot5.compatdospointer = 0x245A;
	s_bossshoot6.compatdospointer = 0x246A;
	s_bossshoot7.compatdospointer = 0x247A;
	s_bossshoot8.compatdospointer = 0x248A;
	s_gretelstand.compatdospointer = 0x249A;
	s_gretelchase1.compatdospointer = 0x24AA;
	s_gretelchase1s.compatdospointer = 0x24BA;
	s_gretelchase2.compatdospointer = 0x24CA;
	s_gretelchase3.compatdospointer = 0x24DA;
	s_gretelchase3s.compatdospointer = 0x24EA;
	s_gretelchase4.compatdospointer = 0x24FA;
	s_greteldie1.compatdospointer = 0x250A;
	s_greteldie2.compatdospointer = 0x251A;
	s_greteldie3.compatdospointer = 0x252A;
	s_greteldie4.compatdospointer = 0x253A;
	s_gretelshoot1.compatdospointer = 0x254A;
	s_gretelshoot2.compatdospointer = 0x255A;
	s_gretelshoot3.compatdospointer = 0x256A;
	s_gretelshoot4.compatdospointer = 0x257A;
	s_gretelshoot5.compatdospointer = 0x258A;
	s_gretelshoot6.compatdospointer = 0x259A;
	s_gretelshoot7.compatdospointer = 0x25AA;
	s_gretelshoot8.compatdospointer = 0x25BA;
	s_schabbstand.compatdospointer = 0x25DC;
	s_schabbchase1.compatdospointer = 0x25EC;
	s_schabbchase1s.compatdospointer = 0x25FC;
	s_schabbchase2.compatdospointer = 0x260C;
	s_schabbchase3.compatdospointer = 0x261C;
	s_schabbchase3s.compatdospointer = 0x262C;
	s_schabbchase4.compatdospointer = 0x263C;
	s_schabbdeathcam.compatdospointer = 0x264C;
	s_schabbdie1.compatdospointer = 0x265C;
	s_schabbdie2.compatdospointer = 0x266C;
	s_schabbdie3.compatdospointer = 0x267C;
	s_schabbdie4.compatdospointer = 0x268C;
	s_schabbdie5.compatdospointer = 0x269C;
	s_schabbdie6.compatdospointer = 0x26AC;
	s_schabbshoot1.compatdospointer = 0x26BC;
	s_schabbshoot2.compatdospointer = 0x26CC;
	s_needle1.compatdospointer = 0x26DC;
	s_needle2.compatdospointer = 0x26EC;
	s_needle3.compatdospointer = 0x26FC;
	s_needle4.compatdospointer = 0x270C;
	s_giftstand.compatdospointer = 0x271C;
	s_giftchase1.compatdospointer = 0x272C;
	s_giftchase1s.compatdospointer = 0x273C;
	s_giftchase2.compatdospointer = 0x274C;
	s_giftchase3.compatdospointer = 0x275C;
	s_giftchase3s.compatdospointer = 0x276C;
	s_giftchase4.compatdospointer = 0x277C;
	s_giftdeathcam.compatdospointer = 0x278C;
	s_giftdie1.compatdospointer = 0x279C;
	s_giftdie2.compatdospointer = 0x27AC;
	s_giftdie3.compatdospointer = 0x27BC;
	s_giftdie4.compatdospointer = 0x27CC;
	s_giftdie5.compatdospointer = 0x27DC;
	s_giftdie6.compatdospointer = 0x27EC;
	s_giftshoot1.compatdospointer = 0x27FC;
	s_giftshoot2.compatdospointer = 0x280C;
	s_fatstand.compatdospointer = 0x281C;
	s_fatchase1.compatdospointer = 0x282C;
	s_fatchase1s.compatdospointer = 0x283C;
	s_fatchase2.compatdospointer = 0x284C;
	s_fatchase3.compatdospointer = 0x285C;
	s_fatchase3s.compatdospointer = 0x286C;
	s_fatchase4.compatdospointer = 0x287C;
	s_fatdeathcam.compatdospointer = 0x288C;
	s_fatdie1.compatdospointer = 0x289C;
	s_fatdie2.compatdospointer = 0x28AC;
	s_fatdie3.compatdospointer = 0x28BC;
	s_fatdie4.compatdospointer = 0x28CC;
	s_fatdie5.compatdospointer = 0x28DC;
	s_fatdie6.compatdospointer = 0x28EC;
	s_fatshoot1.compatdospointer = 0x28FC;
	s_fatshoot2.compatdospointer = 0x290C;
	s_fatshoot3.compatdospointer = 0x291C;
	s_fatshoot4.compatdospointer = 0x292C;
	s_fatshoot5.compatdospointer = 0x293C;
	s_fatshoot6.compatdospointer = 0x294C;
	s_fakestand.compatdospointer = 0x295C;
	s_fakechase1.compatdospointer = 0x296C;
	s_fakechase1s.compatdospointer = 0x297C;
	s_fakechase2.compatdospointer = 0x298C;
	s_fakechase3.compatdospointer = 0x299C;
	s_fakechase3s.compatdospointer = 0x29AC;
	s_fakechase4.compatdospointer = 0x29BC;
	s_fakedie1.compatdospointer = 0x29CC;
	s_fakedie2.compatdospointer = 0x29DC;
	s_fakedie3.compatdospointer = 0x29EC;
	s_fakedie4.compatdospointer = 0x29FC;
	s_fakedie5.compatdospointer = 0x2A0C;
	s_fakedie6.compatdospointer = 0x2A1C;
	s_fakeshoot1.compatdospointer = 0x2A2C;
	s_fakeshoot2.compatdospointer = 0x2A3C;
	s_fakeshoot3.compatdospointer = 0x2A4C;
	s_fakeshoot4.compatdospointer = 0x2A5C;
	s_fakeshoot5.compatdospointer = 0x2A6C;
	s_fakeshoot6.compatdospointer = 0x2A7C;
	s_fakeshoot7.compatdospointer = 0x2A8C;
	s_fakeshoot8.compatdospointer = 0x2A9C;
	s_fakeshoot9.compatdospointer = 0x2AAC;
	s_fire1.compatdospointer = 0x2ABC;
	s_fire2.compatdospointer = 0x2ACC;
	s_mechastand.compatdospointer = 0x2ADC;
	s_mechachase1.compatdospointer = 0x2AEC;
	s_mechachase1s.compatdospointer = 0x2AFC;
	s_mechachase2.compatdospointer = 0x2B0C;
	s_mechachase3.compatdospointer = 0x2B1C;
	s_mechachase3s.compatdospointer = 0x2B2C;
	s_mechachase4.compatdospointer = 0x2B3C;
	s_mechadie1.compatdospointer = 0x2B4C;
	s_mechadie2.compatdospointer = 0x2B5C;
	s_mechadie3.compatdospointer = 0x2B6C;
	s_mechadie4.compatdospointer = 0x2B7C;
	s_mechashoot1.compatdospointer = 0x2B8C;
	s_mechashoot2.compatdospointer = 0x2B9C;
	s_mechashoot3.compatdospointer = 0x2BAC;
	s_mechashoot4.compatdospointer = 0x2BBC;
	s_mechashoot5.compatdospointer = 0x2BCC;
	s_mechashoot6.compatdospointer = 0x2BDC;
	s_hitlerchase1.compatdospointer = 0x2BEC;
	s_hitlerchase1s.compatdospointer = 0x2BFC;
	s_hitlerchase2.compatdospointer = 0x2C0C;
	s_hitlerchase3.compatdospointer = 0x2C1C;
	s_hitlerchase3s.compatdospointer = 0x2C2C;
	s_hitlerchase4.compatdospointer = 0x2C3C;
	s_hitlerdeathcam.compatdospointer = 0x2C4C;
	s_hitlerdie1.compatdospointer = 0x2C5C;
	s_hitlerdie2.compatdospointer = 0x2C6C;
	s_hitlerdie3.compatdospointer = 0x2C7C;
	s_hitlerdie4.compatdospointer = 0x2C8C;
	s_hitlerdie5.compatdospointer = 0x2C9C;
	s_hitlerdie6.compatdospointer = 0x2CAC;
	s_hitlerdie7.compatdospointer = 0x2CBC;
	s_hitlerdie8.compatdospointer = 0x2CCC;
	s_hitlerdie9.compatdospointer = 0x2CDC;
	s_hitlerdie10.compatdospointer = 0x2CEC;
	s_hitlershoot1.compatdospointer = 0x2CFC;
	s_hitlershoot2.compatdospointer = 0x2D0C;
	s_hitlershoot3.compatdospointer = 0x2D1C;
	s_hitlershoot4.compatdospointer = 0x2D2C;
	s_hitlershoot5.compatdospointer = 0x2D3C;
	s_hitlershoot6.compatdospointer = 0x2D4C;
	s_bjrun1.compatdospointer = 0x2D64;
	s_bjrun1s.compatdospointer = 0x2D74;
	s_bjrun2.compatdospointer = 0x2D84;
	s_bjrun3.compatdospointer = 0x2D94;
	s_bjrun3s.compatdospointer = 0x2DA4;
	s_bjrun4.compatdospointer = 0x2DB4;
	s_bjjump1.compatdospointer = 0x2DC4;
	s_bjjump2.compatdospointer = 0x2DD4;
	s_bjjump3.compatdospointer = 0x2DE4;
	s_bjjump4.compatdospointer = 0x2DF4;
	s_deathcam.compatdospointer = 0x2E04;
}

statetype *RefKeen_GetObjStatePtrFromDOSPointer_WL1(uint_fast32_t dosptr)
{
	switch (dosptr)
	{
	case 0x181C: return &s_player;
	case 0x182C: return &s_attack;
	case 0x1B0A: return &s_rocket;
	case 0x1B1A: return &s_smoke1;
	case 0x1B2A: return &s_smoke2;
	case 0x1B3A: return &s_smoke3;
	case 0x1B4A: return &s_smoke4;
	case 0x1B5A: return &s_boom1;
	case 0x1B6A: return &s_boom2;
	case 0x1B7A: return &s_boom3;
	case 0x1B8A: return &s_grdstand;
	case 0x1B9A: return &s_grdpath1;
	case 0x1BAA: return &s_grdpath1s;
	case 0x1BBA: return &s_grdpath2;
	case 0x1BCA: return &s_grdpath3;
	case 0x1BDA: return &s_grdpath3s;
	case 0x1BEA: return &s_grdpath4;
	case 0x1BFA: return &s_grdpain;
	case 0x1C0A: return &s_grdpain1;
	case 0x1C1A: return &s_grdshoot1;
	case 0x1C2A: return &s_grdshoot2;
	case 0x1C3A: return &s_grdshoot3;
	case 0x1C4A: return &s_grdchase1;
	case 0x1C5A: return &s_grdchase1s;
	case 0x1C6A: return &s_grdchase2;
	case 0x1C7A: return &s_grdchase3;
	case 0x1C8A: return &s_grdchase3s;
	case 0x1C9A: return &s_grdchase4;
	case 0x1CAA: return &s_grddie1;
	case 0x1CBA: return &s_grddie2;
	case 0x1CCA: return &s_grddie3;
	case 0x1CDA: return &s_grddie4;
	case 0x1CEA: return &s_blinkychase1;
	case 0x1CFA: return &s_blinkychase2;
	case 0x1D0A: return &s_inkychase1;
	case 0x1D1A: return &s_inkychase2;
	case 0x1D2A: return &s_pinkychase1;
	case 0x1D3A: return &s_pinkychase2;
	case 0x1D4A: return &s_clydechase1;
	case 0x1D5A: return &s_clydechase2;
	case 0x1D6A: return &s_dogpath1;
	case 0x1D7A: return &s_dogpath1s;
	case 0x1D8A: return &s_dogpath2;
	case 0x1D9A: return &s_dogpath3;
	case 0x1DAA: return &s_dogpath3s;
	case 0x1DBA: return &s_dogpath4;
	case 0x1DCA: return &s_dogjump1;
	case 0x1DDA: return &s_dogjump2;
	case 0x1DEA: return &s_dogjump3;
	case 0x1DFA: return &s_dogjump4;
	case 0x1E0A: return &s_dogjump5;
	case 0x1E1A: return &s_dogchase1;
	case 0x1E2A: return &s_dogchase1s;
	case 0x1E3A: return &s_dogchase2;
	case 0x1E4A: return &s_dogchase3;
	case 0x1E5A: return &s_dogchase3s;
	case 0x1E6A: return &s_dogchase4;
	case 0x1E7A: return &s_dogdie1;
	case 0x1E8A: return &s_dogdie2;
	case 0x1E9A: return &s_dogdie3;
	case 0x1EAA: return &s_dogdead;
	case 0x1EBA: return &s_ofcstand;
	case 0x1ECA: return &s_ofcpath1;
	case 0x1EDA: return &s_ofcpath1s;
	case 0x1EEA: return &s_ofcpath2;
	case 0x1EFA: return &s_ofcpath3;
	case 0x1F0A: return &s_ofcpath3s;
	case 0x1F1A: return &s_ofcpath4;
	case 0x1F2A: return &s_ofcpain;
	case 0x1F3A: return &s_ofcpain1;
	case 0x1F4A: return &s_ofcshoot1;
	case 0x1F5A: return &s_ofcshoot2;
	case 0x1F6A: return &s_ofcshoot3;
	case 0x1F7A: return &s_ofcchase1;
	case 0x1F8A: return &s_ofcchase1s;
	case 0x1F9A: return &s_ofcchase2;
	case 0x1FAA: return &s_ofcchase3;
	case 0x1FBA: return &s_ofcchase3s;
	case 0x1FCA: return &s_ofcchase4;
	case 0x1FDA: return &s_ofcdie1;
	case 0x1FEA: return &s_ofcdie2;
	case 0x1FFA: return &s_ofcdie3;
	case 0x200A: return &s_ofcdie4;
	case 0x201A: return &s_ofcdie5;
	case 0x202A: return &s_mutstand;
	case 0x203A: return &s_mutpath1;
	case 0x204A: return &s_mutpath1s;
	case 0x205A: return &s_mutpath2;
	case 0x206A: return &s_mutpath3;
	case 0x207A: return &s_mutpath3s;
	case 0x208A: return &s_mutpath4;
	case 0x209A: return &s_mutpain;
	case 0x20AA: return &s_mutpain1;
	case 0x20BA: return &s_mutshoot1;
	case 0x20CA: return &s_mutshoot2;
	case 0x20DA: return &s_mutshoot3;
	case 0x20EA: return &s_mutshoot4;
	case 0x20FA: return &s_mutchase1;
	case 0x210A: return &s_mutchase1s;
	case 0x211A: return &s_mutchase2;
	case 0x212A: return &s_mutchase3;
	case 0x213A: return &s_mutchase3s;
	case 0x214A: return &s_mutchase4;
	case 0x215A: return &s_mutdie1;
	case 0x216A: return &s_mutdie2;
	case 0x217A: return &s_mutdie3;
	case 0x218A: return &s_mutdie4;
	case 0x219A: return &s_mutdie5;
	case 0x21AA: return &s_ssstand;
	case 0x21BA: return &s_sspath1;
	case 0x21CA: return &s_sspath1s;
	case 0x21DA: return &s_sspath2;
	case 0x21EA: return &s_sspath3;
	case 0x21FA: return &s_sspath3s;
	case 0x220A: return &s_sspath4;
	case 0x221A: return &s_sspain;
	case 0x222A: return &s_sspain1;
	case 0x223A: return &s_ssshoot1;
	case 0x224A: return &s_ssshoot2;
	case 0x225A: return &s_ssshoot3;
	case 0x226A: return &s_ssshoot4;
	case 0x227A: return &s_ssshoot5;
	case 0x228A: return &s_ssshoot6;
	case 0x229A: return &s_ssshoot7;
	case 0x22AA: return &s_ssshoot8;
	case 0x22BA: return &s_ssshoot9;
	case 0x22CA: return &s_sschase1;
	case 0x22DA: return &s_sschase1s;
	case 0x22EA: return &s_sschase2;
	case 0x22FA: return &s_sschase3;
	case 0x230A: return &s_sschase3s;
	case 0x231A: return &s_sschase4;
	case 0x232A: return &s_ssdie1;
	case 0x233A: return &s_ssdie2;
	case 0x234A: return &s_ssdie3;
	case 0x235A: return &s_ssdie4;
	case 0x236A: return &s_bossstand;
	case 0x237A: return &s_bosschase1;
	case 0x238A: return &s_bosschase1s;
	case 0x239A: return &s_bosschase2;
	case 0x23AA: return &s_bosschase3;
	case 0x23BA: return &s_bosschase3s;
	case 0x23CA: return &s_bosschase4;
	case 0x23DA: return &s_bossdie1;
	case 0x23EA: return &s_bossdie2;
	case 0x23FA: return &s_bossdie3;
	case 0x240A: return &s_bossdie4;
	case 0x241A: return &s_bossshoot1;
	case 0x242A: return &s_bossshoot2;
	case 0x243A: return &s_bossshoot3;
	case 0x244A: return &s_bossshoot4;
	case 0x245A: return &s_bossshoot5;
	case 0x246A: return &s_bossshoot6;
	case 0x247A: return &s_bossshoot7;
	case 0x248A: return &s_bossshoot8;
	case 0x249A: return &s_gretelstand;
	case 0x24AA: return &s_gretelchase1;
	case 0x24BA: return &s_gretelchase1s;
	case 0x24CA: return &s_gretelchase2;
	case 0x24DA: return &s_gretelchase3;
	case 0x24EA: return &s_gretelchase3s;
	case 0x24FA: return &s_gretelchase4;
	case 0x250A: return &s_greteldie1;
	case 0x251A: return &s_greteldie2;
	case 0x252A: return &s_greteldie3;
	case 0x253A: return &s_greteldie4;
	case 0x254A: return &s_gretelshoot1;
	case 0x255A: return &s_gretelshoot2;
	case 0x256A: return &s_gretelshoot3;
	case 0x257A: return &s_gretelshoot4;
	case 0x258A: return &s_gretelshoot5;
	case 0x259A: return &s_gretelshoot6;
	case 0x25AA: return &s_gretelshoot7;
	case 0x25BA: return &s_gretelshoot8;
	case 0x25DC: return &s_schabbstand;
	case 0x25EC: return &s_schabbchase1;
	case 0x25FC: return &s_schabbchase1s;
	case 0x260C: return &s_schabbchase2;
	case 0x261C: return &s_schabbchase3;
	case 0x262C: return &s_schabbchase3s;
	case 0x263C: return &s_schabbchase4;
	case 0x264C: return &s_schabbdeathcam;
	case 0x265C: return &s_schabbdie1;
	case 0x266C: return &s_schabbdie2;
	case 0x267C: return &s_schabbdie3;
	case 0x268C: return &s_schabbdie4;
	case 0x269C: return &s_schabbdie5;
	case 0x26AC: return &s_schabbdie6;
	case 0x26BC: return &s_schabbshoot1;
	case 0x26CC: return &s_schabbshoot2;
	case 0x26DC: return &s_needle1;
	case 0x26EC: return &s_needle2;
	case 0x26FC: return &s_needle3;
	case 0x270C: return &s_needle4;
	case 0x271C: return &s_giftstand;
	case 0x272C: return &s_giftchase1;
	case 0x273C: return &s_giftchase1s;
	case 0x274C: return &s_giftchase2;
	case 0x275C: return &s_giftchase3;
	case 0x276C: return &s_giftchase3s;
	case 0x277C: return &s_giftchase4;
	case 0x278C: return &s_giftdeathcam;
	case 0x279C: return &s_giftdie1;
	case 0x27AC: return &s_giftdie2;
	case 0x27BC: return &s_giftdie3;
	case 0x27CC: return &s_giftdie4;
	case 0x27DC: return &s_giftdie5;
	case 0x27EC: return &s_giftdie6;
	case 0x27FC: return &s_giftshoot1;
	case 0x280C: return &s_giftshoot2;
	case 0x281C: return &s_fatstand;
	case 0x282C: return &s_fatchase1;
	case 0x283C: return &s_fatchase1s;
	case 0x284C: return &s_fatchase2;
	case 0x285C: return &s_fatchase3;
	case 0x286C: return &s_fatchase3s;
	case 0x287C: return &s_fatchase4;
	case 0x288C: return &s_fatdeathcam;
	case 0x289C: return &s_fatdie1;
	case 0x28AC: return &s_fatdie2;
	case 0x28BC: return &s_fatdie3;
	case 0x28CC: return &s_fatdie4;
	case 0x28DC: return &s_fatdie5;
	case 0x28EC: return &s_fatdie6;
	case 0x28FC: return &s_fatshoot1;
	case 0x290C: return &s_fatshoot2;
	case 0x291C: return &s_fatshoot3;
	case 0x292C: return &s_fatshoot4;
	case 0x293C: return &s_fatshoot5;
	case 0x294C: return &s_fatshoot6;
	case 0x295C: return &s_fakestand;
	case 0x296C: return &s_fakechase1;
	case 0x297C: return &s_fakechase1s;
	case 0x298C: return &s_fakechase2;
	case 0x299C: return &s_fakechase3;
	case 0x29AC: return &s_fakechase3s;
	case 0x29BC: return &s_fakechase4;
	case 0x29CC: return &s_fakedie1;
	case 0x29DC: return &s_fakedie2;
	case 0x29EC: return &s_fakedie3;
	case 0x29FC: return &s_fakedie4;
	case 0x2A0C: return &s_fakedie5;
	case 0x2A1C: return &s_fakedie6;
	case 0x2A2C: return &s_fakeshoot1;
	case 0x2A3C: return &s_fakeshoot2;
	case 0x2A4C: return &s_fakeshoot3;
	case 0x2A5C: return &s_fakeshoot4;
	case 0x2A6C: return &s_fakeshoot5;
	case 0x2A7C: return &s_fakeshoot6;
	case 0x2A8C: return &s_fakeshoot7;
	case 0x2A9C: return &s_fakeshoot8;
	case 0x2AAC: return &s_fakeshoot9;
	case 0x2ABC: return &s_fire1;
	case 0x2ACC: return &s_fire2;
	case 0x2ADC: return &s_mechastand;
	case 0x2AEC: return &s_mechachase1;
	case 0x2AFC: return &s_mechachase1s;
	case 0x2B0C: return &s_mechachase2;
	case 0x2B1C: return &s_mechachase3;
	case 0x2B2C: return &s_mechachase3s;
	case 0x2B3C: return &s_mechachase4;
	case 0x2B4C: return &s_mechadie1;
	case 0x2B5C: return &s_mechadie2;
	case 0x2B6C: return &s_mechadie3;
	case 0x2B7C: return &s_mechadie4;
	case 0x2B8C: return &s_mechashoot1;
	case 0x2B9C: return &s_mechashoot2;
	case 0x2BAC: return &s_mechashoot3;
	case 0x2BBC: return &s_mechashoot4;
	case 0x2BCC: return &s_mechashoot5;
	case 0x2BDC: return &s_mechashoot6;
	case 0x2BEC: return &s_hitlerchase1;
	case 0x2BFC: return &s_hitlerchase1s;
	case 0x2C0C: return &s_hitlerchase2;
	case 0x2C1C: return &s_hitlerchase3;
	case 0x2C2C: return &s_hitlerchase3s;
	case 0x2C3C: return &s_hitlerchase4;
	case 0x2C4C: return &s_hitlerdeathcam;
	case 0x2C5C: return &s_hitlerdie1;
	case 0x2C6C: return &s_hitlerdie2;
	case 0x2C7C: return &s_hitlerdie3;
	case 0x2C8C: return &s_hitlerdie4;
	case 0x2C9C: return &s_hitlerdie5;
	case 0x2CAC: return &s_hitlerdie6;
	case 0x2CBC: return &s_hitlerdie7;
	case 0x2CCC: return &s_hitlerdie8;
	case 0x2CDC: return &s_hitlerdie9;
	case 0x2CEC: return &s_hitlerdie10;
	case 0x2CFC: return &s_hitlershoot1;
	case 0x2D0C: return &s_hitlershoot2;
	case 0x2D1C: return &s_hitlershoot3;
	case 0x2D2C: return &s_hitlershoot4;
	case 0x2D3C: return &s_hitlershoot5;
	case 0x2D4C: return &s_hitlershoot6;
	case 0x2D64: return &s_bjrun1;
	case 0x2D74: return &s_bjrun1s;
	case 0x2D84: return &s_bjrun2;
	case 0x2D94: return &s_bjrun3;
	case 0x2DA4: return &s_bjrun3s;
	case 0x2DB4: return &s_bjrun4;
	case 0x2DC4: return &s_bjjump1;
	case 0x2DD4: return &s_bjjump2;
	case 0x2DE4: return &s_bjjump3;
	case 0x2DF4: return &s_bjjump4;
	case 0x2E04: return &s_deathcam;
	}
	return NULL;
}

REFKEEN_NS_E
#endif
