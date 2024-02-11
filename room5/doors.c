#include "doors.h"

#include "tiles_defs.h"
#include "level_defs.h"
#include "tiles.h"
#include "room5.h"

// Connexion des portes aux thèmes du jeu
u8 g_DoorTheme[3];
u8 g_DoorThemeCount[3];
struct InteractedDoor g_InteractedDoor;
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
	g_InteractedDoor.tile = tile;
	g_InteractedDoor.x = x;
	g_InteractedDoor.y = y;
	g_InteractedDoor.currentRoom = currentRoom;
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
