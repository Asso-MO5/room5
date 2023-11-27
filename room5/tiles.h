#pragma once
#include "core.h"

/*
	 Interface qui permet de manipuler les tuiles à l'écran.
*/

/* Récupère la tuile à la position indiquée */
u8 getTile(u8 x, u8 y); // Coordonnées en pixels
u8 getTileByTileCoord(u8 x, u8 y); // Coordonnées en tuiles

/* Modifie la tuile à la position indiquée */
void setTile(u8 x, u8 y, u8 tile); // Coordonnées en pixels
void setTileByTileCoord(u8 x, u8 y, u8 tile); // Coordonnées en tuiles

/* Test si la tuile à la position indiquée provoque une collision
   Coordonnées en pixels */
bool checkCollision(u8 x, u8 y);
