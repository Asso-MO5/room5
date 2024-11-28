#include "save.h"
#include "crypt.h"

bool SaveEncode(struct SaveData *pData, c8 *saveCode)
{
	u16 saveBuffer[2];
	saveBuffer[0] = pData->currentLevel & 0b111111 | (pData->themes[0] & 0b111) << 6 | (pData->themes[1] & 0b111) << 9 | (pData->themes[2] & 0b111) << 12;
	saveBuffer[1] = pData->currentTime;

	// Le sel, c'est pour le cryptage, pas dans le beurre.
	Crypt_SetKey("room5");
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
	pData->currentTime = saveBuffer[1];

	pData->currentLevel = saveBuffer[0] & 0b111111;
	pData->themes[0] = (saveBuffer[0] >> 6) & 0b111;
	pData->themes[1] = (saveBuffer[0] >> 9) & 0b111;
	pData->themes[2] = (saveBuffer[0] >> 12) & 0b111;

	return TRUE;
}
