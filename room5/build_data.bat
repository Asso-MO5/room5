@echo off
REM setlocal EnableDelayedExpansion

:: Setup path
set Tools=..\MSXgl\tools
set MSXtk=%Tools%\MSXtk\bin
set Dest=.\data
if not exist %Dest% md %Dest%

:: Export tiles
echo -- Export tiles data...
%MSXtk%\MSXimg.exe assets\tileset.png -out %Dest%/bg_tileset.h -mode gm1 --gm2unique -name g_Tiles -pos 0 0 -size 128 128

:: Export sprite
echo -- Export sprite data...
%MSXtk%\MSXimg.exe assets\sprt_player.png -out %Dest%/sprt_player.h -pos 0 8 -size 16 16 -num 8 1 -name g_SprtPlayerSprt -mode sprt ^
	-l i16 0 0 1 1 0xCCC35E ^
	-l i16 0 0 1 1 0xFFFFFF ^
	-l i16 0 0 1 1 0xDB6559 ^
	-l i16 0 0 1 1 0x010101

pause