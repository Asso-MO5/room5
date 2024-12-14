#pragma once
#include "core.h"

#include "data/level/level001_def.h"
#include "data/level/level002_def.h"
#include "data/level/level003_def.h"
#include "data/level/level004_def.h"
#include "data/level/level005_def.h"
#include "data/level/level006_def.h"
#include "data/level/level007_def.h"
#include "data/level/level008_def.h"
#include "data/level/level009_def.h"
#include "data/level/level010_def.h"
#include "data/level/level011_def.h"
#include "data/level/level012_def.h"
#include "data/level/level013_def.h"
#include "data/level/level014_def.h"
#include "data/level/level015_def.h"
#include "data/level/level016_def.h"
#include "data/level/level017_def.h"
#include "data/level/level018_def.h"
#include "data/level/level019_def.h"
#include "data/level/level020_def.h"
#include "data/level/level021_def.h"
#include "data/level/level022_def.h"
#include "data/level/level023_def.h"
#include "data/level/level024_def.h"
#include "data/level/level025_def.h"
#include "data/level/level026_def.h"
#include "data/level/level027_def.h"
#include "data/level/level028_def.h"
#include "data/level/level029_def.h"
#include "data/level/level030_def.h"
#include "data/level/level031_def.h"
#include "data/level/level032_def.h"

// Structure de description d'une pièce
struct RoomDefinition
{
	const u8 *Layout;
	i8 NextLvlIdx;
	u8 TotalThemes;
};

extern const struct RoomDefinition g_Rooms[];
