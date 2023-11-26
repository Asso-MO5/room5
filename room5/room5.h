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
#define MAX_MANUAL_ELEVATOR 8
#define ELEVATOR_STAND 20
#define MAX_VISIBLE_OBJECTS 16
#define MAX_ELECTRIC_WALL 16
#define MAX_NOT_ELECTRIC_WALL 16
#define RESET_DURATION 50
#define MAX_SWITCH_TIMER 127

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
	ITEM_COND_CUPBOARD,
	ITEM_COND_CUPBOARD_LIGHT,
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

// direction de l'histoire

enum StoryDirection
{
	THEME_HOSPITAL = 0,
	THEME_ALIEN,
	THEME_MATRIX, // follow the white rabbit
	THEME_NUMBER, //
};

enum ElevatorDirection
{
	ELEVATOR_DIRECTION_UP,
	ELEVATOR_DIRECTION_DOWN,
};

//-----------------------------------------------------------------------------
// Structures de donnée
//-----------------------------------------------------------------------------

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

// Structure d'un element visible si l'électricité est allumée
struct ActiveObject
{
	u8 X;
	u8 Y;
	u8 Tile;
};

struct SwitchTimer
{
	u8 X;
	u8 Y;
	u8 Timer;
};