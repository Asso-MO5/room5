#include "tiles.h"
#include "msxgl.h"

//-----------------------------------------------------------------------------
// Récupère la tuile à la position indiquée
//-----------------------------------------------------------------------------
u8 getTile(u8 x, u8 y)
{
	u8 tile = VDP_Peek_16K(g_ScreenLayoutLow + (y / 8) * 32 + (x / 8));
	return tile;
}

u8 getTileByTileCoord(u8 x, u8 y)
{
	u8 tile = VDP_Peek_16K(g_ScreenLayoutLow + y * 32 + x);
	return tile;
}

//-----------------------------------------------------------------------------
// Modifie la tuile à la position indiquée
void setTile(u8 x, u8 y, u8 tile)
{
	VDP_Poke_16K(tile, g_ScreenLayoutLow + (y / 8) * 32 + (x / 8));
}

//-----------------------------------------------------------------------------
// remplace la tuile à la position indiquée par une tuile vide avec les coordonnées de la tuile
void setTileByTileCoord(u8 x, u8 y, u8 tile)
{
	VDP_Poke_16K(tile, g_ScreenLayoutLow + y * 32 + x);
}

//-----------------------------------------------------------------------------
// Test la collision à la position indiquée
bool checkCollision(u8 x, u8 y)
{
	return getTile(x, y) >= 128;
}
