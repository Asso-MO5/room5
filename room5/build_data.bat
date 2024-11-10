@echo off
setlocal EnableDelayedExpansion

:: Setup path
set Tools=..\MSXgl\tools
set MSXtk=%Tools%\MSXtk\bin
set Dest=.\data
if not exist %Dest% md %Dest%

:: Export background tiles
echo -- Export background tiles data...
%MSXtk%\MSXimg.exe assets\tileset.png -out %Dest%/bg_tileset.h -mode gm1 --tilesUnique -name g_Tiles -pos 0 0 -size 128 128 -compress pletter

:: Export player sprite
echo -- Export player sprite data...
%MSXtk%\MSXimg.exe assets\sprt_player.png -out %Dest%/sprt_player.h -pos 0 8 -size 16 16 -num 12 1 -name g_SprtPlayer -mode sprt ^
	-l i16 0 -8 1 1 0xCCC35E ^
	-l i16 0 0 1 1 0xFFFFFF ^
	-l i16 0 8 1 1 0xDB6559 ^
	-l i16 0 0 1 1 0x010101

:: Export environment sprite
echo -- Export environment sprite data...
%MSXtk%\MSXimg.exe assets\sprt_enviro.png -out %Dest%/sprt_elevator.h -pos 0 0 -size 16 16 -num 2 1 -name g_SprtElevator -mode sprt -l i16 0 0 1 1 0xFFFFFF

:: Convert binary level to header
for %%G in (data\level\*.bin) do (
    set "temp=%%~nG"
    echo Converting %%~nG.bin...
    %Tools%\compress\Pletter\pletter %%G data\level\%%~nG.pl5
    %MSXtk%\MSXbin data\level\%%~nG.pl5 -ad -t g_Level!temp:~-3! -o data\level\%%~nG.h
)

:: Convert Arkos Tracker music
%Tools%\compress\Pletter\pletter assets\hocuspocus.akg  assets\hocuspocus.pl5
%MSXtk%\MSXbin assets\hocuspocus.pl5 -ad -t g_AKG_HocusPocus -o data\sounds\akg_HocusPocus.h
@REM %Tools%\compress\Pletter\pletter assets\music\music_main.akg  assets\music\music_main.pl5
@REM %MSXtk%\MSXbin assets\music\music_main.pl5 -ad -t g_AKG_MusicMain -o data\sounds\music_main.h

:: Convert Japanese font
%MSXtk%\MSXimg assets\font_kana8.png -out data\font_jp.h -pos 0 0 -size 8 8  -gap 0 0 -num 8 13  -trans 0x000000 -bpc 1 -name g_Font_JP

REM pause