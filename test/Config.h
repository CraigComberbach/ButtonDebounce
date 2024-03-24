#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>

#define ENABLE_BUTTON_DEBOUNCE_TEST_WRAPPERS

//Buttons Debounce Library
#define BUTTON_DEBOUNCE_MAJOR 0
#define BUTTON_DEBOUNCE_MINOR 0
#define BUTTON_DEBOUNCE_PATCH 0

//Buttons
typedef enum
{
	BDB_,
	NUMBER_OF_BUTTON_DEBOUNCE_OBJECTS
} BDB_ObjectList_t;

typedef int_fast8_t ErrorCode_t;
#define SUCCESS 0

#endif//CONFIG_H
