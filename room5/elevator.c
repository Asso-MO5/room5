#include "elevator.h"
#include "tiles.h"
#include "tiles_defs.h"
#include "color.h"
#include "objects.h"
#include "msxgl.h"

// Paramètres des élévateurs
#define MAX_ELEVATOR 8
#define MAX_MANUAL_ELEVATOR 8
#define ELEVATOR_STAND 20

// États des élévateurs
enum ElevatorState
{
	ELEVATOR_STATE_MOVE,
	ELEVATOR_STATE_STAND,
};

// Directions des élévateurs
enum ElevatorDirection
{
	ELEVATOR_DIRECTION_UP,
	ELEVATOR_DIRECTION_DOWN,
};

// Définition d'un élévateur
struct ElevatorDefinition
{
	u8 X;
	u8 Y;
	i8 VelocityY;
	u8 State;
	u8 Timer;
};

// Variables pour la gestion des ascenseurs automatiques
u8 g_ElevatorCount = 0;
struct ElevatorDefinition g_Elevator[MAX_ELEVATOR];

// Variables pour la gestion des ascenseurs manuels
u8 g_ManualElevatorCount = 0;
struct ActiveObject g_ManualElevator[MAX_MANUAL_ELEVATOR];

//-----------------------------------------------------------------------------
// Test la présence d'un rail à la position indiquée
//-----------------------------------------------------------------------------

bool checkRails(u8 x, u8 y)
{
	return getTile(x, y) == TILE_RAILS; // N° de la tuile des rails
}

bool checkManualRails(u8 x, u8 y)
{
	return getTileByTileCoord(x, y) == TILE_MANUAL_RAILS; // N° de la tuile des rails
}

//-----------------------------------------------------------------------------
// Gestion des élévateurs automatiques
//-----------------------------------------------------------------------------

void resetElevators()
{
	g_ElevatorCount = 0;
	g_ManualElevatorCount = 0;
}

bool canAddElevator()
{
	return g_ElevatorCount < MAX_ELEVATOR;
}

void addElevator(u8 x, u8 y)
{
	u8 num = g_ElevatorCount;
	struct ElevatorDefinition *elevator = &g_Elevator[num];

	elevator->X = x;
	elevator->Y = y;
	elevator->VelocityY = 1;
	elevator->State = ELEVATOR_STATE_MOVE;
	elevator->Timer = 0;

	VDP_SetSpriteSM1(SPT_ELEVATOR + num, x, y - 9, 4 * 4 * 12, COLOR_WHITE);

	g_ElevatorCount += 1;
}

void updateElevator(u8 num)
{
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

void updateAllElevators()
{
	for (u8 i = 0; i < g_ElevatorCount; ++i)
	{
		updateElevator(i);
	}
}

void changeAllElevatorsColor(u8 color)
{
	for (u8 i = 0; i < g_ElevatorCount; ++i)
	{
		VDP_SetSpriteColorSM1(SPT_ELEVATOR + i, color);
	}

	VDP_Poke_16K(color << 4, VDP_GetColorTable() + 19);
}

void hideAllElevators()
{
	for (u8 i = g_ElevatorCount; i < MAX_ELEVATOR; ++i)
	{
		VDP_HideSprite(SPT_ELEVATOR + i);
	}
}

bool isOnElevator(u8 *X, u8 *Y)
{
	for (u8 i = 0; i < g_ElevatorCount; ++i)
	{
		if ((*X < g_Elevator[i].X - 16) || (*X > g_Elevator[i].X + 16))
			continue;

		if ((*Y + 17 > g_Elevator[i].Y) && (*Y + 17 < g_Elevator[i].Y + 8))
		{
			*Y = g_Elevator[i].Y - 16;
			return TRUE;
		}
	}

	return FALSE;
}

//-----------------------------------------------------------------------------
// Gestion des élévateurs manuels
//-----------------------------------------------------------------------------

void addManualElevator(u8 x, u8 y)
{
	u8 num = g_ManualElevatorCount;
	struct ActiveObject *elevator = &g_ManualElevator[num];

	elevator->X = x;
	elevator->Y = y;
	elevator->Tile = TILE_MANUAL_ELEVATOR;

	g_ManualElevatorCount += 1;
}

void moveManualElevator(u8 num, u8 direction)
{
	struct ActiveObject *elevator = &g_ManualElevator[num];

	if (direction == ELEVATOR_DIRECTION_UP)
	{
		if (checkManualRails(elevator->X, elevator->Y - 1))
		{
			setTileByTileCoord(elevator->X, elevator->Y, TILE_MANUAL_RAILS);
			setTileByTileCoord(elevator->X + 1, elevator->Y, TILE_MANUAL_RAILS);
			elevator->Y--;
			setTileByTileCoord(elevator->X, elevator->Y, TILE_MANUAL_ELEVATOR);
			setTileByTileCoord(elevator->X + 1, elevator->Y, (u8)(TILE_MANUAL_ELEVATOR + 1));
		}
	}
	else
	{
		if (checkManualRails(elevator->X, elevator->Y + 1))
		{
			setTileByTileCoord(elevator->X, elevator->Y, TILE_MANUAL_RAILS);
			setTileByTileCoord(elevator->X + 1, elevator->Y, TILE_MANUAL_RAILS);
			elevator->Y++;
			setTileByTileCoord(elevator->X, elevator->Y, TILE_MANUAL_ELEVATOR);
			setTileByTileCoord(elevator->X + 1, elevator->Y, (u8)(TILE_MANUAL_ELEVATOR + 1));
		}
	}
}

void moveAllManualElevators(u8 tile)
{
	for (u8 i = 0; i < g_ManualElevatorCount; ++i)
	{
		moveManualElevator(i, tile == TILE_ELEVATOR_UP ? ELEVATOR_DIRECTION_UP : ELEVATOR_DIRECTION_DOWN);
	}
}