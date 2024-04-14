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

#define MAX_VISIBLE_OBJECTS 16
#define MAX_ELECTRIC_WALL 16
#define MAX_NOT_ELECTRIC_WALL 16
#define RESET_DURATION 50
#define MAX_SWITCH_TIMER 127
#define MAX_TILE_ANIMATION 10
#define MAX_TEXT_COORD 8
#define TEXT_MODE_DEFAULT 0
#define TEXT_MODE_PHONE 1
#define TEXT_MODE_TALK 2

typedef bool (*animCallback)(void);

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

// direction de l'histoire

enum StoryDirection
{
	THEME_HOSPITAL = 0,
	THEME_ALIEN,
	THEME_MATRIX, // follow the white rabbit
	THEME_NUMBER, //
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
	bool isLeft;	// Est-ce que le personnage est orienté vers la gauche
	bool canMove; // Est-ce que le personnage peut bouger
};
// Structure d'un objet visible sous condition
struct VisibleObject
{
	u8 X;
	u8 Y;
	u8 Tile;
	u8 ItemCondition;
};

struct SwitchTimer
{
	u8 X;
	u8 Y;
	u8 Timer;
};

struct TileAnimation
{
	u8 Width;
	u8 Height;
	u8 FrameCount;
	u8 LoopCount;
	u8 *FrameData;
};

struct TileAnimationInstance
{
	u8 X;
	u8 Y;
	u8 FrameNumber;
	u8 LoopNumber;
	bool isPlaying;
	struct TileAnimation const *Animation;
	animCallback OnAnimationEnd;
};

struct TextCoordInstance
{
	u8 X;
	u8 Y;
	u8 Key;
	u8 Mode;
};