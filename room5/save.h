#pragma once
#include "core.h"
#include "room5.h"

extern const c8 g_CryptRoom5Map[];
void SaveInit();
bool SaveEncode(struct SaveData *pData, c8 *saveCode);
bool SaveDecode(c8 *saveCode, struct SaveData *pData);