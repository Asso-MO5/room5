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
// DEFINES
//=============================================================================

// Library's logo
#define MSX_GL "\x01\x02\x03\x04\x05\x06"
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

struct PlayerDefinition
{
  u8 X;
  u8 Y;
};
//=============================================================================
// GLOBAL VARIABLES (tout dans la RAM)
//=============================================================================

u8 g_CurrRoomIdx;
bool g_CurrentLightOn;
struct PlayerDefinition g_Player;
//=============================================================================
// READ-ONLY DATA
//=============================================================================

// Fonts data
#include "tilesets/tileset.h"
#include "sprites/player.h"
#include "aseprites/export/level001.h"
#include "aseprites/export/level002.h"

// Animation characters
const u8 g_ChrAnim[] = {'-', '/', '|', '\\'};

const struct RoomDefinition g_Rooms[] = {
    {(32 - LEVEL001_WIDTH) / 2, (24 - LEVEL001_HEIGHT) / 2, LEVEL001_WIDTH, LEVEL001_HEIGHT, g_Level001, "Room 1", 1},
    {(32 - LEVEL002_WIDTH) / 2, (24 - LEVEL002_HEIGHT) / 2, LEVEL002_WIDTH, LEVEL002_HEIGHT, g_Level002, "Room 2", 0},
};

//=============================================================================
// MAIN LOOP
//=============================================================================

//-----------------------------------------------------------------------------
/// Program entry point

void displayLevel(u8 levelIdx)
{
  g_CurrRoomIdx = levelIdx;
  VDP_FillVRAM_16K(0, g_ScreenLayoutLow, 32 * 24);

  for (u8 i = 0; i < g_Rooms[levelIdx].Height; i++)
  {
    VDP_WriteVRAM_16K(g_Rooms[levelIdx].Layout + g_Rooms[levelIdx].Width * i,
                      g_ScreenLayoutLow + 32 * (i + g_Rooms[levelIdx].Y) + (g_Rooms[levelIdx].X), g_Rooms[levelIdx].Width);

    for (u8 j = 0; j < g_Rooms[levelIdx].Width; j++)
    {
      u8 tile = g_Rooms[levelIdx].Layout[g_Rooms[levelIdx].Width * i + j];
      if (tile == 63)
      {
        // half tile
        g_Player.X = (g_Rooms[levelIdx].X + j) * 8 - 4;
        g_Player.Y = (g_Rooms[levelIdx].Y + i) * 8 - 9;
      }
    }
  }

  VDP_FillVRAM_16K(0x41, g_ScreenColorLow, 8);
  VDP_FillVRAM_16K(0x41, g_ScreenColorLow + (64 / 8), 8);
  VDP_FillVRAM_16K(0x51, g_ScreenColorLow + (128 / 8), 8);

  Print_DrawTextAt(g_Rooms[levelIdx].X - 1, 0, g_Rooms[levelIdx].Name);
  g_CurrentLightOn = false;
}

u8 getTile(u8 x, u8 y)
{
  u8 tile = VDP_Peek_16K(g_ScreenLayoutLow + (y / 8) * 32 + (x / 8));
  return tile;
}

// tel 73 - port 12 -13
void interact(u8 x, u8 y)
{
  u8 tile = getTile(x, y);
  switch (tile)
  {
    // tel
  case 73:
    Print_DrawTextAt(g_Rooms[g_CurrRoomIdx].X - 1, g_Rooms[g_CurrRoomIdx].Y + g_Rooms[g_CurrRoomIdx].Height + 2, "DRIIIING !!");
    break;
  case 74:
  {
    g_CurrentLightOn = !g_CurrentLightOn;
    u8 firstCol = g_CurrentLightOn ? 0xA1 : 0x41;
    u8 secondCol = g_CurrentLightOn ? 0xB1 : 0x51;
    VDP_FillVRAM_16K(firstCol, g_ScreenColorLow, 8);
    VDP_FillVRAM_16K(firstCol, g_ScreenColorLow + (64 / 8), 8);
    VDP_FillVRAM_16K(secondCol, g_ScreenColorLow + (128 / 8), 8);
  }

  break;
  case 12:
  case 13:
    displayLevel(g_Rooms[g_CurrRoomIdx].NextLvlIdx);
    break;
  default:
    break;
  }
}

bool checkCollision(u8 x, u8 y)
{
  return getTile(x, y) >= 128;
}

void main()
{
  VDP_SetMode(VDP_MODE_SCREEN1);
  VDP_SetSpriteFlag(VDP_SPRITE_SIZE_16);
  VDP_ClearVRAM();
  VDP_SetColor(COLOR_BLACK);
  VDP_WriteVRAM_16K(g_Tiles_Patterns, g_ScreenPatternLow, sizeof(g_Tiles_Patterns));
  VDP_WriteVRAM_16K(g_Tiles_Colors, g_ScreenColorLow, sizeof(g_Tiles_Colors));

  // font
  Print_SetMode(PRINT_MODE_TEXT);
  Print_SetFontEx(8, 8, 1, 1, ' ', '_', g_Tiles_Patterns + 192);
  Print_Initialize();
  g_PrintData.PatternOffset = 192;

  // player

  g_Player.X = 100;
  g_Player.Y = 103;

  VDP_WriteVRAM_16K(g_SprtPlayerSprt, g_SpritePatternLow, sizeof(g_SprtPlayerSprt));
  VDP_SetSpriteSM1(0, g_Player.X, g_Player.Y, 0, COLOR_DARK_YELLOW);
  VDP_SetSpriteSM1(1, g_Player.X, g_Player.Y, 4, COLOR_WHITE);
  VDP_SetSpriteSM1(2, g_Player.X, g_Player.Y, 8, COLOR_DARK_RED);
  VDP_SetSpriteSM1(3, g_Player.X, g_Player.Y, 12, COLOR_BLACK);

  displayLevel(0);

  u8 count = 0;
  while (!Keyboard_IsKeyPressed(KEY_ESC))
  {
    Halt();
    u8 xTemp = g_Player.X;
    u8 yTemp = g_Player.Y;
    if (Keyboard_IsKeyPressed(KEY_LEFT))
    {
      xTemp--;
    }
    if (Keyboard_IsKeyPressed(KEY_RIGHT))
    {
      xTemp++;
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

    if (Keyboard_IsKeyPressed(KEY_SPACE))
    {
      // middle player
      while (!Keyboard_IsKeyPressed(KEY_SPACE))
      {
      }
      interact(g_Player.X + 8, g_Player.Y + 8);
    }

    VDP_SetSpritePosition(0, g_Player.X, g_Player.Y);
    VDP_SetSpritePosition(1, g_Player.X, g_Player.Y);
    VDP_SetSpritePosition(2, g_Player.X, g_Player.Y);
    VDP_SetSpritePosition(3, g_Player.X, g_Player.Y);
  }

  Bios_Exit(0);
}