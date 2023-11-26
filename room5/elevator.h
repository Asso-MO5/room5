#pragma once
#include "core.h"

#define MAX_ELEVATOR 8
#define MAX_MANUAL_ELEVATOR 8
#define ELEVATOR_STAND 20

// Variables pour la gestion des ascenseurs automatiques
extern u8 g_ElevatorCount;
extern struct ElevatorDefinition g_Elevator[MAX_ELEVATOR];

// Variables pour la gestion des ascenseurs manuels
extern u8 g_ManualElevatorCount;
extern struct ActiveObject g_ManualElevator[MAX_MANUAL_ELEVATOR];

// Etats des élévateurs
enum ElevatorState
{
	ELEVATOR_STATE_MOVE,
	ELEVATOR_STATE_STAND,
};

enum ElevatorDirection
{
	ELEVATOR_DIRECTION_UP,
	ELEVATOR_DIRECTION_DOWN,
};

// Structure des paramètres de l'élévateur
struct ElevatorDefinition
{
	u8 X;
	u8 Y;
	i8 VelocityY;
	u8 State;
	u8 Timer;
};

bool checkRails(u8 x, u8 y);
bool checkManualRails(u8 x, u8 y);

void initElevator(u8 num, u8 x, u8 y);
void updateElevator(u8 num);
void addManualElevator(u8 num, u8 x, u8 y);
void updateAllElevators();
void moveManualElevator(u8 num, u8 direction);
