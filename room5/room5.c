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

// Structure de description d'une pièce
struct RoomDefinition
{
  u8 X;
  u8 Y;
  u8 Width;
  u8 Height;
  const u8 *Layout;
  const c8 *Name;
  u8 NextLvlIdx;
};

// Structure des paramètres du joueur
struct PlayerDefinition
{
  u8 X;
  u8 Y;
};

enum PlayerState
{
  PLAYER_STATE_IDLE,
  PLAYER_STATE_MOVE,
  PLAYER_STATE_ACTION
};

//=============================================================================
// VARIABLES GLOBALES (alloué en RAM)
//=============================================================================

// Index de la pièce courante
u8 g_CurrRoomIdx;
// Définie si la lumière est allumée ou non
bool g_CurrentLightOn;
// Paramètres du joueur
struct PlayerDefinition g_Player;

u8 g_PlayerState = PLAYER_STATE_IDLE;

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

// Données des sprites de l'elevateur
#include "data/sprt_elevator.h"

// Liste des pièces et de leur caracteristiques
const struct RoomDefinition g_Rooms[] = {
    {(32 - LEVEL001_WIDTH) / 2, (24 - LEVEL001_HEIGHT) / 2, LEVEL001_WIDTH, LEVEL001_HEIGHT, g_Level001, "Room 1", 1},
    {(32 - LEVEL002_WIDTH) / 2, (24 - LEVEL002_HEIGHT) / 2, LEVEL002_WIDTH, LEVEL002_HEIGHT, g_Level002, "Room 42", 2},
    {(32 - LEVEL003_WIDTH) / 2, (24 - LEVEL003_HEIGHT) / 2, LEVEL003_WIDTH, LEVEL003_HEIGHT, g_Level003, "Room 2", 3},
    {(32 - LEVEL004_WIDTH) / 2, (24 - LEVEL004_HEIGHT) / 2, LEVEL004_WIDTH, LEVEL004_HEIGHT, g_Level004, "Room 66", 0},
};

const u8 g_NumPlayerFramesMove[] = {1, 2, 3, 4};
const u8 g_NumPlayerFramesAction[] = {5, 6, 7, 8, 9, 10, 9, 11};

//=============================================================================
// FONCTIONS
//=============================================================================

//-----------------------------------------------------------------------------
// Récupère la tuile à la position indiquée
void activateLight(bool bActivate)
{
  g_CurrentLightOn = bActivate;

  u8 firstCol = g_CurrentLightOn ? 0xA1 : 0x41;
  u8 secondCol = g_CurrentLightOn ? 0xB1 : 0x51;
  VDP_FillVRAM_16K(firstCol, g_ScreenColorLow, 8);
  VDP_FillVRAM_16K(firstCol, g_ScreenColorLow + (64 / 8), 8);
  VDP_FillVRAM_16K(secondCol, g_ScreenColorLow + (128 / 8), 8);

  VDP_SetSpriteColorSM1(0, g_CurrentLightOn ? COLOR_LIGHT_YELLOW : COLOR_LIGHT_BLUE);
  VDP_SetSpriteColorSM1(1, g_CurrentLightOn ? COLOR_WHITE : COLOR_CYAN);
  VDP_SetSpriteColorSM1(2, g_CurrentLightOn ? COLOR_MEDIUM_RED : COLOR_DARK_BLUE);
}

//-----------------------------------------------------------------------------
// Afficher une pièce
void displayLevel(u8 levelIdx)
{
  // Nettoyage de l'écran (tuile n°0 partout)
  g_CurrRoomIdx = levelIdx;
  // Nettoyage de l'écran (tuile n°0 partout)
  VDP_FillVRAM_16K(0, g_ScreenLayoutLow, 32 * 24);

  // Dessiner la pièce ligne par ligne
  for (u8 i = 0; i < g_Rooms[levelIdx].Height; ++i)
  {
    VDP_WriteVRAM_16K(g_Rooms[levelIdx].Layout + g_Rooms[levelIdx].Width * i,
                      g_ScreenLayoutLow + 32 * (i + g_Rooms[levelIdx].Y) + (g_Rooms[levelIdx].X), g_Rooms[levelIdx].Width);

    for (u8 j = 0; j < g_Rooms[levelIdx].Width; ++j)
    {
      u8 tile = g_Rooms[levelIdx].Layout[g_Rooms[levelIdx].Width * i + j];
      if (tile == 63) // Detection de la position initiale du joueur
      {
        // Positionnement du joueur centré sur la tuile trouvée
        g_Player.X = (g_Rooms[levelIdx].X + j) * 8 - 4;
        g_Player.Y = (g_Rooms[levelIdx].Y + i) * 8 - 9;
      }
    }
  }

  // Intialisation de la couleur des tuiles
  activateLight(FALSE);

  // Afficher le nom de la pièce
  Print_DrawTextAt(g_Rooms[levelIdx].X - 1, 0, g_Rooms[levelIdx].Name);
}

//-----------------------------------------------------------------------------
// Récupère la tuile à la position indiquée
u8 getTile(u8 x, u8 y)
{
  u8 tile = VDP_Peek_16K(g_ScreenLayoutLow + (y / 8) * 32 + (x / 8));
  return tile;
}

//-----------------------------------------------------------------------------
// Interagit à une position donnée
bool interact(u8 x, u8 y)
{
  u8 tile = getTile(x, y);
  switch (tile)
  {
  // Telephone
  case 73:
    Print_DrawTextAt(g_Rooms[g_CurrRoomIdx].X - 1, g_Rooms[g_CurrRoomIdx].Y + g_Rooms[g_CurrRoomIdx].Height + 2, "DRIIIING !!");
    return TRUE;
  // Light ON/OFF
  case 74:
  case 76:
    activateLight(!g_CurrentLightOn);
    return TRUE;
  // Open door
  case 12:
  case 13:
    displayLevel(g_Rooms[g_CurrRoomIdx].NextLvlIdx);
    // TODO Animer porte qui s'ouvre et personnage qui passe
    return FALSE;
  }
  return FALSE;
}

//-----------------------------------------------------------------------------
// Point d'entrée du programme principal
bool checkCollision(u8 x, u8 y)
{
  return getTile(x, y) >= 128;
}

//=============================================================================
// BOUCLE PRINCIPALE
//=============================================================================

//-----------------------------------------------------------------------------
// Point d'entrée du programme principal
void main()
{
  // Initialisation de l'affichage
  VDP_SetMode(VDP_MODE_SCREEN1);
  VDP_SetSpriteFlag(VDP_SPRITE_SIZE_16);
  VDP_ClearVRAM();
  VDP_SetColor(COLOR_BLACK);

  // Chargement du tileset en VRAM
  VDP_WriteVRAM_16K(g_Tiles_Patterns, g_ScreenPatternLow, sizeof(g_Tiles_Patterns));
  VDP_WriteVRAM_16K(g_Tiles_Colors, g_ScreenColorLow, sizeof(g_Tiles_Colors));
  // Initialisation de la font de caractère
  Print_SetMode(PRINT_MODE_TEXT);
  Print_SetFontEx(8, 8, 1, 1, ' ', '_', g_Tiles_Patterns + 192);
  Print_Initialize();
  g_PrintData.PatternOffset = 192;

  // Initialisation du joueur
  g_Player.X = 100;
  g_Player.Y = 103;
  // Chargement des formes des sprites
  VDP_WriteVRAM_16K(g_SprtPlayer, g_SpritePatternLow, sizeof(g_SprtPlayer));
  // Creation des 4 sprites du personnage
  VDP_SetSpriteSM1(0, g_Player.X, g_Player.Y, 0, COLOR_DARK_YELLOW);
  VDP_SetSpriteSM1(1, g_Player.X, g_Player.Y, 4, COLOR_WHITE);
  VDP_SetSpriteSM1(2, g_Player.X, g_Player.Y, 8, COLOR_DARK_RED);
  VDP_SetSpriteSM1(3, g_Player.X, g_Player.Y, 12, COLOR_BLACK);

  // Afficher la pièce n°0 (la première)
  displayLevel(0);

  u8 count = 0;

  while (1)
  {
    // Attente de la synchronsation avec le processeur graphique (à 50 ou 60 Hz)
    Halt();

    count++;

    u8 xTemp = g_Player.X;
    u8 yTemp = g_Player.Y;

    if (g_PlayerState == PLAYER_STATE_ACTION)
    {
      if (count == 4 * 8)
      {
        g_PlayerState = PLAYER_STATE_IDLE;
        count = 0;
      }
    }
    else
    {

      // MOVES
      g_PlayerState = PLAYER_STATE_IDLE;
      if (Keyboard_IsKeyPressed(KEY_LEFT))
      {
        xTemp--;
        g_PlayerState = PLAYER_STATE_MOVE;
      }
      if (Keyboard_IsKeyPressed(KEY_RIGHT))
      {
        xTemp++;
        g_PlayerState = PLAYER_STATE_MOVE;
      }

      // ACTION
      if (Keyboard_IsKeyPressed(KEY_SPACE))
      {
        // Interaction au milieu du personnage
        if (interact(g_Player.X + 8, g_Player.Y + 4))
        {
          count = 0;
          g_PlayerState = PLAYER_STATE_ACTION;
        }
        else
        {
          // TODO mettre animation haussement épaule
        }
      }
    }

    bool bCollide = false;
    if (checkCollision(xTemp, yTemp))
      bCollide = true;
    if (checkCollision(xTemp + 15, yTemp))
      bCollide = true;
    if (checkCollision(xTemp + 15, yTemp + 15))
      bCollide = true;
    if (checkCollision(xTemp, yTemp + 15))
      bCollide = true;

    if (!bCollide)
    {
      g_Player.X = xTemp;
      VDP_SetColor(COLOR_BLACK);
    }
    else
    {
      VDP_SetColor(COLOR_DARK_RED);
    }

    u8 baseNumPattern = 0;

    switch (g_PlayerState)
    {
    case PLAYER_STATE_IDLE:
      baseNumPattern = 0;
      break;
    case PLAYER_STATE_MOVE:
      baseNumPattern = g_NumPlayerFramesMove[count / 4 % 4] * 16;
      break;
    case PLAYER_STATE_ACTION:
      baseNumPattern = g_NumPlayerFramesAction[count / 4 % 8] * 16;
      break;
    }

    // Mise à jour des sprites du joueur (1 par couleur)
    VDP_SetSpritePattern(0, baseNumPattern);
    VDP_SetSpritePattern(1, baseNumPattern + 4);
    VDP_SetSpritePattern(2, baseNumPattern + 8);
    VDP_SetSpritePattern(3, baseNumPattern + 12);
    VDP_SetSpritePosition(0, g_Player.X, g_Player.Y);
    VDP_SetSpritePosition(1, g_Player.X, g_Player.Y);
    VDP_SetSpritePosition(2, g_Player.X, g_Player.Y);
    VDP_SetSpritePosition(3, g_Player.X, g_Player.Y);
  }
}