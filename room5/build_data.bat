@echo off
REM setlocal EnableDelayedExpansion

:: Setup path
set Tools=..\MSXgl\tools
set MSXtk=%Tools%\MSXtk\bin
set Dest=.\data
if not exist %Dest% md %Dest%

:: Export background tiles
echo -- Export background tiles data...
%MSXtk%\MSXimg.exe assets\tileset.png -out %Dest%/bg_tileset.h -mode gm1 --gm2unique -name g_Tiles -pos 0 0 -size 128 128

:: Export player sprite
echo -- Export player sprite data...
%MSXtk%\MSXimg.exe assets\sprt_player.png -out %Dest%/sprt_player.h -pos 0 8 -size 16 16 -num 12 1 -name g_SprtPlayer -mode sprt ^
	-l i16 0 0 1 1 0xCCC35E ^
	-l i16 0 0 1 1 0xFFFFFF ^
	-l i16 0 0 1 1 0xDB6559 ^
	-l i16 0 0 1 1 0x010101

:: Export environment sprite
echo -- Export environment sprite data...
%MSXtk%\MSXimg.exe assets\sprt_enviro.png -out %Dest%/sprt_elevator.h -pos 0 0 -size 16 16 -num 2 1 -name g_SprtElevator -mode sprt -l i16 0 0 1 1 0xFFFFFF

REM pause