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

//=============================================================================
// DEFINITIONS
//=============================================================================

// Prototypes de fonctions
void waitVSync();
void initPlayer(u8 x, u8 y);
void updatePlayer();
void activateLight(bool bActivate);
void activateElectricity(bool bActivate);
void displayLevel(u8 levelIdx);
bool onDoorAnimEnd();
bool interact(u8 x, u8 y);

// Variables statiques définies dans un autre module
extern const unsigned char g_AKG_MusicMain[];
extern const unsigned char g_Font_JP[];

//=============================================================================
// DONNEES CONSTANTES (stockées dans le ROM)
//=============================================================================

// Données des sprites du joueur
#include "data/sprt_player.h"

// Données des formes et couleurs des tuiles
#include "data/bg_tileset.h"

// Données des sprites de l'élévateur
#include "data/sprt_elevator.h"

// Données de traduction
#include "data/translate.h"

// Liste des frames d'animation du personnage
const u8 g_PlayerFramesMove[] = {1, 2, 3, 4};
const u8 g_PlayerFramesAction[] = {5, 6, 7, 8, 9, 10, 9, 11};
const u8 g_PlayerFramesFall[] = {1, 2, 3, 4};

// Donnée d'animation des portes
const u8 g_DoorAnimationTiles[] = {
		44, 11, 45, 71, 46, 15, // Frame 0
		44, 11, 45, 71, 46, 15, // Frame 1
		44, 47, 45, 54, 46, 55, // Frame 2
		44, 47, 45, 54, 46, 55, // Frame 3,
		44, 47, 45, 54, 46, 55, // Frame 4,
		44, 47, 45, 54, 46, 55, // Frame 5,
		44, 47, 45, 54, 46, 55, // Frame 6
};
const struct TileAnimation g_DoorAnimation = {
		2,
		3,
		7,
		1,
		g_DoorAnimationTiles};

// Donnée d'animation du téléphone
const u8 g_PhoneAnimationTiles[] = {
		18, 80, // Frame 0
		18, 16, // Frame 1
		19, 80, // Frame 2
		19, 17, // Frame 3
};
const struct TileAnimation g_PhoneAnimation = {
		1,
		2,
		4,
		0,
		g_PhoneAnimationTiles};

//=============================================================================
// VARIABLES GLOBALES (alloué en RAM)
//=============================================================================

volatile bool g_vSync = TRUE;
bool g_isNTSC = TRUE;
u8 g_frameVSyncCounter = 0;

u8 g_ScreenBuffer[32 * 24]; // Buffer de l'écran (32x24 tuiles de 8x8 pixels)

// Compteur de frame pour les animations (incrémenté à chaque boucle principale ; 50/60 Hz)
u8 g_FrameCounter = 0;

// Index de la pièce courante
u8 g_CurrRoomIdx;

u8 g_SpriteBuffer1[8 * 4 * 4];
u8 g_SpriteBuffer2[8 * 4 * 4];

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

// Compte de RESET
u8 g_ResetCount = 0;

// Switch minuteur
struct SwitchTimer g_SwitchTimer;

// Instances d'animations en cours
struct TileAnimationInstance g_AnimationInstances[MAX_TILE_ANIMATION];

struct TextCoordInstance g_TextCoordInstances[MAX_TEXT_COORD];
u8 g_TextCoordCount = 0;

// Index de la langue selecitonnée
u8 g_Language = LANG_EN;

//=============================================================================
// FONCTIONS
//=============================================================================

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
	Print_SetMode(PRINT_MODE_TEXT);
	Print_SetFontEx(8, 8, 1, 1, ' ', '_', g_Tiles_Patterns + 192);
	Print_Initialize();
	g_PrintData.PatternOffset = 192;

	// Chargement des formes des sprites
	VDP_WriteVRAM_16K(g_SprtElevator, g_SpritePatternLow + 4 * 4 * 12 * 8, sizeof(g_SprtElevator));

	// Creation des 4 sprites du personnage (leur position et leur pattern seront mis-à-jour à chaque frame dans la boucle principale)
	VDP_SetSpriteSM1(SPT_PLAYER_HAIR, 0, 0, 0, COLOR_DARK_YELLOW);
	VDP_SetSpriteSM1(SPT_PLAYER_SKIN, 0, 0, 4, COLOR_WHITE);
	VDP_SetSpriteSM1(SPT_PLAYER_CHAIR, 0, 0, 8, COLOR_DARK_RED);
	VDP_SetSpriteSM1(SPT_PLAYER_OUTLINE, 0, 0, 12, COLOR_BLACK);
}

//.............................................................................
//
//  GESTION DES CONTRÔLEURS (clavier et joysticks)
//
//.............................................................................

//-----------------------------------------------------------------------------
// Test de la direction 'droite' sur n'importe quel contrôleur
bool isMoveRight()
{
	if (Keyboard_IsKeyPressed(KEY_RIGHT))
		return TRUE;
	if ((Joystick_Read(JOY_PORT_1) & JOY_INPUT_DIR_RIGHT) == 0)
		return TRUE;
	if ((Joystick_Read(JOY_PORT_2) & JOY_INPUT_DIR_RIGHT) == 0)
		return TRUE;

	return FALSE;
}

//-----------------------------------------------------------------------------
// Test de la direction 'gauche' sur n'importe quel contrôleur
bool isMoveLeft()
{
	if (Keyboard_IsKeyPressed(KEY_LEFT))
		return TRUE;
	if ((Joystick_Read(JOY_PORT_1) & JOY_INPUT_DIR_LEFT) == 0)
		return TRUE;
	if ((Joystick_Read(JOY_PORT_2) & JOY_INPUT_DIR_LEFT) == 0)
		return TRUE;

	return FALSE;
}

//-----------------------------------------------------------------------------
// Test de l'action 'interact' sur n'importe quel contrôleur
bool isInteract()
{
	if (Keyboard_IsKeyPressed(KEY_SPACE))
		return TRUE;
	if ((Joystick_Read(JOY_PORT_1) & JOY_INPUT_TRIGGER_A) == 0)
		return TRUE;
	if ((Joystick_Read(JOY_PORT_2) & JOY_INPUT_TRIGGER_A) == 0)
		return TRUE;

	return FALSE;
}

//-----------------------------------------------------------------------------
// Test de l'action 'cancel' sur n'importe quel contrôleur
bool isCancel()
{
	if (Keyboard_IsKeyPressed(KEY_ESC))
		return TRUE;
	if ((Joystick_Read(JOY_PORT_1) & JOY_INPUT_TRIGGER_B) == 0)
		return TRUE;
	if ((Joystick_Read(JOY_PORT_2) & JOY_INPUT_TRIGGER_B) == 0)
		return TRUE;

	return FALSE;
}

// ------------------------------------------------------------------------------
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
// Mise à jour du personnage
void updatePlayer()
{
	if (g_Player.State == PLAYER_STATE_ACTION)
	{
		if (g_FrameCounter == 2 * 8)
		{
			i8 interactOffset = g_Player.isLeft ? 4 : 12;
			// Interaction au milieu du personnage
			if (interact(g_Player.X + interactOffset, g_Player.Y + 4) || interact(g_Player.X + interactOffset, g_Player.Y + 12))
			{
				g_Player.State = PLAYER_STATE_IDLE;
			}
			else
			{
				// TODO mettre animation haussement épaule
				g_Player.State = PLAYER_STATE_IDLE;
			}
		}
	}
	else if (Keyboard_IsKeyPressed(KEY_CTRL)) // Déplacement de debug (sans collision ni gravité)
	{
		if (Keyboard_IsKeyPushed(KEY_SPACE))
		{
			displayLevel(g_Rooms[g_CurrRoomIdx].NextLvlIdx);
		}

		if (Keyboard_IsKeyPressed(KEY_LEFT))
			g_Player.X--;
		else if (Keyboard_IsKeyPressed(KEY_RIGHT))
			g_Player.X++;
		if (Keyboard_IsKeyPressed(KEY_UP))
			g_Player.Y--;
		else if (Keyboard_IsKeyPressed(KEY_DOWN))
			g_Player.Y++;

		g_Player.VelocityY = 0;
	}
	else if (g_Player.canMove)
	{

		u8 xTemp = g_Player.X; // Sauvegarde de l'ancienne position du joueur
		u8 yTemp = g_Player.Y;

		// Test des boutons de déplacement gauche/droite
		g_Player.State = PLAYER_STATE_IDLE;

		// Test des déplacements gauche/droite
		if (isMoveLeft())
		{
			xTemp--;
			g_Player.State = PLAYER_STATE_MOVE;
			g_Player.isLeft = TRUE;
		}
		else if (isMoveRight())
		{
			xTemp++;
			g_Player.State = PLAYER_STATE_MOVE;
			g_Player.isLeft = FALSE;
		}

		// Test du bouton d'interaction
		if (isInteract())
		{
			g_FrameCounter = 0;
			g_Player.State = PLAYER_STATE_ACTION;
		}

		if (isCancel())
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
		{
			g_Player.X = xTemp;
			// VDP_SetColor(COLOR_BLACK);
		}
		else
		{
			g_Player.VelocityY = 0;
			// VDP_SetColor(COLOR_DARK_RED);
		}

		bool onElevator = FALSE;

		if (checkRails(g_Player.X + 8, g_Player.Y + 16) || checkRails(g_Player.X + 8, g_Player.Y + 8))
		{
			onElevator = isOnElevator(&g_Player.X, &g_Player.Y);

			if (onElevator)
			{
				bFalling = FALSE;
			}
		}

		if (onElevator)
		{
			g_Player.VelocityY = 0;
		}
		else if (bFalling)
		{
			if (g_Player.VelocityY < 8)
				g_Player.VelocityY++;

			g_Player.Y = yTemp + g_Player.VelocityY;
			g_Player.State = PLAYER_STATE_FALL;
		}
		else
		{
			g_Player.VelocityY = 0;
			g_Player.Y &= 0b11111000;
		}
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
		// Arrêt de l'animation
		stopAnimationInstance(&g_PhoneAnimation);
		setTile(xP, yP, TILE_PHONE);
		setTile(xP, yP - 8, TILE_EMPTY);
	}
	// Else = les fins

	// Afficher le texte
	VDP_FillVRAM_16K((u8)(COLOR_WHITE << 4), g_ScreenColorLow + 152 / 8, 8);

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
	u8 firstCol = bActivate ? 0xA1 : 0x41;
	u8 secondCol = bActivate ? 0xB1 : 0x51;
	VDP_FillVRAM_16K(firstCol, g_ScreenColorLow, 7);
	VDP_FillVRAM_16K(firstCol, g_ScreenColorLow + (64 / 8), 8);
	VDP_FillVRAM_16K(secondCol, g_ScreenColorLow + (128 / 8), 3);
	// ancienne méthode pour modifier la couleurs des élévateurs manuels
	// VDP_FillVRAM_16K(bActivate ? 0xf1 : 0x71, g_ScreenColorLow + (184 / 8), 1);

	// Change la couleur du personnage
	VDP_SetSpriteColorSM1(SPT_PLAYER_HAIR, bActivate ? COLOR_LIGHT_YELLOW : COLOR_LIGHT_BLUE);
	VDP_SetSpriteColorSM1(SPT_PLAYER_SKIN, bActivate ? COLOR_WHITE : COLOR_CYAN);
	VDP_SetSpriteColorSM1(SPT_PLAYER_CHAIR, bActivate ? COLOR_MEDIUM_RED : COLOR_DARK_BLUE);

	changeAllElevatorsColor(bActivate ? COLOR_WHITE : COLOR_CYAN);

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
	VDP_Poke_16K(bActivate ? COLOR_LIGHT_RED << 4 : COLOR_CYAN << 4, g_ScreenColorLow + 7);
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

// Ouvre les placard

void activateCupboard(u8 x, u8 y)
{
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
	u8 targetItem = g_ScreenBuffer[pRoom->Width * (i + 1) + j];
	struct VisibleObject *pObj = &g_VisibleObjects[g_VisibleObjectCount];
	pObj->X = (pRoom->X + j);
	pObj->Y = (pRoom->Y + (i + 1));
	pObj->ItemCondition = condition;
	pObj->Tile = targetItem;
	g_VisibleObjectCount++;

	u8 x = pRoom->X + j;
	u8 y = pRoom->Y + i;
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
	pObj->X = (pRoom->X + j);
	pObj->Y = (pRoom->Y + i);
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
	pObj->X = (pRoom->X + j);
	pObj->Y = (pRoom->Y + i);
	pObj->Tile = TILE_NOT_ELECTRIC_WALL;
	g_NotElectricWallCount++;
}

//--- PORTE -------------------------------------------------------------------

void startDoorAnim(u8 x, u8 y, u8 tile)
{
	g_Player.canMove = FALSE;
	// Récupérer la tuile qui est 2 haut dessus
	if (tile == TILE_DOOR2 || tile == TILE_LOCK_DOOR2)
		x -= 8;
	y -= 8;

	activateDoor(tile, x, y, g_CurrRoomIdx);
	addAnimationInstance(x / 8, y / 8, &g_DoorAnimation, onDoorAnimEnd);
}

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

//.............................................................................
//
//  AFFICHAGE
//
//.............................................................................

//-----------------------------------------------------------------------------
// Afficher une pièce
void displayLevel(u8 levelIdx)
{

	// Who's gonna call ?
	Mem_Set(0, g_AnimationInstances, sizeof(g_AnimationInstances));

	initInventory(); // Pas possible de changer de pièce avec un objet dans les mains
	activateElectricity(TRUE);
	resetElevators();

	g_CurrRoomIdx = levelIdx; // Enregistrement du numéro de la pièce
	g_VisibleObjectCount = 0;
	g_ElectricWallCount = 0;
	g_NotElectricWallCount = 0;
	u8 themeCounter = 0;
	bool fuseboxOnIsEnabled = FALSE;
	u8 fuseBoxCount = 0;
	g_SwitchTimer.Timer = 0;
	g_TextCoordCount = 0;

	// Nettoyage de l'écran (tuile n°0 partout)
	VDP_FillVRAM_16K(0, g_ScreenLayoutLow, 32 * 24);

	const struct RoomDefinition *pRoom = &g_Rooms[levelIdx];
	const u8 *pLayout = g_ScreenBuffer;

	// Décompresse
	Pletter_Unpack(pRoom->Layout, g_ScreenBuffer);

	// Dessin de la pièce ligne par ligne
	// I = ligne, J = colonne
	for (u8 i = 0; i < pRoom->Height; ++i)
	{
		// Copie une ligne de donnée en VRAM
		u16 lineIdx = pRoom->Width * i;
		VDP_WriteVRAM_16K(pLayout + lineIdx,
											g_ScreenLayoutLow + 32 * (i + pRoom->Y) + (pRoom->X), pRoom->Width);

		for (u8 j = 0; j < pRoom->Width; ++j)
		{
			u16 layoutIdx = lineIdx + j;
			u8 tile = pLayout[layoutIdx];
			// Positionnement du joueur centré sur la tuile trouvée
			u8 x = pRoom->X + j;
			u8 y = pRoom->Y + i;

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
				txt->X = x;
				txt->Y = y;
				txt->Key = transKey;
				txt->Mode = tile == TILE_SPE_TRANSLATE_PHONE ? TEXT_MODE_PHONE : TEXT_MODE_DEFAULT;
			}
			else if (tile == TILE_SPE_THEME_HOSPITAL ||
							 tile == TILE_SPE_THEME_ALIEN ||
							 tile == TILE_SPE_THEME_MATRIX)
			{
				u8 theme = (tile - TILE_SPE_THEME_HOSPITAL);
				setDoorTheme(themeCounter, theme);
				setTileByTileCoord(x, y, TILE_EMPTY);
				themeCounter++;
			}
			else if (tile == TILE_SPE_LIGHT_ON ||
							 tile == TILE_SPE_LIGHT_OFF)
			{
				// Ne fonctionne que si les tuiles sont dans le même ordre que l'enum
				addConditionalItem(levelIdx, i, j, tile - TILE_SPE_LIGHT_ON + ITEM_COND_LIGHT_ON);
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
			else if (tile == TILE_MANUAL_ELEVATOR)
			{
				addManualElevator(x, y);
			}
			else if (tile == TILE_SPE_CUPBOARD ||
							 tile == TILE_SPE_CUPBOARD_LIGHT)
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
			}
			if ((tile == TILE_RAILS) && canAddElevator()) // Detection des rails pour placer les élévateurs
			{
				if (pLayout[layoutIdx - 1] != TILE_RAILS) // Tile à gauche
				{
					u16 previousLineIdx = layoutIdx - pRoom->Width;
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

	/*
	Ceci est tout à fait normal, nous avons besoin de régulièrement tester les thèmes

	Print_SetPosition(0, 23);
	Print_DrawFormat("TEST %i, %i, %i / %i, %i, %i", g_DoorThemeCount[0], g_DoorThemeCount[1], g_DoorThemeCount[2], g_DoorTheme[0], g_DoorTheme[1], g_DoorTheme[2]);
	*/
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
			setTile(x, y, TILE_EMPTY);
			for (u8 i = 0; i < g_VisibleObjectCount; ++i)
			{
				struct VisibleObject *pObj = &g_VisibleObjects[i];
				if ((pObj->X == x / 8) && (pObj->Y == y / 8))
				{
					pObj->ItemCondition = ITEM_COND_DISABLED;
				}
			}
			return TRUE;
		}
	}

	switch (tile)
	{
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
		activateLight(!g_CurrentLightOn);
		return TRUE;
	case TILE_LIGHT2:
		if (getTile(x - 8, y + 8) == TILE_CABLE)
		{
			activateLight(!g_CurrentLightOn);
			return TRUE;
		}
		return FALSE;

		// Scotch pour réparer les fils
	case TILE_BROKEN_CABLE:
		if (hasItemInInventory(TILE_ITEM_TAPE))
		{
			removeItemFromInventory(TILE_ITEM_TAPE);
			setTile(x, y, TILE_CABLE);
			return TRUE;
		}
		return FALSE;

	// Fusible et boite à fusible
	case TILE_FUSEBOX:
		if (g_SwitchTimer.Timer > 0)
		{
			return FALSE;
		}
		if (hasItemInInventory(TILE_ITEM_FUSE))
		{
			removeItemFromInventory(TILE_ITEM_FUSE);
			activateElectricity(TRUE);

			setTile(x, y, TILE_FUSEBOX_ON);
			return TRUE;
		}
		return FALSE;

	case TILE_FUSEBOX_ON:
		if (addItemToInventory(TILE_ITEM_FUSE))
		{
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
		moveAllManualElevators(tile);
		return TRUE;

	case TILE_LOCK_DOOR1:
	case TILE_LOCK_DOOR2:
		if (hasItemInInventory(TILE_ITEM_KEY_DOOR))
		{
			removeItemFromInventory(TILE_ITEM_KEY_DOOR);
			startDoorAnim(x, y, tile);
			return TRUE;
		}
		return FALSE;

	// Porte de sortie
	case TILE_DOOR1:
	case TILE_DOOR2:
		startDoorAnim(x, y, tile);
		return FALSE;

		// Porte de fin
	case TILE_DOOR_END1:
	case TILE_DOOR_END2:
		displayLevel(activateEndDoor());
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
			removeItemFromInventory(TILE_ITEM_KEY_CLOSET);
			activateCloset(x, y);
			return TRUE;
		}
		return FALSE;

	case TILE_SWITCH_TIMER:
	case TILE_SWITCH_TIMER + 1:
	case TILE_SWITCH_TIMER + 2:
	case TILE_SWITCH_TIMER + 3:
		if (g_CurrentElectricityOn && g_SwitchTimer.Timer == 0)
		{
			return FALSE;
		}

		g_SwitchTimer.X = x;
		g_SwitchTimer.Y = y;
		g_SwitchTimer.Timer = MAX_SWITCH_TIMER;
		activateElectricity(TRUE);
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
// Menu de langue
void langMenu()
{
	// Initialisation du menu
	for (u8 i = 0; i < LANG_MAX; i++)
	{
		Loc_SetLanguage(i);
		displayTextAt(12, i + 10, Loc_GetText(TEXT_LANG_LABEL));
	}

	// Affichage du curseur
	setTileByTileCoord(LANG_CURSORX, LANG_CURSORY + g_Language, SPT_CURSOR);

	while (1)
	{
		waitVSync();
		Keyboard_Update();
		if (Keyboard_IsKeyPushed(KEY_UP))
		{
			setTileByTileCoord(LANG_CURSORX, LANG_CURSORY + g_Language, TILE_EMPTY);
			if (g_Language == 0)
			{
				g_Language = LANG_MAX - 1;
			}
			else
			{
				g_Language--;
			}

			setTileByTileCoord(LANG_CURSORX, LANG_CURSORY + g_Language, SPT_CURSOR);
		}
		else if (Keyboard_IsKeyPushed(KEY_DOWN))
		{
			setTileByTileCoord(LANG_CURSORX, LANG_CURSORY + g_Language, TILE_EMPTY);
			if (g_Language == LANG_MAX - 1)
			{
				g_Language = 0;
			}
			else
			{
				g_Language++;
			}

			setTileByTileCoord(LANG_CURSORX, LANG_CURSORY + g_Language, SPT_CURSOR);
		}
		else if (Keyboard_IsKeyPushed(KEY_ENTER) || Keyboard_IsKeyPushed(KEY_SPACE))
		{
			Loc_SetLanguage(g_Language);
			break;
		}
	}

	// Traitement spécifique à une langue
	switch (g_Language)
	{
	case LANG_JA:
		VDP_WriteVRAM_16K(g_Font_JP, g_ScreenPatternLow + (8 * 152), 8 * 13 * 8);
		g_PrintData.PatternOffset = 152;
		g_PrintData.CharFirst = 32;
		g_PrintData.CharLast = 255;
		break;
	}
}

//-----------------------------------------------------------------------------
// Gestionnaire d'interruption
// Cette fonction est appelée à chaque interruption venant du processeur graphique pour signifier la fin de l'affichage du image (50 ou 60 fois par secondes).
void VDP_InterruptHandler()
{
	//@see https://aoineko.org/msxgl/index.php?title=Build_tool
	g_vSync = TRUE;
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
}

// Point d'entrée du programme principal
void main()
{
	g_isNTSC = !(g_VersionROM & 0x80);

	// Initialisation de la table de localisation
	// Key click du MSX
	Bios_SetKeyClick(FALSE);

	// langue
	Loc_Initialize(g_TransData, TEXT_MAX);
	Loc_SetLanguage(LANG_EN);

	// Initialisation de l'affichage
	VDP_SetMode(VDP_MODE_SCREEN1);				 // Mode écran 1 (32x24 tuiles de 8x8 pixels en 2 couleurs parmi 32 combinaisons)
	VDP_SetSpriteFlag(VDP_SPRITE_SIZE_16); // Sprite de taille 16x16
	VDP_SetColor(COLOR_BLACK);						 // Couleur de la bordure et de la couleur 0
	VDP_ClearVRAM();

	// === MUSIQUE ===

	Pletter_UnpackToRAM(g_AKG_MusicMain, MUSIC_ADDRESS);
	AKG_Init(MUSIC_ADDRESS, 0);

	// 29673
	//  Chargement des données graphique en mémoire vidéo (VRAM)
	loadData();

	langMenu();

	initializeDoors();

	// Initialise le joueur
	initPlayer(100, 103);

	// Affichage de la pièce n°0 (la première)
	displayLevel(0);

	while (1) // Pour un jeu en cartouche (ROM) on a pas besoin de gérer la sortie de la boucle principale
	{
		// Attente de la synchronisation avec le processeur graphique (à 50 ou 60 Hz)
		waitVSync();

		// COMPRESSER prochain live
		// --- SON
		AKG_Decode();

		// Mise à jour des élévateurs
		if (g_FrameCounter % 4 == 0)
		{
			if (g_CurrentElectricityOn)
			{
				updateAllElevators();
			}

			updateSwitchTimer();

			updateTileAnimations();
		}
		// Mise à jour du personnage
		Keyboard_Update();
		updatePlayer();

		g_FrameCounter++;
	}
}