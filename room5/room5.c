/*
		______ _____  ________  ___  _____
		| ___ \  _  ||  _  |  \/  | |  ___|
		| |_/ / | | || | | | .  . | |___ \
		|    /| | | || | | | |\/| |     \ \
		| |\ \\ \_/ /\ \_/ / |  | | /\__/ /
		\_| \_|\___/  \___/\_|  |_/ \____/

*/

//=============================================================================
// INCLUDES
//=============================================================================
#include "msxgl.h"
#include "localize.h"
#include "compress/pletter.h"
#include "arkos/akg_player.h"
#include "room5.h"
#include "level_defs.h"
#include "tiles_defs.h"
#include "tiles.h"
#include "inventory.h"
#include "objects.h"
#include "elevator.h"
#include "sprite_fx.h"
#include "doors.h"
#include "save.h"
#include "music.h"
#include "control.h"
#include "math.h"
#include "color.h"

//=============================================================================
// DEFINITIONS
//=============================================================================

#define DEBUG_DISPLAY_INFO FALSE

// Prototypes de fonctions
void waitVSync();
void initPlayer(u8 x, u8 y);
void updatePlayer();
void activateLight(bool bActivate);
void activateElectricity(bool bActivate);
void displayLevel(u8 levelIdx);
bool onDoorAnimEnd();
bool interact(u8 x, u8 y);
void menuEnterCode();
void applyLanguage();

// Variables statiques définies dans un autre module
extern const u8 g_Font_JP[];
extern const u8 g_Font_EU[];
extern const u8 g_SprtPlayer[];
extern const u8 g_SprtElevator[];
extern const u8 g_Tiles_Patterns[];
extern const u8 g_Tiles_Colors[];

//=============================================================================
// DONNEES CONSTANTES (stockées dans le ROM)
//=============================================================================

// TODO : Faire une demande officiiiiiiiel à MSXGL pour intégrer les Constantes externe.
// #include "data/translate.h"
#include "data/translate_def.h"
#include "data/bg_tileset.h"
#include "data/sprt_elevator.h"

// Données des sprites du joueur
#include "data/sprt_player.h"
#include "data/sprt_inventory.h"

// Données des polices de character
#include "data/font_jp.h"
#include "data/font_eu.h"

// Données des musiques et SFX
#include "data/sounds/music_main.h"
#include "data/sounds/music_phone.h"
#include "data/sounds/music_empty.h"
#include "data/sounds/sfx.h"

// Données des pièces
#include "data/level/level001.h"
#include "data/level/level002.h"
#include "data/level/level003.h"
#include "data/level/level004.h"
#include "data/level/level005.h"
#include "data/level/level006.h"
#include "data/level/level007.h"
#include "data/level/level008.h"
#include "data/level/level009.h"
#include "data/level/level010.h"
#include "data/level/level011.h"
#include "data/level/level012.h"
#include "data/level/level013.h"
#include "data/level/level014.h"
#include "data/level/level015.h"
#include "data/level/level016.h"
// #include "data/level/level017.h"
// #include "data/level/level018.h"
// #include "data/level/level019.h"
// #include "data/level/level020.h"
// #include "data/level/level021.h"
// #include "data/level/level022.h"
// #include "data/level/level023.h"
// #include "data/level/level024.h"
// #include "data/level/level025.h"
// #include "data/level/level026.h"
// #include "data/level/level027.h"
// #include "data/level/level028.h"
// #include "data/level/level029.h"
// #include "data/level/level030.h"
// #include "data/level/level031.h"
// #include "data/level/level032.h"

// Test SFX
const u8 g_TestSFX[SFX_MAX] = {KEY_A, KEY_Z, KEY_E, KEY_R, KEY_T, KEY_Y, KEY_U, KEY_I, KEY_O, KEY_P};

// Liste des frames d'animation du personnage
const u8 g_PlayerFramesMove[] = {1, 2, 3, 4};
const u8 g_PlayerFramesAction[] = {5, 6, 7, 8, 9, 10, 9, 11};
const u8 g_PlayerFramesFall[] = {1, 2, 3, 4};

// Donnée d'animation des portes
const u8 g_DoorAnimationTiles[] =
{
	44, 11, 45, 95, 46, 15, // Frame 0
	44, 11, 45, 95, 46, 15, // Frame 1
	44, 47, 45, 54, 46, 55, // Frame 2
	44, 47, 45, 54, 46, 55, // Frame 3,
	44, 47, 45, 54, 46, 55, // Frame 4,
	44, 47, 45, 54, 46, 55, // Frame 5,
	44, 47, 45, 54, 46, 55, // Frame 6
};
const struct TileAnimation g_DoorAnimation =
{
	2,
	3,
	7,
	1,
	g_DoorAnimationTiles
};

// Donnée d'animation du téléphone
const u8 g_PhoneAnimationTiles[] =
{
	18, 80, // Frame 0
	18, 16, // Frame 1
	19, 80, // Frame 2
	19, 17, // Frame 3
};

const struct TileAnimation g_PhoneAnimation =
{
	1,
	2,
	4,
	0,
	g_PhoneAnimationTiles
};

// Liste des animations
const u8 *const g_MusicTable[MUSIC_MAX] = {g_AKG_MusicMain, g_AKG_MusicPhone, g_AKG_MusicEmpty};

// Palette de couleur pour le MSX2
const u16 g_CustomPalette[15] =
{
	RGB16(0, 0, 0), // 1
	RGB16(3, 2, 6), // 2
	RGB16(4, 4, 4), // 3
	RGB16(1, 1, 5), // 4
	RGB16(2, 2, 6), // 5
	RGB16(3, 3, 7), // 6
	RGB16(5, 5, 7), // 7
	RGB16(6, 3, 2), // 8
	RGB16(7, 3, 3), // 9
	RGB16(6, 6, 2), // 10
	RGB16(7, 7, 4), // 11
	RGB16(3, 1, 5), // 12
	RGB16(5, 5, 2), // 13
	RGB16(7, 6, 6), // 14
	RGB16(7, 7, 7), // 15
};

// Table de correspondance des couleurs
const u8 g_ColorIndex_MSX1[COLOR_ID_MAX] =
{
	COLOR_BLACK,		// COLOR_BACKGROUND,
	COLOR_DARK_BLUE,	// COLOR_SCENE_NIGHT_DARK,
	COLOR_DARK_BLUE,	// COLOR_PLAYER_NIGHT_DARK,
	COLOR_LIGHT_BLUE,	// COLOR_SCENE_NIGHT_MED,
	COLOR_LIGHT_BLUE,	// COLOR_PLAYER_NIGHT_MED,
	COLOR_CYAN,			// COLOR_PLAYER_NIGHT_LIGHT,
	COLOR_MEDIUM_RED,	// COLOR_PLAYER_DAY_DARK,
	COLOR_LIGHT_RED,	// COLOR_CAMERA,
	COLOR_LIGHT_RED,	// COLOR_NIGHTLIGHT_ON,
	COLOR_DARK_YELLOW,	// COLOR_SCENE_DAY_DARK,
	COLOR_LIGHT_YELLOW, // COLOR_SCENE_DAY_MED,
	COLOR_LIGHT_YELLOW, // COLOR_PLAYER_DAY_MED,
	COLOR_WHITE,		// COLOR_TEXT,
	COLOR_WHITE,		// COLOR_PLAYER_DAY_LIGHT
	COLOR_CYAN,			// COLOR_NIGHTLIGHT_OFF,
	COLOR_WHITE,		// COLOR_ELEVATOR_ON,
	COLOR_CYAN,			// COLOR_ELEVATOR_OFF,
	COLOR_GRAY,			// COLOR_TV
};

// Table de correspondance des couleurs
const u8 g_ColorIndex_MSX2[COLOR_ID_MAX] =
{
	1,	// COLOR_BACKGROUND,
	4,	// COLOR_SCENE_NIGHT_DARK,
	12, // COLOR_PLAYER_NIGHT_DARK,
	5,	// COLOR_SCENE_NIGHT_MED,
	2,	// COLOR_PLAYER_NIGHT_MED,
	7,	// COLOR_PLAYER_NIGHT_LIGHT,
	8,	// COLOR_PLAYER_DAY_DARK,
	9,	// COLOR_CAMERA,
	9,	// COLOR_NIGHTLIGHT_ON,
	10, // COLOR_SCENE_DAY_DARK,
	11, // COLOR_SCENE_DAY_MED,
	13, // COLOR_PLAYER_DAY_MED,
	15, // COLOR_TEXT,
	14, // COLOR_PLAYER_DAY_LIGHT
	6,	// COLOR_NIGHTLIGHT_OFF,
	15, // COLOR_ELEVATOR_ON,
	6,	// COLOR_ELEVATOR_OFF,
	3,	// COLOR_TV,
};

// Offset de position pour les interactions
const VectorI8 g_LeftInteractOffset[4] = {{7, 4}, {7, 12}, {-1, 4}, {-1, 12}};
const VectorI8 g_RightInteractOffset[4] = {{8, 4}, {8, 12}, {16, 4}, {16, 12}};

//=============================================================================
// VARIABLES GLOBALES (alloué en RAM)
//=============================================================================

u8 g_VersionVDP;
volatile bool g_vSync = TRUE;
bool g_isNTSC = TRUE;
u8 g_frameVSyncCounter = 0;
u8 g_frameTimeCounter = 0;
u16 g_SecondCounter = 0;

u8 g_ScreenBuffer[32 * 24]; // Buffer de l'écran (32x24 tuiles de 8x8 pixels)

// Compteur de frame pour les animations (incrémenté à chaque boucle principale ; 50/60 Hz)
u8 g_FrameCounter = 0;

// Index de la pièce courante
u8 g_CurrRoomIdx;

u8 g_SpriteBuffer1[8 * 4 * 4];
u8 g_SpriteBuffer2[8 * 4 * 4];
u8 g_SpriteCameraNum;

u8 g_SaveCodeBuffer[PLAYER_CODE_SIZE];

// Définie si la lumière est active ou non
bool g_CurrentLightOn;

// Définie si l'électricité est active ou non
bool g_CurrentElectricityOn;

// Paramètres du joueur
struct PlayerDefinition g_Player;

// Variables pour la gestion des objets visibles sous conditions (uniquement le jour ou la nuit par ex.)
u8 g_VisibleObjectCount = 0;
struct VisibleObject g_VisibleObjects[MAX_VISIBLE_OBJECTS];

// Variables pour la gestion des murs électriques (disparaissent quand plus d'électricité)
u8 g_ElectricWallCount = 0;
struct ActiveObject g_ElectricWalls[MAX_ELECTRIC_WALL];

// Variables pour la gestion des murs non électriques (disparaissent quand il y a de l'électricité)
u8 g_NotElectricWallCount = 0;
struct ActiveObject g_NotElectricWalls[MAX_NOT_ELECTRIC_WALL];

struct TVData g_TVData;

// Compte de RESET
u8 g_ResetCount = 0;
bool g_Test = FALSE;

// Switch minuteur
struct SwitchTimer g_SwitchTimer;

// Instances d'animations en cours
struct TileAnimationInstance g_AnimationInstances[MAX_TILE_ANIMATION];

struct TextCoordInstance g_TextCoordInstances[MAX_TEXT_COORD];
u8 g_TextCoordCount = 0;

// Index de la langue sélectionnée
u8 g_Language = LANG_EN;
// Table d'index des couleurs
const u8 *g_CurrentColorIdx = g_ColorIndex_MSX1;
// Current music index
u8 g_CurrentMusic = 0xFF;
u8 g_NextMusic = 0xFF;
u8 g_NextSFX = 0xFF;

//=============================================================================
// FONCTIONS
//=============================================================================

//-----------------------------------------------------------------------------
// Récupérer la couleur en fonction de son index
inline u8 getColor(u8 index)
{
	return g_CurrentColorIdx[index];
}

//-----------------------------------------------------------------------------
// Afficher un text à une position donnée
void displayTextAt(u8 x, u8 y, const c8 *text)
{
	u8 startX = x;
	while (*text != '\0')
	{
		if (*text == '\n')
		{
			x = startX;
			y++;
		}
		else
		{
			Print_DrawCharAt(x, y, *text);
			x++;
		}
		text++;
	}
}

//-----------------------------------------------------------------------------
// Ajoute une nouvelle animation de tuiles à la position indiquée
bool addAnimationInstance(u8 X, u8 Y, const struct TileAnimation *pAnimation, animCallback OnAnimationEnd)
{
	for (u8 i = 0; i < MAX_TILE_ANIMATION; ++i)
	{
		struct TileAnimationInstance *pInstance = &g_AnimationInstances[i];

		if (!pInstance->isPlaying)
		{
			pInstance->X = X;
			pInstance->Y = Y;
			pInstance->FrameNumber = 0;
			pInstance->LoopNumber = 0;
			pInstance->isPlaying = TRUE;
			pInstance->Animation = pAnimation;
			pInstance->OnAnimationEnd = OnAnimationEnd;
			return TRUE;
		}
	}

	return FALSE;
}

//-----------------------------------------------------------------------------
//
bool stopAnimationInstance(const struct TileAnimation *pAnimation)
{
	bool foundThis = FALSE;
	for (u8 i = 0; i < MAX_TILE_ANIMATION; ++i)
	{
		struct TileAnimationInstance *pInstance = &g_AnimationInstances[i];

		if (pInstance->isPlaying && pInstance->Animation == pAnimation)
		{
			foundThis = TRUE;
			Mem_Set(0, pInstance, sizeof(*pInstance));
		}
	}

	return foundThis;
}

//-----------------------------------------------------------------------------
// Met à jour toutes les animations de tuiles enregistrées
void updateTileAnimations()
{
	for (u8 i = 0; i < MAX_TILE_ANIMATION; ++i)
	{
		struct TileAnimationInstance *pInstance = &g_AnimationInstances[i];

		if (pInstance->isPlaying)
		{
			u8 size = pInstance->Animation->Width * pInstance->Animation->Height;
			u16 index = size * pInstance->FrameNumber;
			for (u8 y = 0; y < pInstance->Animation->Height; ++y)
			{
				for (u8 x = 0; x < pInstance->Animation->Width; ++x)
				{
					u8 tile = pInstance->Animation->FrameData[index++];
					setTileByTileCoord(pInstance->X + x, pInstance->Y + y, tile);
				}
			}
			pInstance->FrameNumber++;

			if (pInstance->FrameNumber >= pInstance->Animation->FrameCount)
			{

				if (pInstance->Animation->LoopCount != 0)
				{
					pInstance->LoopNumber++;
					if (pInstance->LoopNumber >= pInstance->Animation->LoopCount)
					{
						if (pInstance->OnAnimationEnd != NULL)
						{
							if (pInstance->OnAnimationEnd() == FALSE)
							{
								return;
							}
						}
						pInstance->isPlaying = FALSE;
						continue; // Stop script
					}
				}

				pInstance->FrameNumber = 0;
			}
		}
	}
}

//-----------------------------------------------------------------------------
// Chargement des données graphique en mémoire vidéo (VRAM)
void loadData()
{
	// Chargement du tileset du décor en VRAM
	Pletter_UnpackToVRAM(g_Tiles_Patterns, g_ScreenPatternLow);
	VDP_WriteVRAM_16K(g_Tiles_Colors, g_ScreenColorLow, sizeof(g_Tiles_Colors));

	// Initialisation de la font de caractère
	applyLanguage();
	// initFont();

	// Chargement des patterns de sprites de l'inventaire
	VDP_WriteVRAM_16K(g_SprtInventory, g_SpritePatternLow + 64 * 8, sizeof(g_SprtInventory));

	// Création du pattern de sprite des caméras
	VDP_Poke_16K(0x80, g_SpritePatternLow + 128 * 8);

	// Chargement des patterns de sprites des ascenseurs
	VDP_WriteVRAM_16K(g_SprtElevator, g_SpritePatternLow + 192 * 8, sizeof(g_SprtElevator));

	// Creation des 4 sprites du personnage (leur position et leur pattern seront mis-à-jour à chaque frame dans la boucle principale)
	VDP_SetSpriteSM1(SPT_PLAYER_HAIR, 0, 0, 0, 0);
	VDP_SetSpriteSM1(SPT_PLAYER_SKIN, 0, 0, 4, 0);
	VDP_SetSpriteSM1(SPT_PLAYER_CHAIR, 0, 0, 8, 0);
	VDP_SetSpriteSM1(SPT_PLAYER_OUTLINE, 0, 0, 12, getColor(COLOR_BACKGROUND));

	// Initialisation des sprites de l'inventaire
	u8 inventorySprt[4] = {64, 68, 68, 72};
	loop(i, 4)
		VDP_SetSpriteSM1(SPT_INVENTORY + i, INVENTORY_DISPLAY_X - 3 + 16 * i, VDP_SPRITE_HIDE, inventorySprt[i], getColor(COLOR_TEXT));
}

//-----------------------------------------------------------------------------
// Utilitaire pour afficher un texte à l'écran
void displayTextByMode(u8 mode)
{
	for (u8 i = 0; i < g_TextCoordCount; i++)
	{
		struct TextCoordInstance *txt = &g_TextCoordInstances[i];

		if (txt->Mode == mode)
		{
			displayTextAt(txt->X, txt->Y, Loc_GetText(txt->Key));
		}
	}
}

//.............................................................................
//
//  GESTION DU JOUEUR
//
//.............................................................................

//-----------------------------------------------------------------------------
// Initialise le personnage
void initPlayer(u8 x, u8 y)
{
	g_Player.X = x;
	g_Player.Y = y;
	g_Player.VelocityY = 0;
	g_Player.State = PLAYER_STATE_IDLE;
	g_Player.InAir = TRUE;
	g_Player.isLeft = FALSE;
	g_Player.canMove = TRUE;
}

//-----------------------------------------------------------------------------
// Gerer la fin d'un saut
void stopFalling()
{
	if (g_Player.VelocityY > 2)
		PlaySFX(SFX_LAND);

	g_Player.VelocityY = 0;
}

//-----------------------------------------------------------------------------
// Mise à jour du personnage
void updatePlayer()
{
	if (g_Player.State == PLAYER_STATE_ACTION)
	{
		if (g_FrameCounter == 2 * 8)
		{
			const VectorI8 *interactOffset = g_Player.isLeft ? g_LeftInteractOffset : g_RightInteractOffset;
			// Interaction au milieu du personnage
			g_Player.State = PLAYER_STATE_IDLE;
			loop(i, 4)
			{
				if (interact(g_Player.X + interactOffset[i].x, g_Player.Y + interactOffset[i].y))
				{
					g_Player.State = PLAYER_STATE_IDLE;
					break;
				}
			}
		}
	}
	else if (g_Test && Keyboard_IsKeyPressed(KEY_CTRL)) // Test
	{
		if (Keyboard_IsKeyPushed(KEY_SPACE))
			displayLevel(g_Rooms[g_CurrRoomIdx].NextLvlIdx);
		else if (Keyboard_IsKeyPushed(KEY_1))
			displayLevel(28);
		else if (Keyboard_IsKeyPushed(KEY_2))
			displayLevel(29);
		else if (Keyboard_IsKeyPushed(KEY_3))
			displayLevel(30);
		else if (Keyboard_IsKeyPushed(KEY_0))
			displayLevel(0);

		if (Keyboard_IsKeyPressed(KEY_LEFT))
			g_Player.X--;
		else if (Keyboard_IsKeyPressed(KEY_RIGHT))
			g_Player.X++;
		if (Keyboard_IsKeyPressed(KEY_UP))
			g_Player.Y--;
		else if (Keyboard_IsKeyPressed(KEY_DOWN))
			g_Player.Y++;

		g_Player.VelocityY = 0;

		loop(i, SFX_MAX)
		{
			if (Keyboard_IsKeyPushed(g_TestSFX[i]))
			{
				PlaySFX(i);
				break;
			}
		}
	}
	else if (g_Player.canMove)
	{

		u8 xTemp = g_Player.X; // Sauvegarde de l'ancienne position du joueur
		u8 yTemp = g_Player.Y;

		// Test des boutons de déplacement gauche/droite
		g_Player.State = PLAYER_STATE_IDLE;

		// Test des déplacements gauche/droite
		if (isInputPressed(INPUT_LEFT))
		{
			xTemp--;
			g_Player.State = PLAYER_STATE_MOVE;
			g_Player.isLeft = TRUE;
		}
		else if (isInputPressed(INPUT_RIGHT))
		{
			xTemp++;
			g_Player.State = PLAYER_STATE_MOVE;
			g_Player.isLeft = FALSE;
		}

		// Test du bouton d'interaction
		if (isInputPressed(INPUT_BUTTON_A))
		{
			g_FrameCounter = 0;
			g_Player.State = PLAYER_STATE_ACTION;
		}

		if (isInputPressed(INPUT_BUTTON_B))
		{
			g_ResetCount++;
			if (g_ResetCount > RESET_DURATION)
			{
				g_ResetCount = 0;
				displayLevel(g_CurrRoomIdx);
				return;
			}
		}
		else
		{
			g_ResetCount = 0;
		}

		// Test des collisions horizontales aux 4 coins du personnage
		bool bCollide = FALSE;
		bool bFalling = TRUE;

		// Test de collision
		if (checkCollision(xTemp, yTemp) && g_Player.isLeft)
			bCollide = TRUE;
		if (checkCollision(xTemp + 15, yTemp) && !g_Player.isLeft)
			bCollide = TRUE;
		if (checkCollision(xTemp + 15, yTemp + 15) && !g_Player.isLeft)
			bCollide = TRUE;
		if (checkCollision(xTemp, yTemp + 15) && g_Player.isLeft)
			bCollide = TRUE;

		if (checkCollision(xTemp + 8, yTemp + 16))
			bFalling = FALSE;

		if (!bCollide) // Application du déplacement si aucune collision n'est détectée
			g_Player.X = xTemp;
		else if (!bFalling) // + bCollide
			stopFalling();

		bool onElevator = FALSE;

		if (checkRails(g_Player.X + 8, g_Player.Y + 16) || checkRails(g_Player.X + 8, g_Player.Y + 8))
		{
			onElevator = isOnElevator(&g_Player.X, &g_Player.Y);

			if (onElevator)
				bFalling = FALSE;
		}

		if (onElevator)
		{
			stopFalling();
		}
		else if (bFalling)
		{
			if ((g_Player.VelocityY < 7) && ((g_FrameCounter & 0x03) == 0))
				g_Player.VelocityY++;

			g_Player.Y = yTemp + g_Player.VelocityY;
			g_Player.State = PLAYER_STATE_FALL;
		}
		else
		{
			stopFalling();
			g_Player.Y &= 0b11111000;
		}
	}

	// Tests
	// if (!g_Test && Keyboard_IsKeyPressed(MAKE_KEY(4, 4)) && Keyboard_IsKeyPressed(MAKE_KEY(0, 5)) && Keyboard_IsKeyPressed(MAKE_KEY(4, 2)))
	if (!g_Test && Keyboard_IsKeyPressed(0x44) && Keyboard_IsKeyPressed(0x50) && Keyboard_IsKeyPressed(0x24))
	{
		PlaySFX(SFX_TEST);
		g_Test = TRUE;
	}

	// Calcul de la frame d'animation à jouer en fonction de l'état du joueur
	u8 baseNumPattern = 0;
	switch (g_Player.State)
	{
	case PLAYER_STATE_IDLE:
		baseNumPattern = 0;
		break;
	case PLAYER_STATE_MOVE:
		baseNumPattern = g_PlayerFramesMove[g_FrameCounter / 4 % 4] * 16;
		break;
	case PLAYER_STATE_ACTION:
		baseNumPattern = g_PlayerFramesAction[g_FrameCounter / 2 % 8] * 16;
		break;
	case PLAYER_STATE_FALL:
		baseNumPattern = g_PlayerFramesFall[g_FrameCounter / 4 % 4] * 16;
		break;
	}

	if (g_Player.isLeft)
	{
		Mem_Copy(g_SprtPlayer + 8 * baseNumPattern, g_SpriteBuffer1, 8 * 4 * 4);
		SpriteFX_FlipHorizontal16(g_SpriteBuffer1, g_SpriteBuffer2);
		SpriteFX_FlipHorizontal16(g_SpriteBuffer1 + 32, g_SpriteBuffer2 + 32);
		SpriteFX_FlipHorizontal16(g_SpriteBuffer1 + 64, g_SpriteBuffer2 + 64);
		SpriteFX_FlipHorizontal16(g_SpriteBuffer1 + 96, g_SpriteBuffer2 + 96);
	}
	else
	{
		Mem_Copy(g_SprtPlayer + 8 * baseNumPattern, g_SpriteBuffer2, 8 * 4 * 4);
	}

	VDP_WriteVRAM_16K(g_SpriteBuffer2, g_SpritePatternLow, 8 * 4 * 4);

	//  Mise à jour de la position et du pattern des sprites du joueur (1 par couleur)
	VDP_SetSprite(SPT_PLAYER_HAIR, g_Player.X, g_Player.Y - 9, 0);
	VDP_SetSprite(SPT_PLAYER_SKIN, g_Player.X, g_Player.Y - 1, 4);
	VDP_SetSprite(SPT_PLAYER_CHAIR, g_Player.X, g_Player.Y + 7, 8);
	VDP_SetSprite(SPT_PLAYER_OUTLINE, g_Player.X, g_Player.Y - 1, 12);
}

//.............................................................................
//
//  GESTION DES ACTEURS DU DÉCOR
//
//.............................................................................

//-----------------------------------------------------------------------------
// Mise à jour des boutons d'éléctricité temporaire
void updateSwitchTimer()
{
	if (g_SwitchTimer.Timer > 0)
	{
		g_SwitchTimer.Timer--;

		if ((g_SwitchTimer.Timer & 0x07) == 0)
			PlaySFX(g_SwitchTimer.Timer & 0x08 ? SFX_TIC : SFX_TAC);

		setTile(g_SwitchTimer.X, g_SwitchTimer.Y, TILE_SWITCH_TIMER + 3 - g_SwitchTimer.Timer / 32);
		if (g_SwitchTimer.Timer == 0)
		{
			activateElectricity(FALSE);
		}
	}
}

//.............................................................................
//
//  INTERACTION GAMEPLAY
//
//.............................................................................

//-----------------------------------------------------------------------------
// Répondre au téléphone
void activatePhone(u8 xP, u8 yP, bool bPhone)
{
	if (bPhone)
	{
		StopMusic();

		// Arrêt de l'animation
		stopAnimationInstance(&g_PhoneAnimation);
		setTile(xP, yP, TILE_PHONE);
		setTile(xP, yP - 8, TILE_EMPTY);
	}
	PlaySFX(SFX_SPEAK);

	// Afficher le texte
	VDP_FillVRAM_16K(COLOR_MERGE(getColor(COLOR_TEXT), getColor(COLOR_BACKGROUND)), g_ScreenColorLow + 152 / 8, 8);

	// Déverrouillage des portes
	for (u8 y = 0; y < 24; ++y)
	{
		for (u8 x = 0; x < 32; ++x)
		{
			u8 tile = getTileByTileCoord(x, y);
			if (tile == TILE_LOCK_DOOR1)
			{
				setTileByTileCoord(x, y, TILE_DOOR1);
			}
			if (tile == TILE_LOCK_DOOR2)
			{
				setTileByTileCoord(x, y, TILE_DOOR2);
			}
		}
	}

	displayTextByMode(TEXT_MODE_PHONE);
}

//-----------------------------------------------------------------------------
// Application des effets en fonction de l'état de la lumière
void lightRoom(bool bActivate)
{
	// Change la couleur des tuiles du décor
	u8 firstCol = bActivate ? COLOR_MERGE(getColor(COLOR_SCENE_DAY_DARK), getColor(COLOR_BACKGROUND)) : COLOR_MERGE(getColor(COLOR_SCENE_NIGHT_DARK), getColor(COLOR_BACKGROUND));
	u8 secondCol = bActivate ? COLOR_MERGE(getColor(COLOR_SCENE_DAY_MED), getColor(COLOR_BACKGROUND)) : COLOR_MERGE(getColor(COLOR_SCENE_NIGHT_MED), getColor(COLOR_BACKGROUND));
	VDP_FillVRAM_16K(firstCol, g_ScreenColorLow + 0, 7);
	VDP_FillVRAM_16K(firstCol, g_ScreenColorLow + 9, 7);
	VDP_Poke_16K(bActivate ? COLOR_MERGE(getColor(COLOR_PLAYER_DAY_LIGHT), getColor(COLOR_BACKGROUND)) : COLOR_MERGE(getColor(COLOR_PLAYER_NIGHT_LIGHT), getColor(COLOR_BACKGROUND)), g_ScreenColorLow + 8);
	VDP_FillVRAM_16K(secondCol, g_ScreenColorLow + 16, 3);


	// Change la couleur du personnage
	VDP_SetSpriteColorSM1(SPT_PLAYER_HAIR, bActivate ? getColor(COLOR_PLAYER_DAY_MED) : getColor(COLOR_PLAYER_NIGHT_MED));
	VDP_SetSpriteColorSM1(SPT_PLAYER_SKIN, bActivate ? getColor(COLOR_PLAYER_DAY_LIGHT) : getColor(COLOR_PLAYER_NIGHT_LIGHT));
	VDP_SetSpriteColorSM1(SPT_PLAYER_CHAIR, bActivate ? getColor(COLOR_PLAYER_DAY_DARK) : getColor(COLOR_PLAYER_NIGHT_DARK));

	changeAllElevatorsColor(bActivate ? getColor(COLOR_ELEVATOR_ON) : getColor(COLOR_ELEVATOR_OFF));

	for (u8 i = 0; i < g_VisibleObjectCount; ++i)
	{
		struct VisibleObject *pObj = &g_VisibleObjects[i];
		u8 x = pObj->X;
		u8 y = pObj->Y;
		if (pObj->ItemCondition == ITEM_COND_LIGHT_ON)
		{
			setTileByTileCoord(x, y, bActivate ? pObj->Tile : EMPTY_ITEM);
		}
		if (pObj->ItemCondition == ITEM_COND_LIGHT_OFF)
		{
			setTileByTileCoord(x, y, bActivate ? EMPTY_ITEM : pObj->Tile);
		}
	}
}

//-----------------------------------------------------------------------------
// Allume ou éteint la lumière
void activateLight(bool bActivate)
{
	g_CurrentLightOn = bActivate; // Enregistrement de l’état de la lumière
	VDP_Poke_16K(bActivate ? COLOR_MERGE(getColor(COLOR_NIGHTLIGHT_ON), getColor(COLOR_BACKGROUND)) : COLOR_MERGE(getColor(COLOR_NIGHTLIGHT_OFF), getColor(COLOR_BACKGROUND)), g_ScreenColorLow + 7);
	if (g_CurrentElectricityOn)
		lightRoom(bActivate);
}

//-----------------------------------------------------------------------------
// Active ou désactive l'électricité
void activateElectricity(bool bActivate)
{
	g_CurrentElectricityOn = bActivate; // Enregistrement de l’état de la lumière
	lightRoom(g_CurrentLightOn && bActivate);

	for (u8 i = 0; i < g_ElectricWallCount; ++i)
	{
		struct ActiveObject *pObj = &g_ElectricWalls[i];
		u8 x = pObj->X;
		u8 y = pObj->Y;
		setTileByTileCoord(x, y, bActivate ? pObj->Tile : EMPTY_ITEM);
	}

	for (u8 i = 0; i < g_NotElectricWallCount; ++i)
	{
		struct ActiveObject *pObj = &g_NotElectricWalls[i];
		u8 x = pObj->X;
		u8 y = pObj->Y;
		setTileByTileCoord(x, y, !bActivate ? pObj->Tile : EMPTY_ITEM);
	}
}

//-----------------------------------------------------------------------------
// Ouvre les placard
void activateCupboard(u8 x, u8 y)
{
	PlaySFX(SFX_CABINET);

	u8 gX = x / 8;
	u8 gY = y / 8;
	setTileByTileCoord(gX, gY, TILE_CUPBOARD_OPEN);
	setTileByTileCoord(gX + 2, gY, TILE_CUPBOARD_OPEN + 1);

	u8 tile = TILE_EMPTY;

	for (u8 i = 0; i < g_VisibleObjectCount; ++i)
	{
		struct VisibleObject *pObj = &g_VisibleObjects[i];
		if ((pObj->X == gX + 1) && (pObj->Y == gY) && (pObj->ItemCondition == ITEM_COND_CUPBOARD))
		{
			tile = pObj->Tile;
			break;
		}

		if ((pObj->X == gX + 1) && (pObj->Y == gY) && (pObj->ItemCondition == ITEM_COND_CUPBOARD_LIGHT))
		{

			if (g_CurrentLightOn)
				tile = pObj->Tile;

			pObj->ItemCondition = ITEM_COND_LIGHT_ON;
			break;
		}
	}

	setTileByTileCoord(gX + 1, gY, tile);
}

//-----------------------------------------------------------------------------
//
void activateCloset(u8 x, u8 y)
{
	u8 gX = x / 8;
	u8 gY = y / 8;
	u8 tile = TILE_EMPTY;

	for (u8 i = 0; i < g_VisibleObjectCount; ++i)
	{
		struct VisibleObject *pObj = &g_VisibleObjects[i];
		if ((pObj->X == gX) && (pObj->Y == gY) && (pObj->ItemCondition == ITEM_COND_CUPBOARD))
		{
			tile = pObj->Tile;
			break;
		}

		if ((pObj->X == gX) && (pObj->Y == gY) && (pObj->ItemCondition == ITEM_COND_CUPBOARD_LIGHT))
		{

			if (g_CurrentLightOn)
				tile = pObj->Tile;

			pObj->ItemCondition = ITEM_COND_LIGHT_ON;
			break;
		}
	}

	setTileByTileCoord(gX, gY, tile);
}

//-----------------------------------------------------------------------------
// Ajout d'un objet conditionnel
void addConditionalItem(u8 levelIdx, u8 i, u8 j, u8 condition)
{
	if (g_VisibleObjectCount >= MAX_VISIBLE_OBJECTS)
		return;

	const struct RoomDefinition *pRoom = &g_Rooms[levelIdx];
	u8 targetItem = g_ScreenBuffer[32 * (i + 1) + j];
	struct VisibleObject *pObj = &g_VisibleObjects[g_VisibleObjectCount];
	pObj->X = j;
	pObj->Y = (i + 1);
	pObj->ItemCondition = condition;
	pObj->Tile = targetItem;
	g_VisibleObjectCount++;

	u8 x = j;
	u8 y = i;
	setTileByTileCoord(x, y, TILE_EMPTY);
}

//-----------------------------------------------------------------------------
// Ajout d'un mur électrique
void addElectricWall(u8 levelIdx, u8 i, u8 j)
{
	if (g_ElectricWallCount >= MAX_ELECTRIC_WALL)
		return;

	const struct RoomDefinition *pRoom = &g_Rooms[levelIdx];
	struct ActiveObject *pObj = &g_ElectricWalls[g_ElectricWallCount];
	pObj->X = j;
	pObj->Y = i;
	pObj->Tile = TILE_ELECTRIC_WALL;
	g_ElectricWallCount++;
}

// Ajout d'un mur non électrique
void addNotElectricWall(u8 levelIdx, u8 i, u8 j)
{
	if (g_NotElectricWallCount >= MAX_NOT_ELECTRIC_WALL)
		return;

	const struct RoomDefinition *pRoom = &g_Rooms[levelIdx];
	struct ActiveObject *pObj = &g_NotElectricWalls[g_NotElectricWallCount];
	pObj->X = j;
	pObj->Y = i;
	pObj->Tile = TILE_NOT_ELECTRIC_WALL;
	g_NotElectricWallCount++;
}

// Possibilité de regroupé avec la fonction addNotElectricWall
void addNotElectricGround(u8 levelIdx, u8 i, u8 j)
{
	if (g_NotElectricWallCount >= MAX_NOT_ELECTRIC_WALL)
		return;

	const struct RoomDefinition *pRoom = &g_Rooms[levelIdx];
	struct ActiveObject *pObj = &g_NotElectricWalls[g_NotElectricWallCount];
	pObj->X = j;
	pObj->Y = i;
	pObj->Tile = TILE_NOT_ELECTRIC_GROUND;
	g_NotElectricWallCount++;
}

//--- PORTE -------------------------------------------------------------------

void startDoorAnim(u8 x, u8 y, u8 tile)
{
	PlaySFX(SFX_DOOR);

	g_Player.canMove = FALSE;
	// Récupérer la tuile qui est 2 haut dessus
	if (tile == TILE_DOOR2 || tile == TILE_LOCK_DOOR2)
		x -= 8;
	y -= 8;

	activateDoor(tile, x, y, g_CurrRoomIdx);
	addAnimationInstance(x / 8, y / 8, &g_DoorAnimation, onDoorAnimEnd);
}

//-----------------------------------------------------------------------------
//
bool onDoorAnimEnd()
{
	g_InteractedDoor.y -= 8;

	u8 roomNumber = getTile(g_InteractedDoor.x, g_InteractedDoor.y);
	u8 doorIndex = 255;

	switch (roomNumber)
	{
	case TILE_DOOR_NUMBER_ONE:
		doorIndex = 0;
		break;

	case TILE_DOOR_NUMBER_TWO:
		doorIndex = 1;
		break;
	case TILE_DOOR_NUMBER_THREE:
		doorIndex = 2;
		break;
	}

	if (doorIndex < 255)
	{
		// Nous sommes dans une room avec téléphone.
		// On incrément le compte de doorTheme
		g_DoorThemeCount[g_DoorTheme[doorIndex]]++;
	}

	displayLevel(g_Rooms[g_InteractedDoor.currentRoom].NextLvlIdx);

	return FALSE;
}

//-----------------------------------------------------------------------------
// Réinitialise la télévision
void resetTV()
{
	g_TVData.Activate = FALSE;
	VDP_HideSprite(SPT_TV);
}

//-----------------------------------------------------------------------------
// Initialise la télévision
void initTV(u8 x, u8 y)
{
	g_TVData.X = x;
	g_TVData.Y = y;
	g_TVData.Count = 0;
	resetTV();
}

//-----------------------------------------------------------------------------
// Appuis sur le bouton de la télévision
inline void toggleTV()
{
	PlaySFX(SFX_CLICK);
	g_TVData.Activate = !g_TVData.Activate;
}

//-----------------------------------------------------------------------------
// Mise-à-jour de la télévision
void updateTV()
{
	if (g_TVData.Activate && g_CurrentElectricityOn)
	{
		VDP_SetSpriteSM1(SPT_TV, g_TVData.X * 8 + 1, g_TVData.Y * 8 - 10, 80 + (g_TVData.Count & 0x03) * 4, getColor(COLOR_TV));
		g_TVData.Count++;
	}
	else
	{
		VDP_HideSprite(SPT_TV);
	}
}

//.............................................................................
//
//  AFFICHAGE
//
//.............................................................................

//-----------------------------------------------------------------------------
// Afficher une pièce
void displayLevel(u8 levelIdx)
{
	VDP_EnableDisplay(FALSE);

	PlayMusic(MUSIC_MAIN);

	// Génération du code de sauvegarde
	struct SaveData save;
	save.currentLevel = levelIdx;
	save.currentTime = g_SecondCounter;
	save.themes[0] = g_DoorThemeCount[0];
	save.themes[1] = g_DoorThemeCount[1];
	save.themes[2] = g_DoorThemeCount[2];
	SaveEncode(&save, g_SaveCodeBuffer);

	// Who's gonna call ?
	Mem_Set(0, g_AnimationInstances, sizeof(g_AnimationInstances));

	initInventory(); // Pas possible de changer de pièce avec un objet dans les mains
	activateElectricity(TRUE);
	resetElevators();
	resetTV();

	g_CurrRoomIdx = levelIdx; // Enregistrement du numéro de la pièce
	g_VisibleObjectCount = 0;
	g_ElectricWallCount = 0;
	g_NotElectricWallCount = 0;
	u8 themeCounter = 0;
	bool fuseboxOnIsEnabled = FALSE;
	u8 fuseBoxCount = 0;
	g_SwitchTimer.Timer = 0;
	g_TextCoordCount = 0;

	// Initialisation des sprites de caméra
	g_SpriteCameraNum = 0;
	loop(i, SPT_CAMERA_MAX)
		VDP_HideSprite(SPT_CAMERA + i);


	// Initialisation des sprites de l'inventaire
	{
		u8 sprtY = ((levelIdx < 1) || (levelIdx > 27)) ? VDP_SPRITE_HIDE : SPT_INVENTORY_Y;
		loop(i, 4)
				VDP_SetSpritePositionY(SPT_INVENTORY + i, sprtY);
	}

	// Nettoyage de l'écran (tuile n°0 partout)
	VDP_FillVRAM_16K(0, g_ScreenLayoutLow, 32 * 24);

	// Décompression de la pièce dans le buffet en RAM
	const struct RoomDefinition *pRoom = &g_Rooms[levelIdx];
	const u8 *pLayout = g_ScreenBuffer;
	Pletter_Unpack(pRoom->Layout, g_ScreenBuffer);

	// Dessin de la pièce ligne par ligne
	// I = ligne, J = colonne
	for (u8 i = 0; i < 24; ++i)
	{
		// Copie une ligne de donnée en VRAM
		u16 lineIdx = 32 * i;
		VDP_WriteVRAM_16K(pLayout + lineIdx, g_ScreenLayoutLow + 32 * i, 32);

		for (u8 j = 0; j < 32; ++j)
		{
			u16 layoutIdx = lineIdx + j;
			u8 tile = pLayout[layoutIdx];
			// Positionnement du joueur centré sur la tuile trouvée
			u8 x = j;
			u8 y = i;

			if (tile == TILE_START_POS) // Detection de la position initiale du joueur
			{
				initPlayer(x * 8 - 4, y * 8 - 9);
				setTileByTileCoord(x, y, TILE_EMPTY); // Effacement de la tuile de départ
			}

			else if (tile == TILE_SPE_TRANSLATE || tile == TILE_SPE_TRANSLATE_PHONE)
			{
				u8 sX = x + 1;
				u8 sTile = getTileByTileCoord(sX, y);
				u8 transKey = 0;
				setTileByTileCoord(x, y, TILE_EMPTY);
				while (sTile != TILE_EMPTY)
				{
					setTileByTileCoord(sX, y, TILE_EMPTY);
					transKey *= 10;
					transKey += sTile - TILE_NUM_ZERO;
					sX++;
					sTile = getTileByTileCoord(sX, y);
				}
				struct TextCoordInstance *txt = &g_TextCoordInstances[g_TextCoordCount++];
				txt->X = 1; //(tile == TILE_SPE_TRANSLATE_PHONE) ? 1 : x;
				txt->Y = y;
				txt->Key = transKey;
				txt->Mode = (tile == TILE_SPE_TRANSLATE_PHONE) ? TEXT_MODE_PHONE : TEXT_MODE_DEFAULT;
			}
			else if (tile == TILE_SPE_THEME_HOSPITAL || tile == TILE_SPE_THEME_ALIEN || tile == TILE_SPE_THEME_MATRIX)
			{
				u8 theme = (tile - TILE_SPE_THEME_HOSPITAL);
				setDoorTheme(themeCounter, theme);
				setTileByTileCoord(x, y, TILE_EMPTY);
				themeCounter++;
			}
			else if (tile == TILE_SPE_LIGHT_ON || tile == TILE_SPE_LIGHT_OFF)
			{
				// Ne fonctionne que si les tuiles sont dans le même ordre que l'enum
				addConditionalItem(levelIdx, i, j, tile - TILE_SPE_LIGHT_ON + ITEM_COND_LIGHT_ON);
			}
			else if (tile == TILE_CAMERA_L || tile == TILE_CAMERA_R)
			{
				if (g_SpriteCameraNum < SPT_CAMERA_MAX - 1)
				{
					u8 sx = x * 8;
					u8 sy = y * 8;
					if (tile == TILE_CAMERA_L)
						sx += 3;
					else
						sx += 4;
					VDP_SetSpriteSM1(SPT_CAMERA + g_SpriteCameraNum, sx, sy, (u8)(128 + 4), getColor(COLOR_CAMERA));
					g_SpriteCameraNum++;
				}
			}
			else if (tile == TILE_FUSEBOX)
			{
				activateElectricity(FALSE);
				fuseBoxCount++;
			}
			else if (tile == TILE_FUSEBOX_ON)
			{
				fuseboxOnIsEnabled = TRUE;
				fuseBoxCount++;
			}
			else if (tile == TILE_ELECTRIC_WALL)
			{
				addElectricWall(levelIdx, i, j);
			}
			else if (tile == TILE_NOT_ELECTRIC_WALL)
			{
				addNotElectricWall(levelIdx, i, j);
			}
			else if (tile == TILE_NOT_ELECTRIC_GROUND)
			{
				// Même logique que les murs
				addNotElectricGround(levelIdx, i, j);
			}
			else if (tile == TILE_MANUAL_ELEVATOR)
			{
				addManualElevator(x, y);
			}
			else if ((tile == TILE_SPE_CUPBOARD) || (tile == TILE_SPE_CUPBOARD_LIGHT))
			{
				// Ne fonctionne que si les tuiles sont dans le même ordre que l'enum
				addConditionalItem(levelIdx, i, j, tile - TILE_SPE_CUPBOARD + ITEM_COND_CUPBOARD);
			}
			// Ici on reconstruit les placards
			else if (tile == TILE_CUPBOARD)
			{
				setTileByTileCoord(x + 1, y, TILE_CUPBOARD + 1);
				setTileByTileCoord(x + 1, y - 1, TILE_CUPBOARD_UPPER_PART);
			}
			else if (tile == TILE_CLOSET)
			{
				setTileByTileCoord(x + 1, y, TILE_CLOSET + 1);
				setTileByTileCoord(x + 1, y - 1, TILE_CLOSET_UPPER_PART);
			}
			else if (tile == TILE_PHONE)
			{
				addAnimationInstance(x, y - 1, &g_PhoneAnimation, NULL);
				PlayMusic(MUSIC_PHONE);
			}
			else if (tile == TILE_TV)
			{
				initTV(x, y);
			}
			if ((tile == TILE_RAILS) && canAddElevator()) // Detection des rails pour placer les élévateurs
			{
				if (pLayout[layoutIdx - 1] != TILE_RAILS) // Tile à gauche
				{
					u16 previousLineIdx = layoutIdx - 32;
					if (pLayout[previousLineIdx] != TILE_RAILS) // Tile au dessus
					{
						addElevator(x * 8, y * 8);
					}
				}
			}
		}
	}

	activateElectricity(fuseboxOnIsEnabled || fuseBoxCount == 0);

	// Initialisation de la couleur des tuiles
	activateLight(FALSE);

	hideAllElevators();

	displayTextByMode(TEXT_MODE_DEFAULT);

#if (DEBUG_DISPLAY_INFO)
	Print_SetPosition(0, 22);
	Print_DrawText("L:");
	Print_DrawInt(levelIdx);
	Print_DrawText(" E:");
	Print_DrawInt(g_DoorThemeCount[0]);
	Print_DrawChar('-');
	Print_DrawInt(g_DoorThemeCount[1]);
	Print_DrawChar('-');
	Print_DrawInt(g_DoorThemeCount[2]);
	Print_DrawText(" T:");
	Print_DrawInt(g_SecondCounter);
	Print_DrawText("    ");
#endif

	if (levelIdx == 31)
	{
		Print_SetPosition(0, 23);
		Print_DrawText("TIME ");
		u16 sec = g_SecondCounter % 60;
		u16 min = (g_SecondCounter / 60) % 60;
		u16 hour = g_SecondCounter / 60 / 60;
		Print_DrawInt(hour);
		Print_DrawChar(':');
		if (min < 10)
			Print_DrawChar('0');
		Print_DrawInt(min);
		Print_DrawChar(':');
		if (sec < 10)
			Print_DrawChar('0');
		Print_DrawInt(sec);
	}

	if (levelIdx != 0)
	{
		Print_SetPosition(19, 23);
		Print_DrawText("ROOM ");
		Print_DrawText(g_SaveCodeBuffer);
	}

	VDP_EnableDisplay(TRUE);
}

//.............................................................................
//
//  INTERACTIONS
//
//.............................................................................

//-----------------------------------------------------------------------------
// Interagit à une position donnée - en PIXELS
bool interact(u8 x, u8 y)
{
	u8 tile = getTile(x, y);

	// objet que l'on peut ajouter à l'inventaire
	if ((tile & 0b11110000) == 0b01100000)
	{
		if (addItemToInventory(tile))
		{
			switch (tile)
			{
			case TILE_ITEM_GIFT:
			case TILE_ITEM_APPLE:
				if (g_SecondCounter > BONUS_TIME)
					g_SecondCounter -= BONUS_TIME;
				else
					g_SecondCounter = 0;
				break;
			};

			setTile(x, y, TILE_EMPTY);
			for (u8 i = 0; i < g_VisibleObjectCount; ++i)
			{
				struct VisibleObject *pObj = &g_VisibleObjects[i];
				if ((pObj->X == x / 8) && (pObj->Y == y / 8))
				{
					pObj->ItemCondition = ITEM_COND_DISABLED;
				}
			}
			PlaySFX(SFX_LOOT);
			return TRUE;
		}
	}

	switch (tile)
	{
	case TILE_PC_CODE:
		PlaySFX(SFX_CLICK);
		menuEnterCode();
		return TRUE;
	// Téléphone
	case TILE_PHONE:
	case TILE_PHONE_ANIM_ONE:
	case TILE_PHONE_ANIM_TWO:
		activatePhone(x, y, true);
		return TRUE;

	case TILE_PNJ_HEAD_DOC:
	case TILE_PNJ_HEAD_NEO:
	case TILE_PNJ_HEAD_ALIEN:
		activatePhone(x, y, false);
		return TRUE;

	// Lumière allumée/éteinte
	case TILE_LIGHT1:
		PlaySFX(SFX_CLICK);
		activateLight(!g_CurrentLightOn);
		return TRUE;
	case TILE_LIGHT2:
		if (getTile(x - 8, y + 8) == TILE_CABLE)
		{
			PlaySFX(SFX_CLICK);
			activateLight(!g_CurrentLightOn);
			return TRUE;
		}
		return FALSE;

		// Scotch pour réparer les fils
	case TILE_BROKEN_CABLE:
		if (hasItemInInventory(TILE_ITEM_TAPE))
		{
			PlaySFX(SFX_CLICK);
			removeItemFromInventory(TILE_ITEM_TAPE);
			setTile(x, y, TILE_CABLE);
			return TRUE;
		}
		else
			PlaySFX(SFX_LOCK);
		return FALSE;

	// Fusible et boite à fusible
	case TILE_FUSEBOX:
		if (g_SwitchTimer.Timer > 0)
		{
			return FALSE;
		}
		if (hasItemInInventory(TILE_ITEM_FUSE))
		{
			PlaySFX(SFX_CLICK);
			removeItemFromInventory(TILE_ITEM_FUSE);
			activateElectricity(TRUE);
			setTile(x, y, TILE_FUSEBOX_ON);
			return TRUE;
		}
		else
			PlaySFX(SFX_LOCK);
		return FALSE;

	case TILE_FUSEBOX_ON:
		if (addItemToInventory(TILE_ITEM_FUSE))
		{
			PlaySFX(SFX_CLICK);
			activateElectricity(FALSE);
			setTile(x, y, TILE_FUSEBOX);
			return TRUE;
		}
		return FALSE;

	case TILE_ELEVATOR_UP:
	case TILE_ELEVATOR_DOWN:
		if (!g_CurrentElectricityOn)
		{
			return FALSE;
		}
		PlaySFX(SFX_CLICK);
		moveAllManualElevators(tile);
		return TRUE;

	case TILE_LOCK_DOOR1:
	case TILE_LOCK_DOOR2:
		if (hasItemInInventory(TILE_ITEM_KEY_DOOR))
		{
			PlaySFX(SFX_UNLOCK);
			removeItemFromInventory(TILE_ITEM_KEY_DOOR);
			startDoorAnim(x, y, tile);
			return TRUE;
		}
		else
			PlaySFX(SFX_LOCK);
		return FALSE;

	// Porte de sortie
	case TILE_DOOR1:
	case TILE_DOOR2:
		startDoorAnim(x, y, tile);
		return FALSE;

		// Porte de fin
	case TILE_DOOR_END1:
	case TILE_DOOR_END2:
		if (hasItemInInventory(TILE_ITEM_KEY_DOOR))
		{
			PlaySFX(SFX_UNLOCK);
			displayLevel(activateEndDoor());
			return TRUE;
		}
		else
			PlaySFX(SFX_LOCK);
		return FALSE;

	// Placard
	case TILE_CUPBOARD:
		activateCupboard(x, y);
		return TRUE;
	case TILE_CUPBOARD + 1:
		activateCupboard(x - 8, y);
		return TRUE;
	case TILE_CUPBOARD + 2:
		activateCupboard(x - 16, y);
		return TRUE;

	case TILE_CLOSET + 1:
		if (hasItemInInventory(TILE_ITEM_KEY_CLOSET))
		{
			PlaySFX(SFX_UNLOCK);
			removeItemFromInventory(TILE_ITEM_KEY_CLOSET);
			activateCloset(x, y);
			return TRUE;
		}
		else
			PlaySFX(SFX_LOCK);
		return FALSE;

	case TILE_SWITCH_TIMER:
	case TILE_SWITCH_TIMER + 1:
	case TILE_SWITCH_TIMER + 2:
	case TILE_SWITCH_TIMER + 3:
		if (g_CurrentElectricityOn && g_SwitchTimer.Timer == 0)
			return FALSE;

		PlaySFX(SFX_CLICK);
		g_SwitchTimer.X = x;
		g_SwitchTimer.Y = y;
		g_SwitchTimer.Timer = MAX_SWITCH_TIMER;
		activateElectricity(TRUE);
		return TRUE;
	
	case TILE_TV:
		toggleTV();
		return TRUE;
	}
	return FALSE;
}

//.............................................................................
//
// BOUCLE PRINCIPALE
//
//.............................................................................

//-----------------------------------------------------------------------------
// Application du choix d'une langue et selection de la police de caractère appropriée
void applyLanguage()
{
	// Traitement spécifique à une langue
	// Initialisation de la font de caractère
	Print_SetMode(PRINT_MODE_TEXT);
	switch (g_Language)
	{
	case LANG_JA:
		Print_SetFontEx(8, 8, 1, 1, 32, 255, g_Font_JP);
		VDP_WriteVRAM_16K(g_Font_JP, g_ScreenPatternLow + (8 * 152), 8 * 13 * 8);
		break;
	default:
		Print_SetFontEx(8, 8, 1, 1, 32, 255, g_Font_EU);
		VDP_WriteVRAM_16K(g_Font_EU, g_ScreenPatternLow + (8 * 152), 8 * 13 * 8);
		break;
	}
	Print_Initialize();
	g_PrintData.PatternOffset = 152;
	g_PrintData.CharFirst = 32;
	g_PrintData.CharLast = 255;
}

//-----------------------------------------------------------------------------
// Menu de selection d'une langue
void menuLangSelect()
{
	// Initialisation du menu
	for (u8 i = 0; i < LANG_MAX; i++)
	{
		Loc_SetLanguage(i);
		displayTextAt(LANG_CURSORX + 2, i + LANG_CURSORY, Loc_GetText(TEXT_LANG_LABEL));
	}

	// Affichage du curseur
	setTileByTileCoord(LANG_CURSORX, LANG_CURSORY + g_Language, SPT_CURSOR);

	while (1)
	{
		waitVSync();
		if (isInputPushed(INPUT_UP))
		{
			PlaySFX(SFX_TIC);
			setTileByTileCoord(LANG_CURSORX, LANG_CURSORY + g_Language, TILE_EMPTY);
			if (g_Language == 0)
				g_Language = LANG_MAX - 1;
			else
				g_Language--;

			setTileByTileCoord(LANG_CURSORX, LANG_CURSORY + g_Language, SPT_CURSOR);
		}
		else if (isInputPushed(INPUT_DOWN))
		{
			PlaySFX(SFX_TAC);
			setTileByTileCoord(LANG_CURSORX, LANG_CURSORY + g_Language, TILE_EMPTY);
			if (g_Language == LANG_MAX - 1)
				g_Language = 0;
			else
				g_Language++;

			setTileByTileCoord(LANG_CURSORX, LANG_CURSORY + g_Language, SPT_CURSOR);
		}
		else if (isInputPushed(INPUT_BUTTON_A))
		{
			PlaySFX(SFX_CLICK);
			Loc_SetLanguage(g_Language);
			break;
		}
	}

	applyLanguage();
}

//-----------------------------------------------------------------------------
// Menu de saisi d'un code de sauvegarde
void menuEnterCode()
{
	VDP_DisableSpritesFrom(0);
	Pletter_UnpackToVRAM(g_Tiles_Patterns, g_ScreenPatternLow);

	// clean screen
	VDP_FillVRAM_16K(0, g_ScreenLayoutLow, 32 * 24);
	VDP_FillVRAM_16K(COLOR_MERGE(getColor(COLOR_TEXT), getColor(COLOR_BACKGROUND)), g_ScreenColorLow, 32);

	// Initialisation du menu

	for (u8 i = 0; i < 16; i++)
	{
		Print_SetPosition(10, CODE_CURSORY + i);
		Print_DrawChar(g_CryptRoom5Map[i]);
	}
	Print_DrawTextAt(CODE_CURSORX + 6, CODE_CURSORY + CODE_VAL_OFFSET, "ROOM");

	Mem_Set(0, g_SaveCodeBuffer, PLAYER_CODE_SIZE);

	// Affichage du curseur
	u8 charIndex = 8;
	setTileByTileCoord(CODE_CURSORX, charIndex + CODE_CURSORY, SPT_CURSOR);

	u8 numDestLevel = 0;
	u8 curChar = 0;
	bool bContinue = TRUE;
	while (bContinue)
	{
		waitVSync();
		if (isInputPushed(INPUT_BUTTON_B))
		{
			PlaySFX(SFX_PHONE_PICK);
			if (curChar > 0)
			{
				g_SaveCodeBuffer[--curChar] = 0;
				Print_DrawTextAt(CODE_CURSORX + 11, CODE_CURSORY + CODE_VAL_OFFSET, (const c8 *)g_SaveCodeBuffer);
				Print_DrawChar(' ');
			}
			else
				bContinue = FALSE;
		}

		if (isInputPushed(INPUT_UP))
		{
			PlaySFX(SFX_TIC);
			setTileByTileCoord(CODE_CURSORX, charIndex + CODE_CURSORY, TILE_EMPTY);
			if (charIndex == 0)
				charIndex = 15;
			else
				charIndex--;
			setTileByTileCoord(CODE_CURSORX, charIndex + CODE_CURSORY, SPT_CURSOR);
		}
		else if (isInputPushed(INPUT_DOWN))
		{
			PlaySFX(SFX_TAC);
			setTileByTileCoord(CODE_CURSORX, charIndex + CODE_CURSORY, TILE_EMPTY);
			if (charIndex == 15)
				charIndex = 0;
			else
				charIndex++;
			setTileByTileCoord(CODE_CURSORX, charIndex + CODE_CURSORY, SPT_CURSOR);
		}
		if (isInputPushed(INPUT_BUTTON_A))
		{
			PlaySFX(SFX_CLICK);
			g_SaveCodeBuffer[curChar++] = g_CryptRoom5Map[charIndex];
			if (curChar == 8)
			{
				// Initialise la structure
				struct SaveData save;
				if (SaveDecode(g_SaveCodeBuffer, &save))
				{
					PlaySFX(SFX_UNLOCK);
					numDestLevel = save.currentLevel;
					g_SecondCounter = save.currentTime;
					g_DoorThemeCount[0] = save.themes[0];
					g_DoorThemeCount[1] = save.themes[1];
					g_DoorThemeCount[2] = save.themes[2];
				}
				else
					PlaySFX(SFX_PHONE_PICK);
				bContinue = FALSE;
			}
			Print_DrawTextAt(CODE_CURSORX + 11, CODE_CURSORY + CODE_VAL_OFFSET, (const c8 *)g_SaveCodeBuffer);
		}
	}

	applyLanguage();
	displayLevel(numDestLevel);
}

//-----------------------------------------------------------------------------
// Gestionnaire d'interruption
// Cette fonction est appelée à chaque interruption venant du processeur graphique pour signifier la fin de l'affichage du image (50 ou 60 fois par secondes).
void VDP_InterruptHandler()
{
	//@see https://aoineko.org/msxgl/index.php?title=Build_tool
	g_vSync = TRUE;

	if ((g_NextMusic != 0xFF) && (g_frameVSyncCounter != 6))
	{
		if (g_NextMusic != g_CurrentMusic)
		{
			// Load music data
			Pletter_UnpackToRAM((const void *)g_MusicTable[g_NextMusic], (void *)MUSIC_ADDRESS);
			AKG_Init((const void *)MUSIC_ADDRESS, 0);

			// Load SFX data
			Pletter_UnpackToRAM((const void *)g_AKG_SoundFX, (void *)SFX_ADDRESS);
			AKG_InitSFX((const void *)SFX_ADDRESS);

			g_CurrentMusic = g_NextMusic;
		}
		if (g_NextSFX != 0xFF)
		{
			AKG_PlaySFX(g_NextSFX, ARKOS_CHANNEL_C, 0);
			g_NextSFX = 0xFF;
		}

		AKG_Decode();
	}
}

//-----------------------------------------------------------------------------
// Bloque le programme jusqu'à la fin de l'affichage de l'image en cours
// Cela permet de synchroniser le jeu à 50 frames par seconde.
void waitVSync()
{
	while (g_vSync == FALSE)
	{
	}
	g_vSync = FALSE;

	if (g_isNTSC)
	{
		g_frameVSyncCounter++;
		if (g_frameVSyncCounter == 6)
		{
			while (g_vSync == FALSE)
			{
			}
			g_vSync = FALSE;
			g_frameVSyncCounter = 0;
		}
	}

	g_frameTimeCounter++;
	if (g_frameTimeCounter == 50)
	{
		g_frameTimeCounter = 0;
		if (g_SecondCounter < 0x4000) // 4,5 heures maximum
			g_SecondCounter++;
	}

	Keyboard_Update();
	Joystick_Update();
}

//-----------------------------------------------------------------------------
// Point d'entrée du programme principal
void main()
{
	g_isNTSC = !(g_VersionROM & 0x80);

	// Get VDP version
	if (Keyboard_IsKeyPressed(KEY_1))
		g_VersionVDP = VDP_VERSION_TMS9918A;
	else if (Keyboard_IsKeyPressed(KEY_2))
		g_VersionVDP = VDP_VERSION_V9938;
	else
		g_VersionVDP = VDP_GetVersion();

	// Initialize palette
	if (g_VersionVDP > VDP_VERSION_TMS9918A)
	{
		VDP_SetPalette((u8 *)g_CustomPalette);
		g_CurrentColorIdx = g_ColorIndex_MSX2;
	}

	// Initialisation de la table de localisation
	// Key click du MSX
	Bios_SetKeyClick(FALSE);

	// langue
	Loc_Initialize(g_TransData, TEXT_MAX);
	Loc_SetLanguage(LANG_EN);

	// Initialisation de l'affichage
	VDP_SetMode(VDP_MODE_SCREEN1);						// Mode écran 1 (32x24 tuiles de 8x8 pixels en 2 couleurs parmi 32 combinaisons)
	VDP_SetSpriteFlag(VDP_SPRITE_SIZE_16);		// Sprite de taille 16x16
	VDP_SetColor(getColor(COLOR_BACKGROUND)); // Couleur de la bordure et de la couleur 0
	VDP_ClearVRAM();
	VDP_EnableVBlank(TRUE);

	// Joue une musique vide pour permettre de jouer les sons
	PlayMusic(MUSIC_EMPTY);

	// === SAVE ===
	SaveInit();

	// 29673
	//  Chargement des données graphique en mémoire vidéo (VRAM)
	loadData();

	menuLangSelect();

	initializeDoors();

	// Initialise le joueur
	initPlayer(100, 103);

	// Affichage de la pièce n°0 (la première)
	displayLevel(0);

	while (1) // Pour un jeu en cartouche (ROM) on a pas besoin de gérer la sortie de la boucle principale
	{
		// Attente de la synchronisation avec le processeur graphique (à 50 ou 60 Hz)
		waitVSync();

		// Mise à jour des élévateurs
		if (g_FrameCounter % 4 == 0)
		{
			updateAllElevators();

			updateSwitchTimer();

			updateTileAnimations();

			updateTV();

			loop(i, g_SpriteCameraNum)
					VDP_SetSpritePattern(SPT_CAMERA + i, (g_CurrentElectricityOn && g_FrameCounter & 0b00010000) ? 128 : 128 + 4);
		}
		// Mise à jour du personnage
		updatePlayer();

		g_FrameCounter++;
	}
}