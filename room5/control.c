#include "msxgl.h"
#include "input.h"
#include "control.h"

//.............................................................................
//
//  GESTION DES CONTRÔLEURS (clavier et joysticks)
//
//.............................................................................

struct ControlEntry
{
	u8 Key;
	u8 Joystick;
};

const struct ControlEntry g_ControlEntries[INPUT_MAX] = 
{
	{ KEY_UP,    JOY_INPUT_DIR_UP },
	{ KEY_RIGHT, JOY_INPUT_DIR_RIGHT },
	{ KEY_DOWN,  JOY_INPUT_DIR_DOWN },
	{ KEY_LEFT,  JOY_INPUT_DIR_LEFT },
	{ KEY_SPACE, JOY_INPUT_TRIGGER_A },
	{ KEY_ESC,   JOY_INPUT_TRIGGER_B },
};

//-----------------------------------------------------------------------------
// Check if the given input is pressed
bool isInputPressed(enum INPUT_ID in)
{
	if (Keyboard_IsKeyPressed(g_ControlEntries[in].Key))
		return TRUE;

	u8 joy = g_ControlEntries[in].Joystick;
	if ((Joystick_Read(JOY_PORT_1) & joy) == 0)
		return TRUE;
	if ((Joystick_Read(JOY_PORT_2) & joy) == 0)
		return TRUE;

	return FALSE;
}

//-----------------------------------------------------------------------------
// Check if the given input is just pushed
bool isInputPushed(enum INPUT_ID in)
{
	if (Keyboard_IsKeyPushed(g_ControlEntries[in].Key))
		return TRUE;

	u8 joy = g_ControlEntries[in].Joystick;

	if (in < INPUT_BUTTON_A)
	{
		if (Joystick_GetDirectionChange(JOY_PORT_1) == joy)
			return TRUE;
		if (Joystick_GetDirectionChange(JOY_PORT_2) == joy)
			return TRUE;
	}
	else
	{
		if (Joystick_IsButtonPushed(JOY_PORT_1, joy))
			return TRUE;
		if (Joystick_IsButtonPushed(JOY_PORT_2, joy))
			return TRUE;
	}

	return FALSE;
}