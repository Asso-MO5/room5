// ____________________________
// ██▀▀█▀▀██▀▀▀▀▀▀▀█▀▀█        │   ▄▄▄                ▄▄
// ██  ▀  █▄  ▀██▄ ▀ ▄█ ▄▀▀ █  │  ▀█▄  ▄▀██ ▄█▄█ ██▀▄ ██  ▄███
// █  █ █  ▀▀  ▄█  █  █ ▀▄█ █▄ │  ▄▄█▀ ▀▄██ ██ █ ██▀  ▀█▄ ▀█▄▄
// ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀────────┘                 ▀▀
//  Program template
// ─────────────────────────────────────────────────────────────────────────────

//-----------------------------------------------------------------------------
// Définitions
//-----------------------------------------------------------------------------

// Configuration
#define MAX_ELEVATOR 8
#define ELEVATOR_STAND 20
#define EMPTY_ITEM 0
#define INVENTORY_SIZE 4
#define MAX_VISIBLE_OBJECTS 16
#define MAX_ELECTRIC_WALL 16

// Numéros de tuile
#define TILE_EMPTY 0
#define TILE_RAILS 28
#define TILE_PHONE 80
#define TILE_LIGHT1 81
#define TILE_LIGHT2 82
#define TILE_LOCK_DOOR1 12
#define TILE_LOCK_DOOR2 13
#define TILE_DOOR1 70
#define TILE_DOOR2 71
#define TILE_CABLE 29
#define TILE_BROKE_CABLE 83
#define TILE_FUSEBOX 84
#define TILE_FUSEBOX_ON 85
#define TILE_ELECTRIC_WALL 142

#define TILE_ITEM_KEY_ONE 96
#define TILE_ITEM_KEY_DOOR 97
#define TILE_ITEM_KEY_THREE 98
#define TILE_ITEM_FUSE 99
#define TILE_ITEM_TAPE 100

// tuiles spéciales de conditions
#define TILE_START_POS 127
#define TILE_SPE_LIGHT_OFF 125
#define TILE_SPE_LIGHT_ON 126

// Numéro de sprite
#define SPT_PLAYER_HAIR 0
#define SPT_PLAYER_SKIN 1
#define SPT_PLAYER_CHAIR 2
#define SPT_PLAYER_OUTLINE 16
#define SPT_ELEVATOR 3

//-----------------------------------------------------------------------------
// Enumérations
//-----------------------------------------------------------------------------

// Conditions de visibilité d'un objet
enum ItemCondition
{
	ITEM_COND_LIGHT_ON,
	ITEM_COND_LIGHT_OFF,
	ITEM_COND_ELECTRICITY_ON,
	ITEM_COND_ELECTRICITY_OFF,
	ITEM_COND_DISABLED,
};

// Etats du joueur
enum PlayerState
{
	PLAYER_STATE_IDLE,
	PLAYER_STATE_MOVE,
	PLAYER_STATE_ACTION,
	PLAYER_STATE_FALL,
};

// Etats des élévateurs
enum ElevatorState
{
	ELEVATOR_STATE_MOVE,
	ELEVATOR_STATE_STAND,
};

//-----------------------------------------------------------------------------
// Structures de donnée
//-----------------------------------------------------------------------------

// Structure de description d'une pièce
struct RoomDefinition
{
	u8 X;
	u8 Y;
	u8 Width;
	u8 Height;
	const u8 *Layout;
	const c8 *Name;
	u8 NextLvlIdx;
};

// Structure des paramètres du joueur
struct PlayerDefinition
{
	u8 X;					// Coordonnée X
	u8 Y;					// Coordonnée Y
	i8 VelocityY; // Vélocité vertical
	u8 State;			// État du personnage
	bool InAir;		// Est-ce que le personnage est en train de sauter
};

// Structure des paramètres de l'élévateur
struct ElevatorDefinition
{
	u8 X;
	u8 Y;
	i8 VelocityY;
	u8 State;
	u8 Timer;
};

// Structure d'un objet visible sous condition
struct VisibleObject
{
	u8 X;
	u8 Y;
	u8 Tile;
	u8 ItemCondition;
};