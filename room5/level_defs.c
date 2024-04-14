#include "level_defs.h"

// Données des pièces
#include "data/level/level001.h"
#include "data/level/level002.h"
#include "data/level/level003.h"
#include "data/level/level004.h"
#include "data/level/level005.h"
#include "data/level/level006.h"
#include "data/level/level007.h"
#include "data/level/level008.h"
#include "data/level/level009.h"
#include "data/level/level010.h"
#include "data/level/level011.h"
#include "data/level/level012.h"
#include "data/level/level013.h"
#include "data/level/level014.h"
#include "data/level/level015.h"
#include "data/level/level016.h"
#include "data/level/level017.h"
#include "data/level/level018.h"
#include "data/level/level019.h"
#include "data/level/level020.h"
#include "data/level/level021.h"
#include "data/level/level022.h"
#include "data/level/level023.h"
#include "data/level/level024.h"
#include "data/level/level025.h"
#include "data/level/level026.h"
#include "data/level/level027.h"
#include "data/level/level028.h"
#include "data/level/level029.h"
#include "data/level/level030.h"
#include "data/level/level031.h"
#include "data/level/level032.h"

// Liste des pièces et de leur caracteristiques
const struct RoomDefinition g_Rooms[] = {

		// écran d'accueil
		{(32 - LEVEL001_WIDTH) / 2, (24 - LEVEL001_HEIGHT) / 2, LEVEL001_WIDTH, LEVEL001_HEIGHT, g_Level001, "", 1},

		{(32 - LEVEL002_WIDTH) / 2, (24 - LEVEL002_HEIGHT) / 2, LEVEL002_WIDTH, LEVEL002_HEIGHT, g_Level002, "", 2},
		{(32 - LEVEL003_WIDTH) / 2, (24 - LEVEL003_HEIGHT) / 2, LEVEL003_WIDTH, LEVEL003_HEIGHT, g_Level003, "", 3},
		{(32 - LEVEL004_WIDTH) / 2, (24 - LEVEL004_HEIGHT) / 2, LEVEL004_WIDTH, LEVEL004_HEIGHT, g_Level004, "", 4},
		{(32 - LEVEL005_WIDTH) / 2, (24 - LEVEL005_HEIGHT) / 2, LEVEL005_WIDTH, LEVEL005_HEIGHT, g_Level005, "", 5},
		{(32 - LEVEL006_WIDTH) / 2, (24 - LEVEL006_HEIGHT) / 2, LEVEL006_WIDTH, LEVEL006_HEIGHT, g_Level006, "", 6},
		{(32 - LEVEL007_WIDTH) / 2, (24 - LEVEL007_HEIGHT) / 2, LEVEL007_WIDTH, LEVEL007_HEIGHT, g_Level007, "", 7},
		{(32 - LEVEL008_WIDTH) / 2, (24 - LEVEL008_HEIGHT) / 2, LEVEL008_WIDTH, LEVEL008_HEIGHT, g_Level008, "", 8},
		{(32 - LEVEL009_WIDTH) / 2, (24 - LEVEL009_HEIGHT) / 2, LEVEL009_WIDTH, LEVEL009_HEIGHT, g_Level009, "", 9},
		{(32 - LEVEL010_WIDTH) / 2, (24 - LEVEL010_HEIGHT) / 2, LEVEL010_WIDTH, LEVEL010_HEIGHT, g_Level010, "", 10},
		{(32 - LEVEL011_WIDTH) / 2, (24 - LEVEL011_HEIGHT) / 2, LEVEL011_WIDTH, LEVEL011_HEIGHT, g_Level011, "", 11},
		{(32 - LEVEL012_WIDTH) / 2, (24 - LEVEL012_HEIGHT) / 2, LEVEL012_WIDTH, LEVEL012_HEIGHT, g_Level012, "", 12},
		{(32 - LEVEL013_WIDTH) / 2, (24 - LEVEL013_HEIGHT) / 2, LEVEL013_WIDTH, LEVEL013_HEIGHT, g_Level013, "", 13},
		{(32 - LEVEL014_WIDTH) / 2, (24 - LEVEL014_HEIGHT) / 2, LEVEL014_WIDTH, LEVEL014_HEIGHT, g_Level014, "", 14},
		{(32 - LEVEL015_WIDTH) / 2, (24 - LEVEL015_HEIGHT) / 2, LEVEL015_WIDTH, LEVEL015_HEIGHT, g_Level015, "", 15},
		{(32 - LEVEL016_WIDTH) / 2, (24 - LEVEL016_HEIGHT) / 2, LEVEL016_WIDTH, LEVEL016_HEIGHT, g_Level016, "", 16},
		{(32 - LEVEL017_WIDTH) / 2, (24 - LEVEL017_HEIGHT) / 2, LEVEL017_WIDTH, LEVEL017_HEIGHT, g_Level017, "", 17},
		{(32 - LEVEL018_WIDTH) / 2, (24 - LEVEL018_HEIGHT) / 2, LEVEL018_WIDTH, LEVEL018_HEIGHT, g_Level018, "", 18},
		{(32 - LEVEL019_WIDTH) / 2, (24 - LEVEL019_HEIGHT) / 2, LEVEL019_WIDTH, LEVEL019_HEIGHT, g_Level019, "", 19},
		{(32 - LEVEL020_WIDTH) / 2, (24 - LEVEL020_HEIGHT) / 2, LEVEL020_WIDTH, LEVEL020_HEIGHT, g_Level020, "", 20},
		{(32 - LEVEL021_WIDTH) / 2, (24 - LEVEL021_HEIGHT) / 2, LEVEL021_WIDTH, LEVEL021_HEIGHT, g_Level021, "", 21},
		{(32 - LEVEL022_WIDTH) / 2, (24 - LEVEL022_HEIGHT) / 2, LEVEL022_WIDTH, LEVEL022_HEIGHT, g_Level022, "", 22},
		{(32 - LEVEL023_WIDTH) / 2, (24 - LEVEL023_HEIGHT) / 2, LEVEL023_WIDTH, LEVEL023_HEIGHT, g_Level023, "", 23},
		// on saute les pièces non faites
		{(32 - LEVEL024_WIDTH) / 2, (24 - LEVEL024_HEIGHT) / 2, LEVEL024_WIDTH, LEVEL024_HEIGHT, g_Level024, "", 24},
		{(32 - LEVEL025_WIDTH) / 2, (24 - LEVEL025_HEIGHT) / 2, LEVEL025_WIDTH, LEVEL025_HEIGHT, g_Level025, "", 25},
		{(32 - LEVEL026_WIDTH) / 2, (24 - LEVEL026_HEIGHT) / 2, LEVEL026_WIDTH, LEVEL026_HEIGHT, g_Level026, "", 26},
		{(32 - LEVEL027_WIDTH) / 2, (24 - LEVEL027_HEIGHT) / 2, LEVEL027_WIDTH, LEVEL027_HEIGHT, g_Level027, "", 27},

		// Mène à l'une des fin
		{(32 - LEVEL028_WIDTH) / 2, (24 - LEVEL028_HEIGHT) / 2, LEVEL028_WIDTH, LEVEL028_HEIGHT, g_Level028, "", -1},

		// Les fins
		{(32 - LEVEL029_WIDTH) / 2, (24 - LEVEL029_HEIGHT) / 2, LEVEL029_WIDTH, LEVEL029_HEIGHT, g_Level029, "", 31},
		{(32 - LEVEL030_WIDTH) / 2, (24 - LEVEL030_HEIGHT) / 2, LEVEL030_WIDTH, LEVEL030_HEIGHT, g_Level030, "", 31},
		{(32 - LEVEL031_WIDTH) / 2, (24 - LEVEL031_HEIGHT) / 2, LEVEL031_WIDTH, LEVEL031_HEIGHT, g_Level031, "", 31},

		// fin commune
		{(32 - LEVEL032_WIDTH) / 2, (24 - LEVEL032_HEIGHT) / 2, LEVEL032_WIDTH, LEVEL032_HEIGHT, g_Level032, "", 0},

};
