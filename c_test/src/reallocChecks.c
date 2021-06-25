#include <assert.h>
#include "munit_ex.h"

#define MAXHEAPSIZE = 1000

static MunitResult
reallocReturnsNullOnFail1(const MunitParameter params[], void* data){
	size_t bytes = -1;
	size_t newBytes = 10;

	int output = realloc(bytes, newBytes);

	munit_assert(output == NULL);
	return MUNIT_OK;
}

static MunitResult
reallocAllocReturnsNullOnFail2(const MunitParameter params[], void* data){
	size_t bytes = MAXHEAPSIZE + 1;
	size_t newBytes = 10;

	int output = realloc(bytes, newBytes);

	munit_assert(output == NULL);
	return MUNIT_OK;
}

static MunitResult
reallocAllocReturnsNullOnFail3(const MunitParameter params[], void* data){
	size_t bytes = 10;
	size_t newBytes = MAXHEAPSIZE + 1;

	int output = realloc(bytes, newBytes);

	munit_assert(output == NULL);
	return MUNIT_OK;
}

static MunitResult
reallocAllocReturnsNullOnFail4(const MunitParameter params[], void* data){
	size_t bytes = 0;
	size_t newBytes = 0;

	int output = realloc(bytes, newBytes);

	munit_assert(output == NULL);
	return MUNIT_OK;
}

static MunitResult
reallocAllocReturnsNullOnFail5(const MunitParameter params[], void* data){
	size_t bytes = 16;
	size_t newBytes = 0;

	int output = realloc(bytes, newBytes);

	munit_assert(output == NULL);
	return MUNIT_OK;
}


//declares the test suite to run each test in this file
MunitTest reallocCheck_tests[] = {
	munit_ex_register_test(reallocReturnsNullOnFail1, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(reallocReturnsNullOnFail2, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(reallocReturnsNullOnFail3, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(reallocReturnsNullOnFail4, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(reallocReturnsNullOnFail5, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};