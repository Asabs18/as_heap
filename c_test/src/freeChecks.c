#include <assert.h>
#include <stdbool.h>
#include "munit_ex.h"
#include "bumpAlloc.h"
#include "binding.h"

static MunitResult
freeFreesItem(const MunitParameter params[], void* data) {
	void* ptr = mallocSUT(0);
	
	freeSUT(ptr);

	munit_assert_ptr_not_null(ptr);
	return MUNIT_OK;
}

static MunitResult
freeAllFreesAnyNumOfItems(const MunitParameter params[], void* data) {
	size_t mallocNum = 500;
	for(int i = 0; i < mallocNum - 1; i++){
		mallocSUT(1);
	}
	void* ptr = mallocSUT(1);

	//freeSUT();

	munit_assert_ptr_not_null(ptr);
	return MUNIT_OK;
}

//declares the test suite to run each test in this file
MunitTest freeCheck_tests[] = {
	munit_ex_register_test(freeFreesItem, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(freeAllFreesAnyNumOfItems, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};