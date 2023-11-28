#pragma once

#include "core.h"

/* Interface de gestion des élévateurs */

// Fonctions de gestion des élévateurs
void resetElevators();
bool canAddElevator();
void addElevator(u8 x, u8 y);
void updateAllElevators();
void changeAllElevatorsColor(u8 color);
void hideAllElevators();
bool isOnElevator(u8 * X, u8 * Y);

// Fonctions de gestion des élévateurs manuels
void addManualElevator(u8 x, u8 y);
void moveAllManualElevators(u8 tile);
bool isManualElevatorAt(u8 x, u8 y); // Coordonnées en pixels

bool checkRails(u8 x, u8 y);
