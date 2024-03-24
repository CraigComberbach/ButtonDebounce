#ifndef BDB_BUTTONDEBOUNCE_H
#define BDB_BUTTONDEBOUNCE_H
/**********Include Headers************/
#include <stdbool.h>
#include <stdint.h>
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
typedef enum
{
	SWITCH_UNPRESSED,
	SWITCH_PRESSED,
	SWITCH_HELD,
	SWITCH_RELEASED
} SwitchState;

typedef void (*SwitchStateCallback)(uint8_t switchId, SwitchState state);

/*********Object Definition***********/
typedef struct Switch BDB_Object_t;

/****Module Function Prototypes*******/
void Switch_Init(BDB_Object_t *sw, uint32_t debounceDelay, uint32_t holdDelay, SwitchStateCallback callback);
void Switch_Update(BDB_Object_t *sw, bool currentInput, uint32_t currentTime);
void Process_Switches(BDB_Object_t *switchArray, uint8_t numSwitches, bool *inputs, uint32_t currentTime);

#endif//BDB_BUTTONDEBOUNCE_H
