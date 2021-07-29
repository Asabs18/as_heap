#include <assert.h>
#include <stdbool.h>
#include "munit_ex.h"
//include malloc.h

#define MAXHEAPSIZE 1000
void* malloc(size_t bytes){
	return NULL;
}

static MunitResult
mallocReturnsNullAllocZero(const MunitParameter params[], void* data){
	size_t bytes = 0;

	void* output = malloc(bytes);

	munit_assert(output == NULL);
	return MUNIT_OK;
}

static MunitResult
mallocReturnsByteOnAlloc(const MunitParameter params[], void* data){
	size_t bytes = 1;

	void* output = malloc(bytes);

	munit_assert(sizeof(output) == 1);
	return MUNIT_OK;
}

static MunitResult
mallocReturnsCorrectBytes(const MunitParameter params[], void* data){
	bool fail = false;

	for(int i = 0; i < 500; i++){
		if(sizeof(malloc(i)) != i){
			fail = true;
		}
	}

	munit_assert(fail == false);
	return MUNIT_OK;
}

//declares the test suite to run each test in this file
MunitTest mallocCheck_tests[] = {
	munit_ex_register_test(mallocReturnsNullAllocZero, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(mallocReturnsByteOnAlloc, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(mallocReturnsCorrectBytes, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),

	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};