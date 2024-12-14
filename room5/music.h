#include "msxgl.h"

extern const unsigned char g_AKG_MusicMain[];
extern const unsigned char g_AKG_MusicPhone[];
extern const unsigned char g_AKG_MusicEmpty[];

extern u8 g_CurrentMusic;
extern u8 g_NextMusic;


enum MUSIC_ID
{
	MUSIC_MAIN = 0,
	MUSIC_PHONE,
	MUSIC_EMPTY,
	MUSIC_MAX,
};

// Set the new music to be player
inline void PlayMusic(u8 id) { g_NextMusic = id; }

// Stop music
inline void StopMusic() { PlayMusic(MUSIC_EMPTY); }