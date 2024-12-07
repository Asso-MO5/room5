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

void SaveInit()
{
	// Le sel, c'est pour le cryptage, pas dans le beurre.
	Crypt_SetKey("room5");
	Crypt_SetCode(g_CryptRoom5Code);
	Crypt_SetMap(g_CryptRoom5Map);
}

bool SaveEncode(struct SaveData *pData, c8 *saveCode)
{
	u16 saveBuffer[2];
	saveBuffer[0] = pData->currentTime;
	saveBuffer[1] = pData->currentLevel & 0b111111 | (pData->themes[0] & 0b111) << 6 | (pData->themes[1] & 0b111) << 9 | (pData->themes[2] & 0b111) << 12;

	Crypt_Encode((u8 *)saveBuffer, 4, (u8 *)saveCode);
	return TRUE;
}

bool SaveDecode(const c8 *saveCode, struct SaveData *pData)
{
	saveCode;
	pData;

	u16 saveBuffer[2];
	bool checkDecode = Crypt_Decode(saveCode, (u8 *)saveBuffer);

	if (!checkDecode)
	{
		return FALSE;
	}

	// F|E D C|B A 9|8 7 6|5 4 3 2 1 0
	// x|M M M|A A A|I I I|L L L L L L
	pData->currentTime = saveBuffer[0];

	pData->currentLevel = saveBuffer[1] & 0b111111;
	pData->themes[0] = (saveBuffer[1] >> 6) & 0b111;
	pData->themes[1] = (saveBuffer[1] >> 9) & 0b111;
	pData->themes[2] = (saveBuffer[1] >> 12) & 0b111;

	return TRUE;
}
