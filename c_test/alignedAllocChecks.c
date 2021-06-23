#include <assert.h>
#include "munit_ex.h"

//Command Type correctly returns C command 
static MunitResult
testTest(const MunitParameter params[], void* data) {
	return MUNIT_SKIP;
}

//declares the test suite to run each test in this file
MunitTest alignedAllocCheck_tests[] = {
	munit_ex_register_test(testTest, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};