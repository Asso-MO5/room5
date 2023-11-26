#pragma once
#include "core.h"

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

extern const struct RoomDefinition g_Rooms[];
