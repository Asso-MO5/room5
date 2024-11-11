#include "level_defs.h"

// Liste des pièces et de leur caracteristiques
const struct RoomDefinition g_Rooms[] = {

		// Écran d'accueil
		{ g_Level001, "", 1 },  // 0

		// Pièces du jeu
		{ g_Level002, "", 2 },  // 1
		{ g_Level003, "", 3 },  // 2
		{ g_Level004, "", 4 },  // 3
		{ g_Level005, "", 5 },  // 4
		{ g_Level006, "", 6 },  // 5
		{ g_Level007, "", 7 },  // 6
		{ g_Level008, "", 8 },  // 7
		{ g_Level009, "", 9 },  // 8
		{ g_Level010, "", 10 }, // 9
		{ g_Level011, "", 11 }, // 10
		{ g_Level012, "", 12 }, // 11
		{ g_Level013, "", 13 }, // 12
		{ g_Level014, "", 14 }, // 13
		{ g_Level015, "", 15 }, // 14
		{ g_Level016, "", 16 }, // 15
		{ g_Level017, "", 17 }, // 16
		{ g_Level018, "", 18 }, // 17
		{ g_Level019, "", 19 }, // 18
		{ g_Level020, "", 20 }, // 19
		{ g_Level021, "", 21 }, // 20
		{ g_Level022, "", 22 }, // 21
		{ g_Level023, "", 23 }, // 22
		{ g_Level024, "", 24 }, // 23
		{ g_Level025, "", 25 }, // 24
		{ g_Level026, "", 26 }, // 25
		{ g_Level027, "", 27 }, // 26

		// Mène à l'une des fin
		{ g_Level028, "", -1 }, // 27

		// Fins spécifiques en fonction des choix du joueur
		{ g_Level029, "", 31 }, // 28
		{ g_Level030, "", 31 }, // 29
		{ g_Level031, "", 31 }, // 30

		// Fin commune / Credits
		{ g_Level032, "", 0 },  // 31
};
