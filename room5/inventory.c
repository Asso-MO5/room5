#include "msxgl.h"
#include "inventory.h"
#include "tiles.h"
#include "tiles_defs.h"

u8 g_Inventory[INVENTORY_SIZE]; // Contenu de l'inventaire

//-----------------------------------------------------------------------------
// Initialise l'inventaire
void initInventory()
{
	for (u8 i = 0; i < INVENTORY_SIZE; i++)
	{
		g_Inventory[i] = EMPTY_ITEM;
	}
}

//-----------------------------------------------------------------------------
// Ajout d'un objet dans l'inventaire
bool addItemToInventory(u8 item)
{
	for (u8 i = 0; i < INVENTORY_SIZE; i++)
	{
		if (g_Inventory[i] == EMPTY_ITEM)
		{
			g_Inventory[i] = item;
			setTile(INVENTORY_DISPLAY_X + i * 16, (u8)(INVENTORY_DISPLAY_Y - 8), item);
			return TRUE;
		}
	}
	return FALSE;
}

//-----------------------------------------------------------------------------
// Test la présence d'un objet dans l'inventaire
bool hasItemInInventory(u8 item)
{
	for (u8 i = 0; i < INVENTORY_SIZE; i++)
	{
		if (g_Inventory[i] == item)
		{
			return TRUE;
		}
	}
	return FALSE;
}

//-----------------------------------------------------------------------------
// Retire un objet de l'inventaire
bool removeItemFromInventory(u8 item)
{
	for (u8 i = 0; i < INVENTORY_SIZE; i++)
	{
		if (g_Inventory[i] == item)
		{
			g_Inventory[i] = EMPTY_ITEM;
			setTile(INVENTORY_DISPLAY_X + i * 16, (u8)(INVENTORY_DISPLAY_Y - 8), TILE_EMPTY);
			return TRUE;
		}
	}
	return FALSE;
}
