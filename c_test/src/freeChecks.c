#include <assert.h>
#include <stdbool.h>
#include "munit_ex.h"
#include "bumpAlloc.h"

static MunitResult
freeFreesItem(const MunitParameter params[], void* data) {
	void* ptr = malloc(0);
	
	free(ptr);

	munit_assert_ptr_not_null(ptr);
	return MUNIT_OK;
}

//JUST FOR B_FREE
static MunitResult
freeAllFreesMultipleItems(const MunitParameter params[], void* data) {
	bool fail = false;
	void* ptr1 = malloc(sizeof(int));
	void* ptr2 = malloc(sizeof(int));
	void* ptr3 = malloc(sizeof(int));
	
	free();

	if(ptr1 != NULL || ptr2 != NULL || ptr3 != NULL){
		fail = true;
	}
	munit_assert_false(fail);
	return MUNIT_OK;
}

static MunitResult
freeAllFreesAnyNumOfItems(const MunitParameter params[], void* data) {
	size_t mallocNum = 500;
	for(int i = 0; i < mallocNum - 1; i++){
		malloc(1);
	}
	void* ptr = malloc(1);

	free();

	munit_assert_ptr_not_null(ptr);
	return MUNIT_OK;
}

//declares the test suite to run each test in this file
MunitTest freeCheck_tests[] = {
	munit_ex_register_test(freeFreesItem, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(freeAllFreesMultipleItems, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(freeAllFreesAnyNumOfItems, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};