#include "save.h"
#include "crypt.h"
#include "level_defs.h"

// Default string containing the 32 valid characters
const c8 g_CryptRoom5Map[] = "0123456789ABCDEF";

// Default bit-field coding table
const u16 g_CryptRoom5Code[8] =
{
	//      3210    3210
	0b0000000100000000, // 0
	0b0000000000000100, // 1
	0b0000010000000000, // 2
	0b0000000000000001, // 3
	0b0000000000001000, // 4
	0b0000001000000000, // 5
	0b0000100000000000, // 6
	0b0000000000000010, // 7
};

//-----------------------------------------------------------------------------
// Initilisation du système de sauvegarde
void SaveInit()
{
	// Le sel, c'est pour le cryptage, pas dans le beurre.
	Crypt_SetKey("room5");
	Crypt_SetCode(g_CryptRoom5Code);
	Crypt_SetMap(g_CryptRoom5Map);
}

//-----------------------------------------------------------------------------
// Sauvegarde de l'état actuel du jeu
bool SaveEncode(struct SaveData *pData, c8 *saveCode)
{
	u16 saveBuffer[2];

	//  F  E |  D  C  B  A  9  8  7  6  5  4  3  2  1  0
	//-------+------------------------------------------
	// T1 T0 | TD TC TB TA T9 T8 T7 T6 T5 T4 T3 T2 T1 T0
	saveBuffer[0] = pData->currentTime;
	saveBuffer[0] |= (pData->currentTime & 0x0003) << 14;

	//  F |  E  D  C |  B  A  9 |  8  7  6 |  5  4  3  2  1  0
	//----+----------+----------+----------+-------------------
	// L0 | M2 M1 M0 | A2 A1 A0 | I2 I1 I2 | L5 L4 L3 L2 L1 L0
	saveBuffer[1] = pData->currentLevel & 0b111111 | (pData->themes[0] & 0b111) << 6 | (pData->themes[1] & 0b111) << 9 | (pData->themes[2] & 0b111) << 12;
	if (saveBuffer[1] & 0x0001)
		saveBuffer[1] |= 0x8000;

	Crypt_Encode((u8 *)saveBuffer, 4, (u8 *)saveCode);
	return TRUE;
}

//-----------------------------------------------------------------------------
// Recharge l'état du jeu
bool SaveDecode(const c8 *saveCode, struct SaveData *pData)
{
	u16 saveBuffer[2];
	if (!Crypt_Decode(saveCode, (u8 *)saveBuffer))
		return FALSE;

	if ((saveBuffer[0] >> 14) != (saveBuffer[0] & 0x0003))
		return FALSE;

	if ((saveBuffer[1] >> 15) != (saveBuffer[1] & 0x0001))
		return FALSE;

	//  F  E |  D  C  B  A  9  8  7  6  5  4  3  2  1  0
	//-------+------------------------------------------
	// T1 T0 | TD TC TB TA T9 T8 T7 T6 T5 T4 T3 T2 T1 T0
	pData->currentTime = saveBuffer[0] & 0x3FFF;

	//  F |  E  D  C |  B  A  9 |  8  7  6 |  5  4  3  2  1  0
	//----+----------+----------+----------+-------------------
	// L0 | M2 M1 M0 | A2 A1 A0 | I2 I1 I2 | L5 L4 L3 L2 L1 L0
	pData->currentLevel = saveBuffer[1] & 0b111111;
	pData->themes[0] = (saveBuffer[1] >> 6) & 0b111;
	pData->themes[1] = (saveBuffer[1] >> 9) & 0b111;
	pData->themes[2] = (saveBuffer[1] >> 12) & 0b111;

	u8 totalThemes = pData->themes[0] + pData->themes[1] + pData->themes[2];
	if (totalThemes != g_Rooms[pData->currentLevel].TotalThemes)
		return FALSE;

	return TRUE;
}
