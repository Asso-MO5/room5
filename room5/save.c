#include "save.h"
#include "crypt.h"

bool SaveEncode(struct SaveData *pData, c8 *saveCode)
{
	// Le sel, c'est pour le cryptage, pas dans le beurre.
	Crypt_SetKey("room5");
	Crypt_Encode((u8 *)pData, sizeof(struct SaveData), (u8 *)saveCode);
	return TRUE;
}

bool SaveDecode(c8 *saveCode, struct SaveData *pData)
{
	saveCode;
	pData;
	return TRUE;
}