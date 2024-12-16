//=============================================================================
// DEFINITIONS
//=============================================================================

enum INPUT_ID
{
	INPUT_UP = 0,
	INPUT_RIGHT,
	INPUT_DOWN,
	INPUT_LEFT,
	INPUT_BUTTON_A,
	INPUT_BUTTON_B,
	INPUT_MAX,
};

//=============================================================================
// PROTOTYPES
//=============================================================================

// Check if the given input is pressed
bool isInputPressed(enum INPUT_ID in);

// Check if the given input is just pushed
bool isInputPushed(enum INPUT_ID in);