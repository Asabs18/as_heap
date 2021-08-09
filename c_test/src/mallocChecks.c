#include <assert.h>
#include <stdbool.h>
#include "munit_ex.h"
#include "bumpAlloc.h"


static MunitResult
mallocReturnsNullAllocZero(const MunitParameter params[], void* data){
	size_t bytes = 0;

	void* output = malloc(bytes);

	munit_assert_ptr_null(output);
	return MUNIT_OK;
}

static MunitResult
mallocReturnsByteOnAlloc(const MunitParameter params[], void* data){
	size_t bytes = 1;

	void* output = malloc(bytes);

	munit_assert_ptr_not_null(output);
	free(output);
	return MUNIT_OK;
}

static MunitResult
mallocCalledManyTimes(const MunitParameter params[], void* data){
	bool fail = false;
	size_t size = 2;

	//try and pass in max index
	for(int i = 0; i < 500; i++){
		void* ptr = malloc(i * size);
		if(ptr == NULL){
			fail = true;
		}
	}
	b_freeAll();
	munit_assert_false(fail);
	return MUNIT_OK;
}

static MunitResult
mallocCallAndFreeManyTimes(const MunitParameter params[], void* data){
	bool fail = false;
	size_t size = 2;

	for(int i = 0; i < 500; i++){
		void* ptr = malloc(i * size);
		if(ptr == NULL){
			fail = true;
		}
		free(ptr);	
	}
	munit_assert_false(fail);
	return MUNIT_SKIP;
}

static MunitResult
mallocFreeThenMallocNotNull(const MunitParameter params[], void* data){
	size_t size = 10;
	void* ptr = malloc(size);
	free();
	init();
	ptr = malloc(size);

	munit_assert_ptr_not_null(ptr);
	return MUNIT_OK;
}

static MunitResult
mallocTwiceSameSizeNotNull(const MunitParameter params[], void* data){
	size_t size = 10;
	void* ptr = malloc(size);
	ptr = malloc(size);

	munit_assert_ptr_not_null(ptr);
	return MUNIT_OK;
}

//declares the test suite to run each test in this file
MunitTest mallocCheck_tests[] = {
	munit_ex_register_test(mallocReturnsNullAllocZero, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(mallocReturnsByteOnAlloc, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(mallocCalledManyTimes, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(mallocCallAndFreeManyTimes, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(mallocFreeThenMallocNotNull, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(mallocTwiceSameSizeNotNull, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};