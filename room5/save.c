#include "save.h"
#include "crypt.h"

// Default string containing the 32 valid characters
const c8 g_CryptRoom5Map[] = "ABCDEF1234567890";

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

	//  F |  E  D  C |  B  A  9 |  8  7  6 |  5  4  3  2  1  0
	//----+----------+----------+----------+-------------------
	// L0 | M2 M1 M0 | A2 A1 A0 | I2 I1 I2 | L5 L4 L3 L2 L1 L0
	saveBuffer[0] = pData->currentLevel & 0b111111 | (pData->themes[0] & 0b111) << 6 | (pData->themes[1] & 0b111) << 9 | (pData->themes[2] & 0b111) << 12;

	//  F |  E  D  C  B  A  9  8  7  6  5  4  3  2  1  0
	//----+----------------------------------------------
	// T0 | TE TD TC TB TA T9 T8 T7 T6 T5 T4 T3 T2 T1 T0
	saveBuffer[1] = pData->currentTime;

	Crypt_Encode((u8 *)saveBuffer, 4, (u8 *)saveCode);
	return TRUE;
}

//-----------------------------------------------------------------------------
// Recharge l'état du jeu
bool SaveDecode(const c8 *saveCode, struct SaveData *pData)
{
	u16 saveBuffer[2];
	bool checkDecode = Crypt_Decode(saveCode, (u8 *)saveBuffer);

	if (!checkDecode)
	{
		return FALSE;
	}

	//  F |  E  D  C |  B  A  9 |  8  7  6 |  5  4  3  2  1  0
	//----+----------+----------+----------+-------------------
	// L0 | M2 M1 M0 | A2 A1 A0 | I2 I1 I2 | L5 L4 L3 L2 L1 L0
	pData->currentLevel = saveBuffer[0] & 0b111111;
	pData->themes[0] = (saveBuffer[0] >> 6) & 0b111;
	pData->themes[1] = (saveBuffer[0] >> 9) & 0b111;
	pData->themes[2] = (saveBuffer[0] >> 12) & 0b111;

	//  F |  E  D  C  B  A  9  8  7  6  5  4  3  2  1  0
	//----+----------------------------------------------
	// T0 | TE TD TC TB TA T9 T8 T7 T6 T5 T4 T3 T2 T1 T0
	pData->currentTime = saveBuffer[1];

	return TRUE;
}
