#pragma once
#include "core.h"

#define INVENTORY_SIZE 4
#define EMPTY_ITEM 0

void initInventory();
bool addItemToInventory(u8 item);
bool hasItemInInventory(u8 item);
bool removeItemFromInventory(u8 item);