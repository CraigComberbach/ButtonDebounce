/******************************************************************************
 * Version History:
 * v0.0.0	2024-03-24	Craig Comberbach
 * 	Testing performed with Ceedling 0.32.0-9b8d8a9 pre-release and GCC 13.2.0
 *	First version - Generated by AI (ChatGPT4)
 ******************************************************************************/
/************Header Files*************/
#include "BDB_ButtonDebounce.h"

/********Semantic Versioning**********/
#if BUTTON_DEBOUNCE_MAJOR != 0
	#error "ButtonDebounce library major revision update is available"
#elif BUTTON_DEBOUNCE_MINOR != 0
	#error "ButtonDebounce library minor revision update is available"
#elif BUTTON_DEBOUNCE_PATCH != 0
	#error "ButtonDebounce library patch revision update is available"
#endif
/***********Magic Numbers*************/
/************Enumerations*************/
/**********Type Definitions***********/
/*************Structures**************/
/**********Global Variables***********/
/*********Object Definition***********/
/*****Local Function Prototypes*******/
/*********Main Body Of Code***********/
void Transition_ToPressed(Switch* sw, uint32_t currentTime)
{
	sw->state = SWITCH_PRESSED;
	sw->lastStateChangeTime = currentTime;
	if(sw->callback)
	{
		sw->callback(sw - sw, SWITCH_PRESSED);
	}
}

void Transition_ToReleased(Switch* sw, uint32_t currentTime)
{
	sw->state = SWITCH_RELEASED;
	sw->lastStateChangeTime = currentTime;
	if(sw->callback)
	{
		sw->callback(sw - sw, SWITCH_RELEASED);
	}
}

void Transition_ToHeld(Switch* sw, uint32_t currentTime)
{
	sw->state = SWITCH_HELD;
	//No update to lastStateChangeTime to maintain the hold state
	if(sw->callback)
	{
		sw->callback(sw - sw, SWITCH_HELD);
	}
}

void Transition_ToUnpressed(Switch* sw, uint32_t currentTime)
{
	sw->state = SWITCH_UNPRESSED;
	sw->lastStateChangeTime = currentTime;
	if(sw->callback)
	{
		sw->callback(sw - sw, SWITCH_UNPRESSED);
	}
}

void Switch_Update(Switch* sw, bool currentInput, uint32_t currentTime)
{
	bool debounceTimeElapsed = (currentTime - sw->lastStateChangeTime) > sw->debounceDelay;
	if(currentInput != sw->lastInput)
	{
		sw->lastStateChangeTime = currentTime;
	}
	sw->lastInput = currentInput;

	//State transition logic
	switch(sw->state)
	{
		case SWITCH_UNPRESSED:
			if(currentInput && debounceTimeElapsed)
			{
				Transition_ToPressed(sw, currentTime);
			}
			break;
		case SWITCH_PRESSED:
			if(!currentInput && debounceTimeElapsed)
			{
				Transition_ToReleased(sw, currentTime);
			}
			else if(currentInput && (currentTime - sw->lastStateChangeTime) > sw->holdDelay)
			{
				Transition_ToHeld(sw, currentTime);
			}
			break;
		case SWITCH_HELD:
			if(!currentInput && debounceTimeElapsed)
			{
				Transition_ToReleased(sw, currentTime);
			}
			break;
		case SWITCH_RELEASED:
			if(currentInput && debounceTimeElapsed)
			{
				Transition_ToPressed(sw, currentTime);
			}
			else if(!currentInput && debounceTimeElapsed)
			{
				Transition_ToUnpressed(sw, currentTime);
			}
			break;
	}
}

#ifdef ENABLE_BUTTON_DEBOUNCE_TEST_WRAPPERS

#endif
