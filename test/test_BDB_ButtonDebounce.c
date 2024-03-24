#include "BDB_ButtonDebounce.h"
#include "unity.h"

/***************************Test Set/Get/Wrappers*****************************/
void TestSetBDB_Selves_debounceDelay(BDB_ObjectList_t ID, uint32_t NewValue);
uint32_t TestGetBDB_Selves_debounceDelay(BDB_ObjectList_t ID);

void TestSetBDB_Selves_holdDelay(BDB_ObjectList_t ID, uint32_t NewValue);
uint32_t TestGetBDB_Selves_holdDelay(BDB_ObjectList_t ID);

void TestSetBDB_Selves_lastStateChangeTime(BDB_ObjectList_t ID, uint32_t NewValue);
uint32_t TestGetBDB_Selves_lastStateChangeTime(BDB_ObjectList_t ID);

void TestSetBDB_Selves_state(BDB_ObjectList_t ID, SwitchState NewValue);
SwitchState TestGetBDB_Selves_state(BDB_ObjectList_t ID);

void TestSetBDB_Selves_lastInput(BDB_ObjectList_t ID, bool NewValue);
bool TestGetBDB_Selves_lastInput(BDB_ObjectList_t ID);

void TestSetBDB_Selves_callback(BDB_ObjectList_t ID, SwitchStateCallback NewValue);
SwitchStateCallback TestGetBDB_Selves_callback(BDB_ObjectList_t ID);

/*********************************Test Mocks**********************************/
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
	BDB_Object_t *testSwitch;
	Switch_Init(testSwitch, 50, 100, MockCallbackFunction);

	TEST_ASSERT_EQUAL_UINT32(50, TestGetBDB_Selves_debounceDelay(BDB_));
	TEST_ASSERT_EQUAL_UINT32(100, TestGetBDB_Selves_holdDelay(BDB_));
	TEST_ASSERT_EQUAL(SWITCH_UNPRESSED, TestGetBDB_Selves_state(BDB_));
	TEST_ASSERT_EQUAL_PTR(MockCallbackFunction, TestGetBDB_Selves_callback(BDB_));
}

void test_SwitchUpdate_ToPressed(void)
{
	BDB_Object_t *testSwitch;
	Switch_Init(testSwitch, 50, 100, MockCallbackFunction);

	//Simulate input to trigger transition to PRESSED state
	Switch_Update(testSwitch, true, 51);//Assume 51ms has passed, exceeding debounce delay

	TEST_ASSERT_EQUAL(SWITCH_PRESSED, TestGetBDB_Selves_state(BDB_));
}

void test_TransitionFunctions_CallCallbackCorrectly(void)
{
	//This test would verify if the callback function is called correctly during transitions
	//You might need to use a global variable or a mock framework to capture the callback invocation
}
