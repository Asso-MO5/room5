#pragma once
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
#define MUSIC_ADDRESS 0xD000
#define SFX_ADDRESS 0xE000
#define LANG_CURSORX 8
#define LANG_CURSORY 6
#define CODE_CURSORX 8
#define CODE_CURSORY 6
#define CODE_VAL_OFFSET 8
#define PLAYER_CODE_SIZE 16
#define BONUS_TIME 30 // Time gained when getting a bonus

// Numéro de sprite
#define SPT_ELEVATOR 0
#define SPT_PLAYER_HAIR 8
#define SPT_PLAYER_SKIN 9
#define SPT_PLAYER_CHAIR 10
#define SPT_PLAYER_OUTLINE 11
#define SPT_TV 12
#define SPT_CAMERA 16
#define SPT_INVENTORY 28 // 28-31

#define SPT_CAMERA_MAX 12
#define SPT_INVENTORY_Y 176

// Couleurs
enum COLOR_ID
{
	COLOR_BACKGROUND = 0,
	COLOR_SCENE_NIGHT_DARK,
	COLOR_PLAYER_NIGHT_DARK,
	COLOR_SCENE_NIGHT_MED,
	COLOR_PLAYER_NIGHT_MED,
	COLOR_PLAYER_NIGHT_LIGHT,
	COLOR_PLAYER_DAY_DARK,
	COLOR_CAMERA,
	COLOR_NIGHTLIGHT_ON,
	COLOR_SCENE_DAY_DARK,
	COLOR_SCENE_DAY_MED,
	COLOR_PLAYER_DAY_MED,
	COLOR_TEXT,
	COLOR_PLAYER_DAY_LIGHT,
	COLOR_NIGHTLIGHT_OFF,
	COLOR_ELEVATOR_ON,
	COLOR_ELEVATOR_OFF,
	COLOR_TV,
	COLOR_ID_MAX,
};

typedef bool (*animCallback)(void);

//-----------------------------------------------------------------------------
// Énumérations
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

struct TVData
{
	u8 X;
	u8 Y;
	bool Activate;
	u8 Count;
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

struct SaveData
{
	u8 currentLevel;
	u16 currentTime;
	u8 themes[3];
};
