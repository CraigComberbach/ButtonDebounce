#include "BDB_ButtonDebounce.h"
#include "unity.h"

//Mocked callback function to track state changes
void MockCallbackFunction(uint8_t switchId, SwitchState state)
{
	//Mock function logic (if needed, you can use global variables to check the calls)
}

void setUp(void)
{
}

void tearDown(void)
{
}

void test_SwitchInit_InitializesProperly(void)
{
	Switch testSwitch;
	Switch_Init(&testSwitch, 50, 100, MockCallbackFunction);

	TEST_ASSERT_EQUAL_UINT32(50, testSwitch.debounceDelay);
	TEST_ASSERT_EQUAL_UINT32(100, testSwitch.holdDelay);
	TEST_ASSERT_EQUAL(SWITCH_UNPRESSED, testSwitch.state);
	TEST_ASSERT_EQUAL_PTR(MockCallbackFunction, testSwitch.callback);
}

void test_SwitchUpdate_ToPressed(void)
{
	Switch testSwitch;
	Switch_Init(&testSwitch, 50, 100, MockCallbackFunction);

	//Simulate input to trigger transition to PRESSED state
	Switch_Update(&testSwitch, true, 51);//Assume 51ms has passed, exceeding debounce delay

	TEST_ASSERT_EQUAL(SWITCH_PRESSED, testSwitch.state);
}

void test_TransitionFunctions_CallCallbackCorrectly(void)
{
	//This test would verify if the callback function is called correctly during transitions
	//You might need to use a global variable or a mock framework to capture the callback invocation
}
