@echo off
REM setlocal EnableDelayedExpansion

:: Setup path
set Tools=..\..\tools
set MSXtk=%Tools%\MSXtk\bin
set Dest=.\tilesets
if not exist %Dest% md %Dest%

:: Export tiles
echo -- Export tiles data...
%MSXtk%\MSXimg.exe assets\tileset.png -out %Dest%/tileset.h -mode gm1 --gm2unique -name g_Tiles -pos 0 0 -size 128 128
%MSXtk%\MSXimg.exe assets\tileset.png -out %Dest%/tileset.bas -mode gm1 --gm2unique -pos 0 0 -size 128 128

REM :: Export sprite
REM echo -- Export sprite data...
REM %MSXtk%\MSXimg.exe assets\player.png -out %Dest%/player.h -pos 0 0 -size 16 16 -num 5 1 -name g_SprtPlayerSprt -mode sprt ^
	REM -l i16 0 0 1 1 0xCCC35E ^
	REM -l i16 0 0 1 1 0xFFFFFF ^
	REM -l i16 0 0 1 1 0xDB6559 ^
	REM -l i16 0 0 1 1 0x010101

pause