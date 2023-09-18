// ____________________________
// ██▀▀█▀▀██▀▀▀▀▀▀▀█▀▀█        │   ▄▄▄                ▄▄
// ██  ▀  █▄  ▀██▄ ▀ ▄█ ▄▀▀ █  │  ▀█▄  ▄▀██ ▄█▄█ ██▀▄ ██  ▄███
// █  █ █  ▀▀  ▄█  █  █ ▀▄█ █▄ │  ▄▄█▀ ▀▄██ ██ █ ██▀  ▀█▄ ▀█▄▄
// ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀────────┘                 ▀▀
//  Program template
// ─────────────────────────────────────────────────────────────────────────────

//=============================================================================
// INCLUDES
//=============================================================================
#include "msxgl.h"
#include "room5.h"

//=============================================================================
// DEFINITIONS
//=============================================================================

// Prototypes de fonctions
void initElevator(u8 num, u8 x, u8 y);
void updateElevator(u8 num);
void initPlayer(u8 x, u8 y);
void updatePlayer();
void initInventory();
bool addItemToInventory(u8 item);
bool hasItemInInventory(u8 item);
bool removeItemFromInventory(u8 item);
u8 getTile(u8 x, u8 y);
void setTile(u8 x, u8 y, u8 tile);
bool checkCollision(u8 x, u8 y);
bool checkRails(u8 x, u8 y);
void activateLight(bool bActivate);
void displayLevel(u8 levelIdx);
bool interact(u8 x, u8 y);

//=============================================================================
// VARIABLES GLOBALES (alloué en RAM)
//=============================================================================

// Compteur de frame
u8 g_FrameCounter = 0;

// Index de la pièce courante
u8 g_CurrRoomIdx;

// Définie si la lumière est allumée ou non
bool g_CurrentLightOn;

// Définie si l'electricité est allumée ou non
bool g_CurrentElectricityOn;

// Paramètres du joueur
struct PlayerDefinition g_Player;

// Liste des objets dans l'inventaire
u8 g_Inventory[INVENTORY_SIZE];

// Paramètres des ascenseurs
u8 g_ElevatorCount = 0;
struct ElevatorDefinition g_Elevator[MAX_ELEVATOR];

// Paramètres des objets visibles uniquement à la lumière
u8 g_VisibleObjectCount = 0;
struct VisibleObject g_VisibleObjects[MAX_VISIBLE_OBJECTS];

// Paramètres des murs éléctriques
u8 g_ElectricWallCount = 0;
struct VisibleObject g_ElectricWalls[MAX_ELECTRIC_WALL];

//=============================================================================
// DONNEES CONSTANTES (stockées dans le ROM)
//=============================================================================

// Données des sprites du joueur
#include "data/sprt_player.h"

// Données des formes et couleurs des tuiles
#include "data/bg_tileset.h"

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
#include "data/level/level017.h"
#include "data/level/level018.h"
#include "data/level/level019.h"
#include "data/level/level020.h"
#include "data/level/level021.h"
#include "data/level/level022.h"
#include "data/level/level023.h"
#include "data/level/level024.h"
#include "data/level/level025.h"
#include "data/level/level026.h"
#include "data/level/level027.h"
#include "data/level/level028.h"
#include "data/level/level029.h"
#include "data/level/level030.h"
#include "data/level/level031.h"
#include "data/level/level032.h"

// Données des sprites de l'elevateur
#include "data/sprt_elevator.h"

// Liste des pièces et de leur caracteristiques
const struct RoomDefinition g_Rooms[] = {
	{ (32 - LEVEL002_WIDTH) / 2, (24 - LEVEL002_HEIGHT) / 2, LEVEL002_WIDTH, LEVEL002_HEIGHT, g_Level002, "Room 42", 1 },
	{ (32 - LEVEL003_WIDTH) / 2, (24 - LEVEL003_HEIGHT) / 2, LEVEL003_WIDTH, LEVEL003_HEIGHT, g_Level003, "Room 1",  2 },
	{ (32 - LEVEL004_WIDTH) / 2, (24 - LEVEL004_HEIGHT) / 2, LEVEL004_WIDTH, LEVEL004_HEIGHT, g_Level004, "Room 24", 3 },
	{ (32 - LEVEL005_WIDTH) / 2, (24 - LEVEL005_HEIGHT) / 2, LEVEL005_WIDTH, LEVEL005_HEIGHT, g_Level005, "Room 35", 4 },
	{ (32 - LEVEL006_WIDTH) / 2, (24 - LEVEL006_HEIGHT) / 2, LEVEL006_WIDTH, LEVEL006_HEIGHT, g_Level006, "Room 66", 5 },
	{ (32 - LEVEL007_WIDTH) / 2, (24 - LEVEL007_HEIGHT) / 2, LEVEL007_WIDTH, LEVEL007_HEIGHT, g_Level007, "Room 57", 6 },
	{ (32 - LEVEL008_WIDTH) / 2, (24 - LEVEL008_HEIGHT) / 2, LEVEL008_WIDTH, LEVEL008_HEIGHT, g_Level008, "Room 6",  7 },
	{ (32 - LEVEL009_WIDTH) / 2, (24 - LEVEL009_HEIGHT) / 2, LEVEL009_WIDTH, LEVEL009_HEIGHT, g_Level009, "Room 18", 8 },
	{ (32 - LEVEL010_WIDTH) / 2, (24 - LEVEL010_HEIGHT) / 2, LEVEL010_WIDTH, LEVEL010_HEIGHT, g_Level010, "Room 99", 9 },
	{ (32 - LEVEL011_WIDTH) / 2, (24 - LEVEL011_HEIGHT) / 2, LEVEL011_WIDTH, LEVEL011_HEIGHT, g_Level011, "Room 3",  10 },
	{ (32 - LEVEL012_WIDTH) / 2, (24 - LEVEL012_HEIGHT) / 2, LEVEL012_WIDTH, LEVEL012_HEIGHT, g_Level012, "Room 69", 11 },
	{ (32 - LEVEL013_WIDTH) / 2, (24 - LEVEL013_HEIGHT) / 2, LEVEL013_WIDTH, LEVEL013_HEIGHT, g_Level013, "Room 7",  12 },
	{ (32 - LEVEL014_WIDTH) / 2, (24 - LEVEL014_HEIGHT) / 2, LEVEL014_WIDTH, LEVEL014_HEIGHT, g_Level014, "Room 33", 13 },
	{ (32 - LEVEL015_WIDTH) / 2, (24 - LEVEL015_HEIGHT) / 2, LEVEL015_WIDTH, LEVEL015_HEIGHT, g_Level015, "Room 51", 0 }
};

// Liste des frames d'animation du personnage
const u8 g_PlayerFramesMove[]   = { 1, 2, 3, 4 };
const u8 g_PlayerFramesAction[] = { 5, 6, 7, 8, 9, 10, 9, 11 };
const u8 g_PlayerFramesFall[]   = { 1, 2, 3, 4 };

//=============================================================================
// FONCTIONS
//=============================================================================

//-----------------------------------------------------------------------------
// Chargement des données graphique en mémoire vidéo (VRAM)
void loadData()
{
	// Chargement du tileset du décor en VRAM
	VDP_WriteVRAM_16K(g_Tiles_Patterns, g_ScreenPatternLow, sizeof(g_Tiles_Patterns));
	VDP_WriteVRAM_16K(g_Tiles_Colors, g_ScreenColorLow, sizeof(g_Tiles_Colors));

	// Initialisation de la font de caractère
	Print_SetMode(PRINT_MODE_TEXT);
	Print_SetFontEx(8, 8, 1, 1, ' ', '_', g_Tiles_Patterns + 192);
	Print_Initialize();
	g_PrintData.PatternOffset = 192;

	// Chargement des formes des sprites
	VDP_WriteVRAM_16K(g_SprtPlayer, g_SpritePatternLow, sizeof(g_SprtPlayer));
	VDP_WriteVRAM_16K(g_SprtElevator, g_SpritePatternLow + 4 * 4 * 12 * 8, sizeof(g_SprtElevator));

	// Creation des 4 sprites du personnage (leur position et leur pattern seront mis-à-jour à chaque frame dans la boucle principale)
	VDP_SetSpriteSM1(SPT_PLAYER_HAIR, 0, 0, 0, COLOR_DARK_YELLOW);
	VDP_SetSpriteSM1(SPT_PLAYER_SKIN, 0, 0, 4, COLOR_WHITE);
	VDP_SetSpriteSM1(SPT_PLAYER_CHAIR, 0, 0, 8, COLOR_DARK_RED);
	VDP_SetSpriteSM1(SPT_PLAYER_OUTLINE, 0, 0, 12, COLOR_BLACK);
}

//.............................................................................
// Gestion des tuiles
//.............................................................................

//-----------------------------------------------------------------------------
// Récupère la tuile à la position indiquée
u8 getTile(u8 x, u8 y)
{
	u8 tile = VDP_Peek_16K(g_ScreenLayoutLow + (y / 8) * 32 + (x / 8));
	return tile;
}

//-----------------------------------------------------------------------------
// Modifie la tuile à la position indiquée
void setTile(u8 x, u8 y, u8 tile)
{
	VDP_Poke_16K(tile, g_ScreenLayoutLow + (y / 8) * 32 + (x / 8));
}

//-----------------------------------------------------------------------------
// remplace la tuile à la position indiquée par une tuile vide avec les coordonnées de la tuile
void setTileByTileCoord(u8 x, u8 y, u8 tile)
{
	VDP_Poke_16K(tile, g_ScreenLayoutLow + y * 32 + x);
}

//-----------------------------------------------------------------------------
// Test la collision à la position indiquée
bool checkCollision(u8 x, u8 y)
{
	return getTile(x, y) >= 128;
}

//-----------------------------------------------------------------------------
// Test la présence d'un rail à la position indiquée
bool checkRails(u8 x, u8 y)
{
	return getTile(x, y) == TILE_RAILS; // N° de la tuile des rails
}

//.............................................................................
// Contrôle du personnage
//.............................................................................

//-----------------------------------------------------------------------------
// Test la direction "droite" dans les différents périphériques supportées 
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
// Test la direction "gauche" dans les différents périphériques supportées 
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
// Test la direction "droite" dans les différents périphériques supportées 
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

//.............................................................................
// Gestion des acteurs
//.............................................................................

//-----------------------------------------------------------------------------
// Initialise un élévateur
void initElevator(u8 num, u8 x, u8 y)
{
	struct ElevatorDefinition *elevator = &g_Elevator[num];

	elevator->X = x;
	elevator->Y = y;
	elevator->VelocityY = 1;
	elevator->State = ELEVATOR_STATE_MOVE;
	elevator->Timer = 0;

	VDP_SetSpriteSM1(SPT_ELEVATOR + num, x, y, 4 * 4 * 12, COLOR_WHITE);
}

//-----------------------------------------------------------------------------
// Mise à jour d'un élévateur
void updateElevator(u8 num)
{
	if (!g_CurrentElectricityOn) // Ignorer la mise à jour quand il n'y a pas d'électricité
		return;

	struct ElevatorDefinition *elevator = &g_Elevator[num];

	if (elevator->Timer > 0) // Attendre que le timer d'attente tombe à 0
	{
		elevator->Timer--;
		return;
	}

	if (elevator->VelocityY < 0) // Si l'élévateur monte
	{
		if (!checkRails(elevator->X, elevator->Y - 1))
		{

			elevator->VelocityY = 1;
			elevator->Timer = ELEVATOR_STAND;
			elevator->State = ELEVATOR_STATE_STAND;
			return;
		}
	}
	else // Si l'élévateur descent
	{
		if (!checkRails(elevator->X, elevator->Y + 1))
		{
			elevator->VelocityY = -1;
			elevator->Timer = ELEVATOR_STAND;
			elevator->State = ELEVATOR_STATE_STAND;
			return;
		}
	}

	// Mise à jour de la position d'un élévateur
	elevator->Y += elevator->VelocityY;

	VDP_SetSpritePosition(SPT_ELEVATOR + num, elevator->X, elevator->Y - 9);
}

//-----------------------------------------------------------------------------
// Initialise le personnage-joueur
void initPlayer(u8 x, u8 y)
{
	g_Player.X = x;
	g_Player.Y = y;
	g_Player.VelocityY = 0;
	g_Player.State = PLAYER_STATE_IDLE;
	g_Player.InAir = TRUE;
}

//-----------------------------------------------------------------------------
// Mise à jour du personnage-joueur
void updatePlayer()
{
	if (g_Player.State == PLAYER_STATE_ACTION)
	{
		if (g_FrameCounter == 2 * 8)
		{
			// Interaction au milieu du personnage
			if (interact(g_Player.X + 12, g_Player.Y + 4) || interact(g_Player.X + 12, g_Player.Y + 12))
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
		if (Keyboard_IsKeyPressed(KEY_SPACE))
		{
			displayLevel(g_Rooms[g_CurrRoomIdx].NextLvlIdx);
			while (Keyboard_IsKeyPressed(KEY_SPACE))
			{
			}
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
	else
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
		}
		else if (isMoveRight())
		{
			xTemp++;
			g_Player.State = PLAYER_STATE_MOVE;
		}

		// Test du bouton d'interaction
		if (isInteract())
		{
			g_FrameCounter = 0;
			g_Player.State = PLAYER_STATE_ACTION;
		}

		// Test des collisions horizontales aux 4 coins du personnage
		bool bCollide = FALSE;
		bool bFalling = TRUE;

		// Test de collision
		if (checkCollision(xTemp, yTemp))
			bCollide = TRUE;
		if (checkCollision(xTemp + 15, yTemp))
			bCollide = TRUE;
		if (checkCollision(xTemp + 15, yTemp + 15))
			bCollide = TRUE;
		if (checkCollision(xTemp, yTemp + 15))
			bCollide = TRUE;

		if (checkCollision(xTemp + 8, yTemp + 17))
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

			for (u8 i = 0; i < g_ElevatorCount; ++i)
			{
				if ((g_Player.X < g_Elevator[i].X - 16) || (g_Player.X > g_Elevator[i].X + 16))
					continue;

				if ((g_Player.Y + 17 > g_Elevator[i].Y) && (g_Player.Y + 17 < g_Elevator[i].Y + 8))
				{
					g_Player.Y = g_Elevator[i].Y - 16;
					bFalling = FALSE;
					onElevator = TRUE;
				}
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
			// g_Player.Y--;
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

	// Mise à jour de la position et du pattern des sprites du joueur (1 par couleur)
	VDP_SetSprite(SPT_PLAYER_HAIR, g_Player.X, g_Player.Y - 9, baseNumPattern);
	VDP_SetSprite(SPT_PLAYER_SKIN, g_Player.X, g_Player.Y - 1, baseNumPattern + 4);
	VDP_SetSprite(SPT_PLAYER_CHAIR, g_Player.X, g_Player.Y + 7, baseNumPattern + 8);
	VDP_SetSprite(SPT_PLAYER_OUTLINE, g_Player.X, g_Player.Y - 1, baseNumPattern + 12);
}

//.............................................................................
// Inventaire
//.............................................................................

//-----------------------------------------------------------------------------
// Initialise l'inventaire
void initInventory()
{
	for (u8 i = 0; i < INVENTORY_SIZE; i++)
	{
		g_Inventory[i] = EMPTY_ITEM;
	}
}

//-----------------------------------------------------------------------------
// Ajout d'un objet dans l'inventaire
bool addItemToInventory(u8 item)
{
	for (u8 i = 0; i < INVENTORY_SIZE; i++)
	{
		if (g_Inventory[i] == EMPTY_ITEM)
		{
			g_Inventory[i] = item;
			setTile(8 + i * 16, (u8)(192 - 8), item);
			return TRUE;
		}
	}
	return FALSE;
}

//-----------------------------------------------------------------------------
// Test la présence d'un objet dans l'inventaire
bool hasItemInInventory(u8 item)
{
	for (u8 i = 0; i < INVENTORY_SIZE; i++)
	{
		if (g_Inventory[i] == item)
		{
			return TRUE;
		}
	}
	return FALSE;
}

//-----------------------------------------------------------------------------
// Retire un objet de l'inventaire
bool removeItemFromInventory(u8 item)
{
	for (u8 i = 0; i < INVENTORY_SIZE; i++)
	{
		if (g_Inventory[i] == item)
		{
			g_Inventory[i] = EMPTY_ITEM;
			setTile(8 + i * 16, (u8)(192 - 8), 0);
			return TRUE;
		}
	}
	return FALSE;
}

//.............................................................................
// Gameplay
//.............................................................................

//-----------------------------------------------------------------------------
// Allume ou éteint la lumière
void activateLight(bool bActivate)
{
	if (!g_CurrentElectricityOn && bActivate) // Si il n'y a pas de courant, on ne peut pas allumer la lumière
		return;
	g_CurrentLightOn = bActivate; // Enregistrement de l’état de la lumière

	// Change la couleur des tuiles du décor
	u8 firstCol = g_CurrentLightOn ? 0xA1 : 0x41;
	u8 secondCol = g_CurrentLightOn ? 0xB1 : 0x51;
	VDP_FillVRAM_16K(firstCol, g_ScreenColorLow, 8);
	VDP_FillVRAM_16K(firstCol, g_ScreenColorLow + (64 / 8), 8);
	VDP_FillVRAM_16K(secondCol, g_ScreenColorLow + (128 / 8), 8);

	// Change la couleur du personnage
	VDP_SetSpriteColorSM1(SPT_PLAYER_HAIR, g_CurrentLightOn ? COLOR_LIGHT_YELLOW : COLOR_LIGHT_BLUE);
	VDP_SetSpriteColorSM1(SPT_PLAYER_SKIN, g_CurrentLightOn ? COLOR_WHITE : COLOR_CYAN);
	VDP_SetSpriteColorSM1(SPT_PLAYER_CHAIR, g_CurrentLightOn ? COLOR_MEDIUM_RED : COLOR_DARK_BLUE);

	// Change la couleur des élévateurs
	for (u8 i = 0; i < g_ElevatorCount; ++i)
		VDP_SetSpriteColorSM1(SPT_ELEVATOR + i, g_CurrentLightOn ? COLOR_WHITE : COLOR_CYAN);

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
// Active et désactive l'élécricité
void activateElectricity(bool bActivate)
{
	g_CurrentElectricityOn = bActivate; // Enregistrement de l’état de la lumière

	for (u8 i = 0; i < g_ElectricWallCount; ++i)
	{
		struct VisibleObject *pObj = &g_ElectricWalls[i];
		u8 x = pObj->X;
		u8 y = pObj->Y;
		setTileByTileCoord(x, y, bActivate ? pObj->Tile : EMPTY_ITEM);
	}
}

//-----------------------------------------------------------------------------
// Ajouter un objet visible uniquement dans le noir ou dans la lumière
void addConditionalItem(u8 levelIdx, u8 i, u8 j, u8 condition)
{
	if (g_VisibleObjectCount >= MAX_VISIBLE_OBJECTS)
		return;

	u8 targetItem = g_Rooms[levelIdx].Layout[g_Rooms[levelIdx].Width * (i + 1) + j];
	struct VisibleObject *pObj = &g_VisibleObjects[g_VisibleObjectCount];
	pObj->X = (g_Rooms[levelIdx].X + j);
	pObj->Y = (g_Rooms[levelIdx].Y + (i + 1));
	pObj->ItemCondition = condition;
	pObj->Tile = targetItem;
	g_VisibleObjectCount++;

	u8 x = g_Rooms[levelIdx].X + j;
	u8 y = g_Rooms[levelIdx].Y + i;
	setTileByTileCoord(x, y, TILE_EMPTY);
}

//-----------------------------------------------------------------------------
// Ajouter un mur éléctrique
void addElectricWall(u8 levelIdx, u8 i, u8 j)
{
	if (g_ElectricWallCount >= MAX_ELECTRIC_WALL)
		return;

	struct VisibleObject *pObj = &g_ElectricWalls[g_ElectricWallCount];
	pObj->X = (g_Rooms[levelIdx].X + j);
	pObj->Y = (g_Rooms[levelIdx].Y + i);
	pObj->ItemCondition = ITEM_COND_ELECTRICITY_ON;
	pObj->Tile = TILE_ELECTRIC_WALL;
	g_ElectricWallCount++;
}

//.............................................................................
// Chargement
//.............................................................................

//-----------------------------------------------------------------------------
// Afficher une pièce
void displayLevel(u8 levelIdx)
{
	initInventory();					// Pas possible de changer de pièce avec un objet dans les mains
	g_CurrRoomIdx = levelIdx; // Enregistrement du numéro de la pièce
	g_ElevatorCount = 0;			// Initialisation du nombre d'élévateurs
	activateElectricity(TRUE);
	g_VisibleObjectCount = 0;
	g_ElectricWallCount = 0;
	bool fuseboxOnIsEnabled = FALSE;
	u8 fuseBoxCount = 0;

	// Nettoyage de l'écran (tuile n°0 partout)
	VDP_FillVRAM_16K(0, g_ScreenLayoutLow, 32 * 24);

	// Dessin de la pièce ligne par ligne
	// I = ligne, J = colonne
	for (u8 i = 0; i < g_Rooms[levelIdx].Height; ++i)
	{
		// Copie une ligne de donnée en VRAM
		VDP_WriteVRAM_16K(g_Rooms[levelIdx].Layout + g_Rooms[levelIdx].Width * i,
			g_ScreenLayoutLow + 32 * (i + g_Rooms[levelIdx].Y) + (g_Rooms[levelIdx].X), g_Rooms[levelIdx].Width);

		for (u8 j = 0; j < g_Rooms[levelIdx].Width; ++j)
		{
			u8 tile = g_Rooms[levelIdx].Layout[g_Rooms[levelIdx].Width * i + j];
			if (tile == TILE_START_POS) // Detection de la position initiale du joueur
			{
				// Positionnement du joueur centré sur la tuile trouvée
				u8 x = g_Rooms[levelIdx].X + j;
				u8 y = g_Rooms[levelIdx].Y + i;

				initPlayer(x * 8 - 4, y * 8 - 9);
				setTileByTileCoord(x, y, TILE_EMPTY); // Effacement de la tuile de départ
			}
			else if (tile == TILE_SPE_LIGHT_ON)
			{
				addConditionalItem(levelIdx, i, j, ITEM_COND_LIGHT_ON);
			}
			else if (tile == TILE_SPE_LIGHT_OFF)
			{
				addConditionalItem(levelIdx, i, j, ITEM_COND_LIGHT_OFF);
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
			if ((tile == TILE_RAILS) && (g_ElevatorCount < MAX_ELEVATOR)) // Detection des rails pour placer les élévateurs
			{
				if (g_Rooms[levelIdx].Layout[g_Rooms[levelIdx].Width * i + j - 1] != TILE_RAILS)
				{
					if (g_Rooms[levelIdx].Layout[g_Rooms[levelIdx].Width * (i - 1) + j] != TILE_RAILS)
					{
						initElevator(g_ElevatorCount, (g_Rooms[levelIdx].X + j) * 8, (g_Rooms[levelIdx].Y + i) * 8);
						g_ElevatorCount++;
					}
				}
			}
		}
	}

	activateElectricity(fuseboxOnIsEnabled || fuseBoxCount == 0);

	// Initialisation de la couleur des tuiles
	activateLight(FALSE);

	for (u8 i = g_ElevatorCount; i < MAX_ELEVATOR; ++i)
	{
		VDP_HideSprite(SPT_ELEVATOR + i);
	}

	// Affichage du nom de la pièce
	Print_DrawTextAt(g_Rooms[levelIdx].X - 1, 0, g_Rooms[levelIdx].Name);
}

//.............................................................................
// Interaction
//.............................................................................

//-----------------------------------------------------------------------------
// Interagit à une position donnée
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
				if ((g_VisibleObjects[i].X == x / 8) && (g_VisibleObjects[i].Y == y / 8))
				{
					g_VisibleObjects[i].ItemCondition = ITEM_COND_DISABLED;
				}
			}
			return TRUE;
		}
	}

	switch (tile)
	{
	// Téléphone
	case TILE_PHONE:
		Print_DrawTextAt(g_Rooms[g_CurrRoomIdx].X - 1, g_Rooms[g_CurrRoomIdx].Y + g_Rooms[g_CurrRoomIdx].Height + 2, "DRIIIING !!");
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
	case TILE_BROKE_CABLE:
		if (hasItemInInventory(TILE_ITEM_TAPE))
		{
			removeItemFromInventory(TILE_ITEM_TAPE);
			setTile(x, y, TILE_CABLE);
			return TRUE;
		}
		return FALSE;

	// Fusible et boite à fusible
	case TILE_FUSEBOX:
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

	// Porte fermée
	case TILE_LOCK_DOOR1:
	case TILE_LOCK_DOOR2:
		if (hasItemInInventory(TILE_ITEM_KEY_DOOR))
		{
			removeItemFromInventory(TILE_ITEM_KEY_DOOR);
			u8 tileX = x;
			if (tile == TILE_LOCK_DOOR2)
				tileX -= 8;

			setTile(tileX, y, TILE_DOOR1);
			setTile(tileX + 8, y, TILE_DOOR2);
			return TRUE;
		}
		return FALSE;

	// Porte ouverte
	case TILE_DOOR1:
	case TILE_DOOR2:
		displayLevel(g_Rooms[g_CurrRoomIdx].NextLvlIdx);
		// TODO Animer porte qui s'ouvre et personnage qui passe
		return FALSE;
	}
	return FALSE;
}

//=============================================================================
// BOUCLE PRINCIPALE
//=============================================================================

//-----------------------------------------------------------------------------
// Point d'entrée du programme principal
void main()
{
	// Initialisation de l'affichage
	VDP_SetMode(VDP_MODE_SCREEN1);				 // Mode écran 1 (32x24 tuiles de 8x8 pixels en 2 couleurs)
	VDP_SetSpriteFlag(VDP_SPRITE_SIZE_16); // Sprite de taille 16x16
	VDP_SetColor(COLOR_BLACK);						 // Couleur de la bordure et de la couleur 0
	VDP_ClearVRAM();

	// Chargement des données graphique en mémoire vidéo (VRAM)
	loadData();

	// Initialise le joueur
	initPlayer(100, 103);

	// Affichage de la pièce n°0 (la première)
	displayLevel(0);

	while (1) // Pour un jeu en cartouche (ROM) on a pas besoin de gérer la sortie de la boucle principale
	{
		// Attente de la synchronisation avec le processeur graphique (à 50 ou 60 Hz)
		Halt();

		// Mise à jour des élévateurs
		if (g_FrameCounter % 4 == 0)
			for (u8 i = 0; i < g_ElevatorCount; ++i)
				updateElevator(i);

		// Mise à jour du personnage
		updatePlayer();

		g_FrameCounter++;
	}
}