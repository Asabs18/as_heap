#include <assert.h>
#include "munit_ex.h"
//include free.h


static MunitResult
testTest(const MunitParameter params[], void* data) {
	return MUNIT_SKIP;
}

//declares the test suite to run each test in this file
MunitTest freeCheck_tests[] = {
	munit_ex_register_test(testTest, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};