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

#ifdef REFKEEN_VER_SODFG14
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
extern statetype s_hrocket;
extern statetype s_hsmoke1;
extern statetype s_hsmoke2;
extern statetype s_hsmoke3;
extern statetype s_hsmoke4;
extern statetype s_hboom1;
extern statetype s_hboom2;
extern statetype s_hboom3;
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
extern statetype s_transstand;
extern statetype s_transchase1;
extern statetype s_transchase1s;
extern statetype s_transchase2;
extern statetype s_transchase3;
extern statetype s_transchase3s;
extern statetype s_transchase4;
extern statetype s_transdie0;
extern statetype s_transdie01;
extern statetype s_transdie1;
extern statetype s_transdie2;
extern statetype s_transdie3;
extern statetype s_transdie4;
extern statetype s_transshoot1;
extern statetype s_transshoot2;
extern statetype s_transshoot3;
extern statetype s_transshoot4;
extern statetype s_transshoot5;
extern statetype s_transshoot6;
extern statetype s_transshoot7;
extern statetype s_transshoot8;
extern statetype s_uberstand;
extern statetype s_uberchase1;
extern statetype s_uberchase1s;
extern statetype s_uberchase2;
extern statetype s_uberchase3;
extern statetype s_uberchase3s;
extern statetype s_uberchase4;
extern statetype s_uberdie0;
extern statetype s_uberdie01;
extern statetype s_uberdie1;
extern statetype s_uberdie2;
extern statetype s_uberdie3;
extern statetype s_uberdie4;
extern statetype s_uberdie5;
extern statetype s_ubershoot1;
extern statetype s_ubershoot2;
extern statetype s_ubershoot3;
extern statetype s_ubershoot4;
extern statetype s_ubershoot5;
extern statetype s_ubershoot6;
extern statetype s_ubershoot7;
extern statetype s_willstand;
extern statetype s_willchase1;
extern statetype s_willchase1s;
extern statetype s_willchase2;
extern statetype s_willchase3;
extern statetype s_willchase3s;
extern statetype s_willchase4;
extern statetype s_willdeathcam;
extern statetype s_willdie1;
extern statetype s_willdie2;
extern statetype s_willdie3;
extern statetype s_willdie4;
extern statetype s_willdie5;
extern statetype s_willdie6;
extern statetype s_willshoot1;
extern statetype s_willshoot2;
extern statetype s_willshoot3;
extern statetype s_willshoot4;
extern statetype s_willshoot5;
extern statetype s_willshoot6;
extern statetype s_deathstand;
extern statetype s_deathchase1;
extern statetype s_deathchase1s;
extern statetype s_deathchase2;
extern statetype s_deathchase3;
extern statetype s_deathchase3s;
extern statetype s_deathchase4;
extern statetype s_deathdeathcam;
extern statetype s_deathdie1;
extern statetype s_deathdie2;
extern statetype s_deathdie3;
extern statetype s_deathdie4;
extern statetype s_deathdie5;
extern statetype s_deathdie6;
extern statetype s_deathdie7;
extern statetype s_deathdie8;
extern statetype s_deathdie9;
extern statetype s_deathshoot1;
extern statetype s_deathshoot2;
extern statetype s_deathshoot3;
extern statetype s_deathshoot4;
extern statetype s_deathshoot5;
extern statetype s_angelstand;
extern statetype s_angelchase1;
extern statetype s_angelchase1s;
extern statetype s_angelchase2;
extern statetype s_angelchase3;
extern statetype s_angelchase3s;
extern statetype s_angelchase4;
extern statetype s_angeldie1;
extern statetype s_angeldie11;
extern statetype s_angeldie2;
extern statetype s_angeldie3;
extern statetype s_angeldie4;
extern statetype s_angeldie5;
extern statetype s_angeldie6;
extern statetype s_angeldie7;
extern statetype s_angeldie8;
extern statetype s_angeldie9;
extern statetype s_angelshoot1;
extern statetype s_angelshoot2;
extern statetype s_angelshoot3;
extern statetype s_angeltired;
extern statetype s_angeltired2;
extern statetype s_angeltired3;
extern statetype s_angeltired4;
extern statetype s_angeltired5;
extern statetype s_angeltired6;
extern statetype s_angeltired7;
extern statetype s_spark1;
extern statetype s_spark2;
extern statetype s_spark3;
extern statetype s_spark4;
extern statetype s_spectrewait1;
extern statetype s_spectrewait2;
extern statetype s_spectrewait3;
extern statetype s_spectrewait4;
extern statetype s_spectrechase1;
extern statetype s_spectrechase2;
extern statetype s_spectrechase3;
extern statetype s_spectrechase4;
extern statetype s_spectredie1;
extern statetype s_spectredie2;
extern statetype s_spectredie3;
extern statetype s_spectredie4;
extern statetype s_spectrewake;

void RefKeen_FillObjStatesWithDOSPointers_NonWL1(void)
{
	s_player.compatdospointer = 0x1712;
	s_attack.compatdospointer = 0x1722;
	s_rocket.compatdospointer = 0x1A10;
	s_smoke1.compatdospointer = 0x1A20;
	s_smoke2.compatdospointer = 0x1A30;
	s_smoke3.compatdospointer = 0x1A40;
	s_smoke4.compatdospointer = 0x1A50;
	s_boom1.compatdospointer = 0x1A60;
	s_boom2.compatdospointer = 0x1A70;
	s_boom3.compatdospointer = 0x1A80;
	s_hrocket.compatdospointer = 0x1A90;
	s_hsmoke1.compatdospointer = 0x1AA0;
	s_hsmoke2.compatdospointer = 0x1AB0;
	s_hsmoke3.compatdospointer = 0x1AC0;
	s_hsmoke4.compatdospointer = 0x1AD0;
	s_hboom1.compatdospointer = 0x1AE0;
	s_hboom2.compatdospointer = 0x1AF0;
	s_hboom3.compatdospointer = 0x1B00;
	s_grdstand.compatdospointer = 0x1B10;
	s_grdpath1.compatdospointer = 0x1B20;
	s_grdpath1s.compatdospointer = 0x1B30;
	s_grdpath2.compatdospointer = 0x1B40;
	s_grdpath3.compatdospointer = 0x1B50;
	s_grdpath3s.compatdospointer = 0x1B60;
	s_grdpath4.compatdospointer = 0x1B70;
	s_grdpain.compatdospointer = 0x1B80;
	s_grdpain1.compatdospointer = 0x1B90;
	s_grdshoot1.compatdospointer = 0x1BA0;
	s_grdshoot2.compatdospointer = 0x1BB0;
	s_grdshoot3.compatdospointer = 0x1BC0;
	s_grdchase1.compatdospointer = 0x1BD0;
	s_grdchase1s.compatdospointer = 0x1BE0;
	s_grdchase2.compatdospointer = 0x1BF0;
	s_grdchase3.compatdospointer = 0x1C00;
	s_grdchase3s.compatdospointer = 0x1C10;
	s_grdchase4.compatdospointer = 0x1C20;
	s_grddie1.compatdospointer = 0x1C30;
	s_grddie2.compatdospointer = 0x1C40;
	s_grddie3.compatdospointer = 0x1C50;
	s_grddie4.compatdospointer = 0x1C60;
	s_dogpath1.compatdospointer = 0x1C70;
	s_dogpath1s.compatdospointer = 0x1C80;
	s_dogpath2.compatdospointer = 0x1C90;
	s_dogpath3.compatdospointer = 0x1CA0;
	s_dogpath3s.compatdospointer = 0x1CB0;
	s_dogpath4.compatdospointer = 0x1CC0;
	s_dogjump1.compatdospointer = 0x1CD0;
	s_dogjump2.compatdospointer = 0x1CE0;
	s_dogjump3.compatdospointer = 0x1CF0;
	s_dogjump4.compatdospointer = 0x1D00;
	s_dogjump5.compatdospointer = 0x1D10;
	s_dogchase1.compatdospointer = 0x1D20;
	s_dogchase1s.compatdospointer = 0x1D30;
	s_dogchase2.compatdospointer = 0x1D40;
	s_dogchase3.compatdospointer = 0x1D50;
	s_dogchase3s.compatdospointer = 0x1D60;
	s_dogchase4.compatdospointer = 0x1D70;
	s_dogdie1.compatdospointer = 0x1D80;
	s_dogdie2.compatdospointer = 0x1D90;
	s_dogdie3.compatdospointer = 0x1DA0;
	s_dogdead.compatdospointer = 0x1DB0;
	s_ofcstand.compatdospointer = 0x1DC0;
	s_ofcpath1.compatdospointer = 0x1DD0;
	s_ofcpath1s.compatdospointer = 0x1DE0;
	s_ofcpath2.compatdospointer = 0x1DF0;
	s_ofcpath3.compatdospointer = 0x1E00;
	s_ofcpath3s.compatdospointer = 0x1E10;
	s_ofcpath4.compatdospointer = 0x1E20;
	s_ofcpain.compatdospointer = 0x1E30;
	s_ofcpain1.compatdospointer = 0x1E40;
	s_ofcshoot1.compatdospointer = 0x1E50;
	s_ofcshoot2.compatdospointer = 0x1E60;
	s_ofcshoot3.compatdospointer = 0x1E70;
	s_ofcchase1.compatdospointer = 0x1E80;
	s_ofcchase1s.compatdospointer = 0x1E90;
	s_ofcchase2.compatdospointer = 0x1EA0;
	s_ofcchase3.compatdospointer = 0x1EB0;
	s_ofcchase3s.compatdospointer = 0x1EC0;
	s_ofcchase4.compatdospointer = 0x1ED0;
	s_ofcdie1.compatdospointer = 0x1EE0;
	s_ofcdie2.compatdospointer = 0x1EF0;
	s_ofcdie3.compatdospointer = 0x1F00;
	s_ofcdie4.compatdospointer = 0x1F10;
	s_ofcdie5.compatdospointer = 0x1F20;
	s_mutstand.compatdospointer = 0x1F30;
	s_mutpath1.compatdospointer = 0x1F40;
	s_mutpath1s.compatdospointer = 0x1F50;
	s_mutpath2.compatdospointer = 0x1F60;
	s_mutpath3.compatdospointer = 0x1F70;
	s_mutpath3s.compatdospointer = 0x1F80;
	s_mutpath4.compatdospointer = 0x1F90;
	s_mutpain.compatdospointer = 0x1FA0;
	s_mutpain1.compatdospointer = 0x1FB0;
	s_mutshoot1.compatdospointer = 0x1FC0;
	s_mutshoot2.compatdospointer = 0x1FD0;
	s_mutshoot3.compatdospointer = 0x1FE0;
	s_mutshoot4.compatdospointer = 0x1FF0;
	s_mutchase1.compatdospointer = 0x2000;
	s_mutchase1s.compatdospointer = 0x2010;
	s_mutchase2.compatdospointer = 0x2020;
	s_mutchase3.compatdospointer = 0x2030;
	s_mutchase3s.compatdospointer = 0x2040;
	s_mutchase4.compatdospointer = 0x2050;
	s_mutdie1.compatdospointer = 0x2060;
	s_mutdie2.compatdospointer = 0x2070;
	s_mutdie3.compatdospointer = 0x2080;
	s_mutdie4.compatdospointer = 0x2090;
	s_mutdie5.compatdospointer = 0x20A0;
	s_ssstand.compatdospointer = 0x20B0;
	s_sspath1.compatdospointer = 0x20C0;
	s_sspath1s.compatdospointer = 0x20D0;
	s_sspath2.compatdospointer = 0x20E0;
	s_sspath3.compatdospointer = 0x20F0;
	s_sspath3s.compatdospointer = 0x2100;
	s_sspath4.compatdospointer = 0x2110;
	s_sspain.compatdospointer = 0x2120;
	s_sspain1.compatdospointer = 0x2130;
	s_ssshoot1.compatdospointer = 0x2140;
	s_ssshoot2.compatdospointer = 0x2150;
	s_ssshoot3.compatdospointer = 0x2160;
	s_ssshoot4.compatdospointer = 0x2170;
	s_ssshoot5.compatdospointer = 0x2180;
	s_ssshoot6.compatdospointer = 0x2190;
	s_ssshoot7.compatdospointer = 0x21A0;
	s_ssshoot8.compatdospointer = 0x21B0;
	s_ssshoot9.compatdospointer = 0x21C0;
	s_sschase1.compatdospointer = 0x21D0;
	s_sschase1s.compatdospointer = 0x21E0;
	s_sschase2.compatdospointer = 0x21F0;
	s_sschase3.compatdospointer = 0x2200;
	s_sschase3s.compatdospointer = 0x2210;
	s_sschase4.compatdospointer = 0x2220;
	s_ssdie1.compatdospointer = 0x2230;
	s_ssdie2.compatdospointer = 0x2240;
	s_ssdie3.compatdospointer = 0x2250;
	s_ssdie4.compatdospointer = 0x2260;
	s_transstand.compatdospointer = 0x2282;
	s_transchase1.compatdospointer = 0x2292;
	s_transchase1s.compatdospointer = 0x22A2;
	s_transchase2.compatdospointer = 0x22B2;
	s_transchase3.compatdospointer = 0x22C2;
	s_transchase3s.compatdospointer = 0x22D2;
	s_transchase4.compatdospointer = 0x22E2;
	s_transdie0.compatdospointer = 0x22F2;
	s_transdie01.compatdospointer = 0x2302;
	s_transdie1.compatdospointer = 0x2312;
	s_transdie2.compatdospointer = 0x2322;
	s_transdie3.compatdospointer = 0x2332;
	s_transdie4.compatdospointer = 0x2342;
	s_transshoot1.compatdospointer = 0x2352;
	s_transshoot2.compatdospointer = 0x2362;
	s_transshoot3.compatdospointer = 0x2372;
	s_transshoot4.compatdospointer = 0x2382;
	s_transshoot5.compatdospointer = 0x2392;
	s_transshoot6.compatdospointer = 0x23A2;
	s_transshoot7.compatdospointer = 0x23B2;
	s_transshoot8.compatdospointer = 0x23C2;
	s_uberstand.compatdospointer = 0x23D2;
	s_uberchase1.compatdospointer = 0x23E2;
	s_uberchase1s.compatdospointer = 0x23F2;
	s_uberchase2.compatdospointer = 0x2402;
	s_uberchase3.compatdospointer = 0x2412;
	s_uberchase3s.compatdospointer = 0x2422;
	s_uberchase4.compatdospointer = 0x2432;
	s_uberdie0.compatdospointer = 0x2442;
	s_uberdie01.compatdospointer = 0x2452;
	s_uberdie1.compatdospointer = 0x2462;
	s_uberdie2.compatdospointer = 0x2472;
	s_uberdie3.compatdospointer = 0x2482;
	s_uberdie4.compatdospointer = 0x2492;
	s_uberdie5.compatdospointer = 0x24A2;
	s_ubershoot1.compatdospointer = 0x24B2;
	s_ubershoot2.compatdospointer = 0x24C2;
	s_ubershoot3.compatdospointer = 0x24D2;
	s_ubershoot4.compatdospointer = 0x24E2;
	s_ubershoot5.compatdospointer = 0x24F2;
	s_ubershoot6.compatdospointer = 0x2502;
	s_ubershoot7.compatdospointer = 0x2512;
	s_willstand.compatdospointer = 0x2522;
	s_willchase1.compatdospointer = 0x2532;
	s_willchase1s.compatdospointer = 0x2542;
	s_willchase2.compatdospointer = 0x2552;
	s_willchase3.compatdospointer = 0x2562;
	s_willchase3s.compatdospointer = 0x2572;
	s_willchase4.compatdospointer = 0x2582;
	s_willdeathcam.compatdospointer = 0x2592;
	s_willdie1.compatdospointer = 0x25A2;
	s_willdie2.compatdospointer = 0x25B2;
	s_willdie3.compatdospointer = 0x25C2;
	s_willdie4.compatdospointer = 0x25D2;
	s_willdie5.compatdospointer = 0x25E2;
	s_willdie6.compatdospointer = 0x25F2;
	s_willshoot1.compatdospointer = 0x2602;
	s_willshoot2.compatdospointer = 0x2612;
	s_willshoot3.compatdospointer = 0x2622;
	s_willshoot4.compatdospointer = 0x2632;
	s_willshoot5.compatdospointer = 0x2642;
	s_willshoot6.compatdospointer = 0x2652;
	s_deathstand.compatdospointer = 0x2662;
	s_deathchase1.compatdospointer = 0x2672;
	s_deathchase1s.compatdospointer = 0x2682;
	s_deathchase2.compatdospointer = 0x2692;
	s_deathchase3.compatdospointer = 0x26A2;
	s_deathchase3s.compatdospointer = 0x26B2;
	s_deathchase4.compatdospointer = 0x26C2;
	s_deathdeathcam.compatdospointer = 0x26D2;
	s_deathdie1.compatdospointer = 0x26E2;
	s_deathdie2.compatdospointer = 0x26F2;
	s_deathdie3.compatdospointer = 0x2702;
	s_deathdie4.compatdospointer = 0x2712;
	s_deathdie5.compatdospointer = 0x2722;
	s_deathdie6.compatdospointer = 0x2732;
	s_deathdie7.compatdospointer = 0x2742;
	s_deathdie8.compatdospointer = 0x2752;
	s_deathdie9.compatdospointer = 0x2762;
	s_deathshoot1.compatdospointer = 0x2772;
	s_deathshoot2.compatdospointer = 0x2782;
	s_deathshoot3.compatdospointer = 0x2792;
	s_deathshoot4.compatdospointer = 0x27A2;
	s_deathshoot5.compatdospointer = 0x27B2;
	s_angelstand.compatdospointer = 0x27C2;
	s_angelchase1.compatdospointer = 0x27D2;
	s_angelchase1s.compatdospointer = 0x27E2;
	s_angelchase2.compatdospointer = 0x27F2;
	s_angelchase3.compatdospointer = 0x2802;
	s_angelchase3s.compatdospointer = 0x2812;
	s_angelchase4.compatdospointer = 0x2822;
	s_angeldie1.compatdospointer = 0x2832;
	s_angeldie11.compatdospointer = 0x2842;
	s_angeldie2.compatdospointer = 0x2852;
	s_angeldie3.compatdospointer = 0x2862;
	s_angeldie4.compatdospointer = 0x2872;
	s_angeldie5.compatdospointer = 0x2882;
	s_angeldie6.compatdospointer = 0x2892;
	s_angeldie7.compatdospointer = 0x28A2;
	s_angeldie8.compatdospointer = 0x28B2;
	s_angeldie9.compatdospointer = 0x28C2;
	s_angelshoot1.compatdospointer = 0x28D2;
	s_angelshoot2.compatdospointer = 0x28E2;
	s_angelshoot3.compatdospointer = 0x28F2;
	s_angeltired.compatdospointer = 0x2902;
	s_angeltired2.compatdospointer = 0x2912;
	s_angeltired3.compatdospointer = 0x2922;
	s_angeltired4.compatdospointer = 0x2932;
	s_angeltired5.compatdospointer = 0x2942;
	s_angeltired6.compatdospointer = 0x2952;
	s_angeltired7.compatdospointer = 0x2962;
	s_spark1.compatdospointer = 0x2972;
	s_spark2.compatdospointer = 0x2982;
	s_spark3.compatdospointer = 0x2992;
	s_spark4.compatdospointer = 0x29A2;
	s_spectrewait1.compatdospointer = 0x29B2;
	s_spectrewait2.compatdospointer = 0x29C2;
	s_spectrewait3.compatdospointer = 0x29D2;
	s_spectrewait4.compatdospointer = 0x29E2;
	s_spectrechase1.compatdospointer = 0x29F2;
	s_spectrechase2.compatdospointer = 0x2A02;
	s_spectrechase3.compatdospointer = 0x2A12;
	s_spectrechase4.compatdospointer = 0x2A22;
	s_spectredie1.compatdospointer = 0x2A32;
	s_spectredie2.compatdospointer = 0x2A42;
	s_spectredie3.compatdospointer = 0x2A52;
	s_spectredie4.compatdospointer = 0x2A62;
	s_spectrewake.compatdospointer = 0x2A72;
}

statetype *RefKeen_GetObjStatePtrFromDOSPointer_NonWL1(uint_fast32_t dosptr)
{
	switch (dosptr)
	{
	case 0x1712: return &s_player;
	case 0x1722: return &s_attack;
	case 0x1A10: return &s_rocket;
	case 0x1A20: return &s_smoke1;
	case 0x1A30: return &s_smoke2;
	case 0x1A40: return &s_smoke3;
	case 0x1A50: return &s_smoke4;
	case 0x1A60: return &s_boom1;
	case 0x1A70: return &s_boom2;
	case 0x1A80: return &s_boom3;
	case 0x1A90: return &s_hrocket;
	case 0x1AA0: return &s_hsmoke1;
	case 0x1AB0: return &s_hsmoke2;
	case 0x1AC0: return &s_hsmoke3;
	case 0x1AD0: return &s_hsmoke4;
	case 0x1AE0: return &s_hboom1;
	case 0x1AF0: return &s_hboom2;
	case 0x1B00: return &s_hboom3;
	case 0x1B10: return &s_grdstand;
	case 0x1B20: return &s_grdpath1;
	case 0x1B30: return &s_grdpath1s;
	case 0x1B40: return &s_grdpath2;
	case 0x1B50: return &s_grdpath3;
	case 0x1B60: return &s_grdpath3s;
	case 0x1B70: return &s_grdpath4;
	case 0x1B80: return &s_grdpain;
	case 0x1B90: return &s_grdpain1;
	case 0x1BA0: return &s_grdshoot1;
	case 0x1BB0: return &s_grdshoot2;
	case 0x1BC0: return &s_grdshoot3;
	case 0x1BD0: return &s_grdchase1;
	case 0x1BE0: return &s_grdchase1s;
	case 0x1BF0: return &s_grdchase2;
	case 0x1C00: return &s_grdchase3;
	case 0x1C10: return &s_grdchase3s;
	case 0x1C20: return &s_grdchase4;
	case 0x1C30: return &s_grddie1;
	case 0x1C40: return &s_grddie2;
	case 0x1C50: return &s_grddie3;
	case 0x1C60: return &s_grddie4;
	case 0x1C70: return &s_dogpath1;
	case 0x1C80: return &s_dogpath1s;
	case 0x1C90: return &s_dogpath2;
	case 0x1CA0: return &s_dogpath3;
	case 0x1CB0: return &s_dogpath3s;
	case 0x1CC0: return &s_dogpath4;
	case 0x1CD0: return &s_dogjump1;
	case 0x1CE0: return &s_dogjump2;
	case 0x1CF0: return &s_dogjump3;
	case 0x1D00: return &s_dogjump4;
	case 0x1D10: return &s_dogjump5;
	case 0x1D20: return &s_dogchase1;
	case 0x1D30: return &s_dogchase1s;
	case 0x1D40: return &s_dogchase2;
	case 0x1D50: return &s_dogchase3;
	case 0x1D60: return &s_dogchase3s;
	case 0x1D70: return &s_dogchase4;
	case 0x1D80: return &s_dogdie1;
	case 0x1D90: return &s_dogdie2;
	case 0x1DA0: return &s_dogdie3;
	case 0x1DB0: return &s_dogdead;
	case 0x1DC0: return &s_ofcstand;
	case 0x1DD0: return &s_ofcpath1;
	case 0x1DE0: return &s_ofcpath1s;
	case 0x1DF0: return &s_ofcpath2;
	case 0x1E00: return &s_ofcpath3;
	case 0x1E10: return &s_ofcpath3s;
	case 0x1E20: return &s_ofcpath4;
	case 0x1E30: return &s_ofcpain;
	case 0x1E40: return &s_ofcpain1;
	case 0x1E50: return &s_ofcshoot1;
	case 0x1E60: return &s_ofcshoot2;
	case 0x1E70: return &s_ofcshoot3;
	case 0x1E80: return &s_ofcchase1;
	case 0x1E90: return &s_ofcchase1s;
	case 0x1EA0: return &s_ofcchase2;
	case 0x1EB0: return &s_ofcchase3;
	case 0x1EC0: return &s_ofcchase3s;
	case 0x1ED0: return &s_ofcchase4;
	case 0x1EE0: return &s_ofcdie1;
	case 0x1EF0: return &s_ofcdie2;
	case 0x1F00: return &s_ofcdie3;
	case 0x1F10: return &s_ofcdie4;
	case 0x1F20: return &s_ofcdie5;
	case 0x1F30: return &s_mutstand;
	case 0x1F40: return &s_mutpath1;
	case 0x1F50: return &s_mutpath1s;
	case 0x1F60: return &s_mutpath2;
	case 0x1F70: return &s_mutpath3;
	case 0x1F80: return &s_mutpath3s;
	case 0x1F90: return &s_mutpath4;
	case 0x1FA0: return &s_mutpain;
	case 0x1FB0: return &s_mutpain1;
	case 0x1FC0: return &s_mutshoot1;
	case 0x1FD0: return &s_mutshoot2;
	case 0x1FE0: return &s_mutshoot3;
	case 0x1FF0: return &s_mutshoot4;
	case 0x2000: return &s_mutchase1;
	case 0x2010: return &s_mutchase1s;
	case 0x2020: return &s_mutchase2;
	case 0x2030: return &s_mutchase3;
	case 0x2040: return &s_mutchase3s;
	case 0x2050: return &s_mutchase4;
	case 0x2060: return &s_mutdie1;
	case 0x2070: return &s_mutdie2;
	case 0x2080: return &s_mutdie3;
	case 0x2090: return &s_mutdie4;
	case 0x20A0: return &s_mutdie5;
	case 0x20B0: return &s_ssstand;
	case 0x20C0: return &s_sspath1;
	case 0x20D0: return &s_sspath1s;
	case 0x20E0: return &s_sspath2;
	case 0x20F0: return &s_sspath3;
	case 0x2100: return &s_sspath3s;
	case 0x2110: return &s_sspath4;
	case 0x2120: return &s_sspain;
	case 0x2130: return &s_sspain1;
	case 0x2140: return &s_ssshoot1;
	case 0x2150: return &s_ssshoot2;
	case 0x2160: return &s_ssshoot3;
	case 0x2170: return &s_ssshoot4;
	case 0x2180: return &s_ssshoot5;
	case 0x2190: return &s_ssshoot6;
	case 0x21A0: return &s_ssshoot7;
	case 0x21B0: return &s_ssshoot8;
	case 0x21C0: return &s_ssshoot9;
	case 0x21D0: return &s_sschase1;
	case 0x21E0: return &s_sschase1s;
	case 0x21F0: return &s_sschase2;
	case 0x2200: return &s_sschase3;
	case 0x2210: return &s_sschase3s;
	case 0x2220: return &s_sschase4;
	case 0x2230: return &s_ssdie1;
	case 0x2240: return &s_ssdie2;
	case 0x2250: return &s_ssdie3;
	case 0x2260: return &s_ssdie4;
	case 0x2282: return &s_transstand;
	case 0x2292: return &s_transchase1;
	case 0x22A2: return &s_transchase1s;
	case 0x22B2: return &s_transchase2;
	case 0x22C2: return &s_transchase3;
	case 0x22D2: return &s_transchase3s;
	case 0x22E2: return &s_transchase4;
	case 0x22F2: return &s_transdie0;
	case 0x2302: return &s_transdie01;
	case 0x2312: return &s_transdie1;
	case 0x2322: return &s_transdie2;
	case 0x2332: return &s_transdie3;
	case 0x2342: return &s_transdie4;
	case 0x2352: return &s_transshoot1;
	case 0x2362: return &s_transshoot2;
	case 0x2372: return &s_transshoot3;
	case 0x2382: return &s_transshoot4;
	case 0x2392: return &s_transshoot5;
	case 0x23A2: return &s_transshoot6;
	case 0x23B2: return &s_transshoot7;
	case 0x23C2: return &s_transshoot8;
	case 0x23D2: return &s_uberstand;
	case 0x23E2: return &s_uberchase1;
	case 0x23F2: return &s_uberchase1s;
	case 0x2402: return &s_uberchase2;
	case 0x2412: return &s_uberchase3;
	case 0x2422: return &s_uberchase3s;
	case 0x2432: return &s_uberchase4;
	case 0x2442: return &s_uberdie0;
	case 0x2452: return &s_uberdie01;
	case 0x2462: return &s_uberdie1;
	case 0x2472: return &s_uberdie2;
	case 0x2482: return &s_uberdie3;
	case 0x2492: return &s_uberdie4;
	case 0x24A2: return &s_uberdie5;
	case 0x24B2: return &s_ubershoot1;
	case 0x24C2: return &s_ubershoot2;
	case 0x24D2: return &s_ubershoot3;
	case 0x24E2: return &s_ubershoot4;
	case 0x24F2: return &s_ubershoot5;
	case 0x2502: return &s_ubershoot6;
	case 0x2512: return &s_ubershoot7;
	case 0x2522: return &s_willstand;
	case 0x2532: return &s_willchase1;
	case 0x2542: return &s_willchase1s;
	case 0x2552: return &s_willchase2;
	case 0x2562: return &s_willchase3;
	case 0x2572: return &s_willchase3s;
	case 0x2582: return &s_willchase4;
	case 0x2592: return &s_willdeathcam;
	case 0x25A2: return &s_willdie1;
	case 0x25B2: return &s_willdie2;
	case 0x25C2: return &s_willdie3;
	case 0x25D2: return &s_willdie4;
	case 0x25E2: return &s_willdie5;
	case 0x25F2: return &s_willdie6;
	case 0x2602: return &s_willshoot1;
	case 0x2612: return &s_willshoot2;
	case 0x2622: return &s_willshoot3;
	case 0x2632: return &s_willshoot4;
	case 0x2642: return &s_willshoot5;
	case 0x2652: return &s_willshoot6;
	case 0x2662: return &s_deathstand;
	case 0x2672: return &s_deathchase1;
	case 0x2682: return &s_deathchase1s;
	case 0x2692: return &s_deathchase2;
	case 0x26A2: return &s_deathchase3;
	case 0x26B2: return &s_deathchase3s;
	case 0x26C2: return &s_deathchase4;
	case 0x26D2: return &s_deathdeathcam;
	case 0x26E2: return &s_deathdie1;
	case 0x26F2: return &s_deathdie2;
	case 0x2702: return &s_deathdie3;
	case 0x2712: return &s_deathdie4;
	case 0x2722: return &s_deathdie5;
	case 0x2732: return &s_deathdie6;
	case 0x2742: return &s_deathdie7;
	case 0x2752: return &s_deathdie8;
	case 0x2762: return &s_deathdie9;
	case 0x2772: return &s_deathshoot1;
	case 0x2782: return &s_deathshoot2;
	case 0x2792: return &s_deathshoot3;
	case 0x27A2: return &s_deathshoot4;
	case 0x27B2: return &s_deathshoot5;
	case 0x27C2: return &s_angelstand;
	case 0x27D2: return &s_angelchase1;
	case 0x27E2: return &s_angelchase1s;
	case 0x27F2: return &s_angelchase2;
	case 0x2802: return &s_angelchase3;
	case 0x2812: return &s_angelchase3s;
	case 0x2822: return &s_angelchase4;
	case 0x2832: return &s_angeldie1;
	case 0x2842: return &s_angeldie11;
	case 0x2852: return &s_angeldie2;
	case 0x2862: return &s_angeldie3;
	case 0x2872: return &s_angeldie4;
	case 0x2882: return &s_angeldie5;
	case 0x2892: return &s_angeldie6;
	case 0x28A2: return &s_angeldie7;
	case 0x28B2: return &s_angeldie8;
	case 0x28C2: return &s_angeldie9;
	case 0x28D2: return &s_angelshoot1;
	case 0x28E2: return &s_angelshoot2;
	case 0x28F2: return &s_angelshoot3;
	case 0x2902: return &s_angeltired;
	case 0x2912: return &s_angeltired2;
	case 0x2922: return &s_angeltired3;
	case 0x2932: return &s_angeltired4;
	case 0x2942: return &s_angeltired5;
	case 0x2952: return &s_angeltired6;
	case 0x2962: return &s_angeltired7;
	case 0x2972: return &s_spark1;
	case 0x2982: return &s_spark2;
	case 0x2992: return &s_spark3;
	case 0x29A2: return &s_spark4;
	case 0x29B2: return &s_spectrewait1;
	case 0x29C2: return &s_spectrewait2;
	case 0x29D2: return &s_spectrewait3;
	case 0x29E2: return &s_spectrewait4;
	case 0x29F2: return &s_spectrechase1;
	case 0x2A02: return &s_spectrechase2;
	case 0x2A12: return &s_spectrechase3;
	case 0x2A22: return &s_spectrechase4;
	case 0x2A32: return &s_spectredie1;
	case 0x2A42: return &s_spectredie2;
	case 0x2A52: return &s_spectredie3;
	case 0x2A62: return &s_spectredie4;
	case 0x2A72: return &s_spectrewake;
	}
	return NULL;
}

REFKEEN_NS_E
#endif
