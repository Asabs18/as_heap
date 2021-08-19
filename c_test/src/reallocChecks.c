#include <assert.h>
#include "munit_ex.h"
#include "bumpAlloc.h"
#include "binding.h"

#define MAXHEAPSIZE 1000

static MunitResult
reallocReturnsNullOnFail1(const MunitParameter params[], void* data){ //change name from fail
	void* oldPtr = NULL;
	size_t newBytes = 10;

	void* output = reallocSUT(oldPtr, newBytes);

	munit_assert_ptr_not_null(output);
	freeSUT(output);
	return MUNIT_OK;
}

static MunitResult
reallocReturnsNullOnFail2(const MunitParameter params[], void* data){
	void* oldPtr = NULL;
	size_t newBytes = 0;

	void* output = reallocSUT(oldPtr, newBytes);

	//munit_assert_ptr_null(output);
	freeSUT(output);
	return MUNIT_SKIP; //review this test
}

static MunitResult
reallocGrowsHeap(const MunitParameter params[], void* data){
	void* oldPtr = NULL;
	size_t newBytes = MAXHEAPSIZE + 1;

	void* output = reallocSUT(oldPtr, newBytes);

	munit_assert_ptr_not_null(output);
	freeSUT(output);
	return MUNIT_OK;
}


static MunitResult
reallocReturnsNotNullOnSuccess(const MunitParameter params[], void* data){
	void* oldPtr = malloc(4);
	size_t newBytes = 8;

	void* output = reallocSUT(oldPtr, newBytes);

	munit_assert_ptr_not_null(output);
	freeSUT(output);
	return MUNIT_OK;
}

static MunitResult
reallocWorksMultipleTimes(const MunitParameter params[], void* data){
	void* oldPtr = malloc(4);
	size_t newBytes = 8;

	void* output = reallocSUT(oldPtr, newBytes);
	newBytes+=2;
	output = reallocSUT(output, newBytes);
	newBytes+=2;
	output = reallocSUT(output, newBytes);

	munit_assert_ptr_not_null(output);
	freeSUT(output);
	return MUNIT_OK;
}


//declares the test suite to run each test in this file
MunitTest reallocCheck_tests[] = {
	munit_ex_register_test(reallocReturnsNullOnFail1, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(reallocGrowsHeap, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(reallocReturnsNotNullOnSuccess, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(reallocWorksMultipleTimes, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(reallocReturnsNullOnFail2, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};