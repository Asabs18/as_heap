#include <assert.h>
#include "munit_ex.h"
//include free.h


static MunitResult
freeFreesItem(const MunitParameter params[], void* data) {
	void* item = malloc(8);
	
	free(item);

	munit_assert(sizeof(item) == 0);
	return MUNIT_OK;
}

//declares the test suite to run each test in this file
MunitTest freeCheck_tests[] = {
	munit_ex_register_test(freeFreesItem, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};