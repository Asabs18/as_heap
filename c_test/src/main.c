#include "as_heap.h"
#include "munit_ex.h"
#include "mallocChecks.h"
#include "reallocChecks.h"
#include "freeChecks.h"
#include "alignedAllocChecks.h"

///main file for unit testing in c///

const MunitSuite as_heapTestSuite[] = {
	{ munit_ex_register_sub_suite(mallocCheck , NULL) },
	{ munit_ex_register_sub_suite(freeCheck, NULL) },
	//{ munit_ex_register_sub_suite(alignedAllocCheck, NULL) },
	{ munit_ex_register_sub_suite(reallocCheck, NULL) },
	{ NULL }
};

//The root test suite calls the as_heap test suite
const MunitSuite root_test_suite = {
	munit_ex_register_empty_sub_suite(as_heap, as_heapTestSuite)
};

//main runs the root test suite
int main(int argc, char** argv) {
	int output = munit_suite_main(&root_test_suite, NULL, argc, argv);
	return output;
}