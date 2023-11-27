#include "doors.h"

#include "tiles_defs.h"
#include "level_defs.h"
#include "tiles.h"
#include "room5.h"

// Connexion des portes aux thèmes du jeu
u8 g_DoorTheme[3];
u8 g_DoorThemeCount[3];

void initializeDoors()
{
	for (u8 i = 0; i < THEME_NUMBER; ++i)
	{
		g_DoorThemeCount[i] = 0;
	}
}

void setDoorTheme(u8 doorIdx, u8 theme)
{
	g_DoorTheme[doorIdx] = theme;
}

u8 activateDoor(u8 tile, u8 x, u8 y, u8 currentRoom)
{
	if (tile == TILE_DOOR2)
		x -= 8;
	y -= 16;

	u8 roomNumber = getTile(x, y);
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

	return g_Rooms[currentRoom].NextLvlIdx;
}

u8 activateEndDoor()
{
	u8 hospital = g_DoorThemeCount[THEME_HOSPITAL];
	u8 alien = g_DoorThemeCount[THEME_ALIEN];
	u8 matrix = g_DoorThemeCount[THEME_MATRIX];

	if (hospital > alien && hospital > matrix)
	{
		return 28;
	}
	else if (alien > hospital && alien > matrix)
	{
		return 29;
	}
	else // if (matrix > hospital && matrix > alien)
	{
		return 30;
	}
}
