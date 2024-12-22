#include "msxgl.h"

extern const unsigned char g_AKG_MusicMain[];
extern const unsigned char g_AKG_MusicPhone[];
extern const unsigned char g_AKG_MusicEmpty[];

extern u8 g_CurrentMusic;
extern u8 g_NextMusic;
extern u8 g_NextSFX;

enum MUSIC_ID
{
	MUSIC_MAIN = 0,
	MUSIC_PHONE,
	MUSIC_EMPTY,
	MUSIC_MAX,
};

enum SFX_ID
{
	SFX_1 = 0,
	SFX_PHONE_RING,
	SFX_PHONE_PICK,
	SFX_4,
	SFX_5,
	SFX_CLICK,
	SFX_DEBUG,
	SFX_8,
	SFX_DOOR,
};

// Set the new music to be player
inline void PlayMusic(u8 id) { g_NextMusic = id; }

// Stop music
inline void StopMusic() { PlayMusic(MUSIC_EMPTY); }

// Set the new music to be player
inline void PlaySFX(u8 id) { g_NextSFX = id; }
