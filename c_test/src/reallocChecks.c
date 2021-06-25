#include <assert.h>
#include "munit_ex.h"

#define MAXHEAPSIZE 1000
void* realloc(void* oldPtr, size_t newBytes){
	return NULL;
}


static MunitResult
reallocReturnsNullOnFail1(const MunitParameter params[], void* data){
	void* oldPtr = NULL;
	size_t newBytes = 10;

	void* output = realloc(oldPtr, newBytes);

	munit_assert(output == NULL);
	return MUNIT_OK;
}

static MunitResult
reallocReturnsNullOnFail2(const MunitParameter params[], void* data){
	void* oldPtr = NULL;
	size_t newBytes = 10;

	void* output = realloc(oldPtr, newBytes);

	munit_assert(output == NULL);
	return MUNIT_OK;
}

static MunitResult
reallocReturnsNullOnFail3(const MunitParameter params[], void* data){
	void* oldPtr = NULL;
	size_t newBytes = MAXHEAPSIZE + 1;

	void* output = realloc(oldPtr, newBytes);

	munit_assert(output == NULL);
	return MUNIT_OK;
}

static MunitResult
reallocReturnsNullOnFail4(const MunitParameter params[], void* data){
	void* oldPtr = NULL;
	size_t newBytes = 0;

	void* output = realloc(oldPtr, newBytes);

	munit_assert(output == NULL);
	return MUNIT_OK;
}


//declares the test suite to run each test in this file
MunitTest reallocCheck_tests[] = {
	munit_ex_register_test(reallocReturnsNullOnFail1, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(reallocReturnsNullOnFail2, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(reallocReturnsNullOnFail3, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(reallocReturnsNullOnFail4, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};