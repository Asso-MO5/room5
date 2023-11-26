#include "elevator.h"
#include "tiles.h"
#include "tiles_defs.h"
#include "color.h"
#include "objects.h"
#include "msxgl.h"

// Variables pour la gestion des ascenseurs automatiques
u8 g_ElevatorCount = 0;
struct ElevatorDefinition g_Elevator[MAX_ELEVATOR];

// Variables pour la gestion des ascenseurs manuels
u8 g_ManualElevatorCount = 0;
struct ActiveObject g_ManualElevator[MAX_MANUAL_ELEVATOR];

//-----------------------------------------------------------------------------
void updateAllElevators()
{
	for (u8 i = 0; i < g_ElevatorCount; i++)
	{
		updateElevator(i);
	}
}

// Initialise un élévateur
void initElevator(u8 num, u8 x, u8 y)
{
	struct ElevatorDefinition *elevator = &g_Elevator[num];

	elevator->X = x;
	elevator->Y = y;
	elevator->VelocityY = 1;
	elevator->State = ELEVATOR_STATE_MOVE;
	elevator->Timer = 0;

	VDP_SetSpriteSM1(SPT_ELEVATOR + num, x, y - 9, 4 * 4 * 12, COLOR_WHITE);
}

//-----------------------------------------------------------------------------
// Mise à jour d'un élévateur
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

// Elévateurs manuel

void addManualElevator(u8 num, u8 x, u8 y)
{
	struct ActiveObject *elevator = &g_ManualElevator[num];

	elevator->X = x;
	elevator->Y = y;
	elevator->Tile = TILE_MANUAL_ELEVATOR;
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

// Test la présence d'un rail à la position indiquée
bool checkRails(u8 x, u8 y)
{
	return getTile(x, y) == TILE_RAILS; // N° de la tuile des rails
}

bool checkManualRails(u8 x, u8 y)
{
	return getTileByTileCoord(x, y) == TILE_MANUAL_RAILS; // N° de la tuile des rails
}
