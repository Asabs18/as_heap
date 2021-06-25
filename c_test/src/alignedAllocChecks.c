#include <assert.h>
#include "munit_ex.h"
//include aligned_alloc

#define MAXHEAPSIZE = 1000

static MunitResult
alignedAllocReturnsNullOnFail1(const MunitParameter params[], void* data){
	size_t bytes = 0;

	int output = aligned_alloc(bytes);

	munit_assert(output == NULL);
	return MUNIT_OK;
}

static MunitResult
alignedAllocReturnsNullOnFail2(const MunitParameter params[], void* data){
	size_t bytes = MAXHEAPSIZE + 1;

	int output = aligned_alloc(bytes);

	munit_assert(output == NULL);
	return MUNIT_OK;
}

static MunitResult
alignedAllocReturnsNullOnFail3(const MunitParameter params[], void* data){
	size_t bytes = -1;

	int output = aligned_alloc(bytes);

	munit_assert(output == NULL);
	return MUNIT_OK;
}

//declares the test suite to run each test in this file
MunitTest alignedAllocCheck_tests[] = {
	munit_ex_register_test(alignedAllocReturnsNullOnFail1, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(alignedAllocReturnsNullOnFail2, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(alignedAllocReturnsNullOnFail3, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};