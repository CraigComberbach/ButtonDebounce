#ifndef BDB_BUTTONDEBOUNCE_H
#define BDB_BUTTONDEBOUNCE_H
/**********Include Headers************/
#include "Config.h"

/**********Add to config.h************/
/*
	//Buttons Debounce Library
	#define BUTTON_DEBOUNCE_MAJOR	0
	#define BUTTON_DEBOUNCE_MINOR	0
	#define BUTTON_DEBOUNCE_PATCH	0

//Buttons
typedef enum
{
	BDB_,
	NUMBER_OF_BUTTON_DEBOUNCE_OBJECTS
} BDB_ObjectList_t;
*/

/**********Add to config.c************/
/*
#ifndef BUTTON_DEBOUNCE_LIBRARY
	#error "You need to include the ButtonDebounce library for this code to compile"
#endif
*/

/********Semantic Versioning**********/
/***********Magic Numbers*************/
#define NO_NOTIFICATION NULL

/************Enumeration**************/
/**********Type Definitions***********/
/*********Object Definition***********/
/****Module Function Prototypes*******/
#include <stdbool.h>
#include <stdint.h>

typedef enum
{
	SWITCH_UNPRESSED,
	SWITCH_PRESSED,
	SWITCH_HELD,
	SWITCH_RELEASED
} SwitchState;

typedef void (*SwitchStateCallback)(uint8_t switchId, SwitchState state);

typedef struct
{
	uint32_t debounceDelay;
	uint32_t holdDelay;
	uint32_t lastStateChangeTime;
	SwitchState state;
	bool lastInput;
	SwitchStateCallback callback;
} Switch;

void Switch_Init(Switch* sw, uint32_t debounceDelay, uint32_t holdDelay, SwitchStateCallback callback);
void Switch_Update(Switch* sw, bool currentInput, uint32_t currentTime);
void Process_Switches(Switch* switchArray, uint8_t numSwitches, bool* inputs, uint32_t currentTime);

//State transition functions
void Transition_ToPressed(Switch* sw, uint32_t currentTime);
void Transition_ToReleased(Switch* sw, uint32_t currentTime);
void Transition_ToHeld(Switch* sw, uint32_t currentTime);
void Transition_ToUnpressed(Switch* sw, uint32_t currentTime);

#endif//BDB_BUTTONDEBOUNCE_H
