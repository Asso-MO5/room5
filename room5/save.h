#pragma once
#include "core.h"
#include "room5.h"

bool SaveEncode(struct SaveData *pData, c8 *saveCode);
bool SaveDecode(c8 *saveCode, struct SaveData *pData);