#include "level_defs.h"

// Liste des pièces et de leur caracteristiques
const struct RoomDefinition g_Rooms[] = {

		// Écran d'accueil
		{ g_Level001, 1, 0 },  // 0

		// Pièces du jeu
		{ g_Level002, 2, 0 },  // 1 - Phone
		{ g_Level003, 3, 1 },  // 2
		{ g_Level004, 4, 1 },  // 3
		{ g_Level005, 5, 1 },  // 4
		{ g_Level006, 6, 1 },  // 5
		{ g_Level007, 7, 1 },  // 6
		{ g_Level008, 8, 1 },  // 7 - Phone
		{ g_Level009, 9, 2 },  // 8
		{ g_Level010, 10, 2 }, // 9
		{ g_Level011, 11, 2 }, // 10
		{ g_Level012, 12, 2 }, // 11 - Phone
		{ g_Level013, 13, 3 }, // 12
		{ g_Level014, 14, 3 }, // 13
		{ g_Level015, 15, 3 }, // 14
		{ g_Level016, 16, 3 }, // 15 - Phone
		{ g_Level017, 17, 4 }, // 16
		{ g_Level018, 18, 4 }, // 17
		{ g_Level019, 19, 4 }, // 18
		{ g_Level020, 20, 4 }, // 19 - Phone
		{ g_Level021, 21, 5 }, // 20
		{ g_Level022, 22, 5 }, // 21
		{ g_Level023, 23, 5 }, // 22
		{ g_Level024, 24, 5 }, // 23 - Phone
		{ g_Level025, 25, 6 }, // 24
		{ g_Level026, 26, 6 }, // 25
		{ g_Level027, 27, 6 }, // 26 - Phone

		// Mène à l'une des fin
		{ g_Level028, -1, 7 }, // 27

		// Fins spécifiques en fonction des choix du joueur
		{ g_Level029, 31, 7 }, // 28
		{ g_Level030, 31, 7 }, // 29
		{ g_Level031, 31, 7 }, // 30

		// Fin commune / Credits
		{ g_Level032, 0, 7 },  // 31
};
