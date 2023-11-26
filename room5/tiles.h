#pragma once
#include "core.h"

u8 getTile(u8 x, u8 y);
u8 getTileByTileCoord(u8 x, u8 y);

void setTile(u8 x, u8 y, u8 tile);
bool checkCollision(u8 x, u8 y);
void setTileByTileCoord(u8 x, u8 y, u8 tile);