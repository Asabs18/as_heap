#include <assert.h>
#include <stdbool.h>
#include "munit_ex.h"
#include "bumpAlloc.h"
#include "binding.h"

static MunitResult
freeFreesItem(const MunitParameter params[], void* data) {
	void* ptr = mallocSUT(8);
	
	freeSUT(ptr);

	munit_assert_ptr_not_null(ptr);
	return MUNIT_OK;
}

//declares the test suite to run each test in this file
MunitTest freeCheck_tests[] = {
	munit_ex_register_test(freeFreesItem, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};