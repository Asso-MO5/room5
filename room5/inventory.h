#pragma once
#include "core.h"

#define INVENTORY_SIZE 5
#define INVENTORY_DISPLAY_X 24
#define INVENTORY_DISPLAY_Y 192

#define EMPTY_ITEM 0

void initInventory();
bool addItemToInventory(u8 item);
bool hasItemInInventory(u8 item);
bool removeItemFromInventory(u8 item);
