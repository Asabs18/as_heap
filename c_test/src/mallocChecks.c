#include <assert.h>
#include "munit_ex.h"
//include malloc.h

#define MAXHEAPSIZE = 1000

static MunitResult
mallocReturnsNullOnFail1(const MunitParameter params[], void* data){
	size_t bytes = 0;

	int output = malloc(bytes);

	munit_assert(output == NULL);
	return MUNIT_OK;
}

static MunitResult
mallocReturnsNullOnFail2(const MunitParameter params[], void* data){
	size_t bytes = MAXHEAPSIZE + 1;

	int output = malloc(bytes);

	munit_assert(output == NULL);
	return MUNIT_OK;
}

static MunitResult
mallocReturnsNullOnFail3(const MunitParameter params[], void* data){
	size_t bytes = -1;

	int output = malloc(bytes);

	munit_assert(output == NULL);
	return MUNIT_OK;
}

//declares the test suite to run each test in this file
MunitTest mallocCheck_tests[] = {
	munit_ex_register_test(mallocReturnsNullOnFail1, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(mallocReturnsNullOnFail2, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(mallocReturnsNullOnFail3, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};