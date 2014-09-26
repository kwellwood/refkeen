=====================================================================
Chocolate Keen Dreams (currently based on Keen Dreams CGA v1.05 only)
=====================================================================

This is a port of Keen Dreams release originally compatible with the CGA
(so basically just 4 distinct colors are used for the graphics).

Note that it does not come with a copy of the game, which is required.
It currently aims to be a replacement executable for Keen Dreams CGA v1.05.

---------------------------------------------------------------------------
Based on the README.md file of the original Keen Dreams source code release
---------------------------------------------------------------------------

This port is released under the GNU GPLv2+.  See LICENSE for more details.

The release of the source code does not affect the licensing of the game data
files, which you must still legally acquire.  This includes the static data
included in this repository for your convenience.  However, you are permitted
to link and distribute that data for the purposes of compatibility with the
original game.

The original source code release was made possible by a crowdfunding effort.
It is brought to you by Javier M. Chavez and Chuck Naaden with additional
support from:

* Dave Allen
* Kirill Illenseer
* Michael Jurich
* Tom Laermans
* Jeremy Newman
* Braden Obrzut
* Evan Ramos
* Sam Schultz
* Matt Stath
* Ian Williams
* Steven Zakulec
* et al

-----------------
Some more credits
-----------------

* sulix, for a hint about memory wrapping, as well as having earlier experience
with him in general. Also done research on Keen.
* adurdin, quantumg, keenrush, levellord, levellass and lemm for their
research works.
* Caitlin Shaw for CloneKeen, a reimplementation of Keen 1-3.
* gerstrong for Commander Genius, containing a few engines used as
reimplementations of Keen 1-3 and Keen 4-6. Originally started
as a branch of CloneKeen known as CloneKeenPlus.

* Apologizes to anybody not mentioned here who deserves a credit. Guess I can
say to all of you, that you should be considered special here. :)

----------------
Why CGA graphics
----------------

As a possible preparation for Commander Keen 4-6, some engine code considered
to be shared with these was originally ported from the Catacomb 3D source code
(https://github.com/FlatRockSoft/Catacomb3D), with no actual testing.
CGA routines were preferred, given possible complications with the EGA
bit planes and multiple read/write modes. Later, this assisted with
the porting of Keen Dreams CGA.

--------------
Current status
--------------

- The mouse for control panel navigation, and keyboard basically everywhere.
- Basic joystick support is in, although it's kind-of similar to the DOS days
so it doesn't remind of more recent titles.
- AdLib and PC Speaker sound emulations are in. AdLib emulation is possible
thanks to the DBOPL emulator from DOSBox.
- CGA graphics and text mode emulation (on an emulated VGA adapter).
- Game is playable using a 64-bit Linux executable (tested on Ubuntu 14.04),
as well as a 32-bit Windows executable, but it hasn't yet been entirely tested.
New non-vanilla bugs are possible!
- There should be compatibility with the configuration file as generated by the
original DOS executable, but this hasn't been tested.
- Saved games aren't exactly tested, and are known to be incompatible with the
original DOS release.

---------------
Making this run
---------------

This requires Keen Dreams CGA v1.05. On Windows, you should simply drop
the files SDL2.dll and chocolate-keen-dreams-cga.exe together with the files
coming with the original game, and then launch chocolate-keen-dreams-cga.exe.
Furthermore, you may optionally copy any of the bundled .bat files.

-------------------------------------------------------
How to play with a fullscreen and/or software rendering
-------------------------------------------------------

Files like chocolate-keen-dreams-cga-fullscreen.bat should be useful here.

-----------------------------------
Help! I'm having multiple monitors!
-----------------------------------

Can't say this is well-tested, but try setting this environment variable
to some number in a command prompt before starting the game:
CHOCOLATE_KEEN_DISPLAYNUM. For instance, on Windows:

set CHOCOLATE_KEEN_DISPLAYNUM=1

----------------------------
How to (un)lock mouse cursor
----------------------------

- Leaving the window (basically making it lose keyboard focus) should release
the cursor. Clicking on the window later should lock the cursor. Note that the
latter step should not be required with a fullscreen window.

--------------------
There is some bug...
--------------------

This is still new, and bugs tend to happen in the porting process.
But, if it's rather a bug found in the original game which is reproduced,
most chances are it won't be fixed, since Chocolate Keen Dreams aims to
preserve behaviors of an original release, including bugs, at least if it's not
too difficult (e.g., anything that highly depends on the memory layout).

-----------------------------------------------
Building Chocolate Keen Dreams from the sources
-----------------------------------------------

- Development files for SDL 2.0 are required, as well as GNU make and the
GNU Compiler Collection's C compiler (i.e. gcc). In practice, at the moment
only "make" and "gcc" are probably required. If nothing goes wrong, a
single "make" command should build the executable. "make clean" removes any
generated object or executable file, assuming the *exact* same arguments have
been passed to "make" as before, with the exception of "clean".
- MinGW can be used as well (tested on Linux). If you try to cross-compile
then you may wish to set PLATFORM=WINDOWS and BINPREFIX accordingly.

---------
Changelog
---------

Sep 26 2014 (v0.8.0):
- Initial release, based on Keen Dreams CGA v1.05. Should be playable with
sound effects and CGA graphics on Linux and Windows desktops. Game saving and
more is totally untested and may be incompatible with original data generated
by the corresponding DOS executable (saved games are known to be incompatible).

- NY00123
