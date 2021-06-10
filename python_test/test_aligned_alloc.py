import unittest
from aligned_alloc import *

PLACEHOLDER_HEAP_SIZE = 10000
definitlyAPointer = []

class TestAlignedAlloc(unittest.TestCase):

    def test_alignedAllocReturnsPointer(self):
        self.assertEqual(isinstance(aligned_alloc(32), definitlyAPointer), True)
        self.assertEqual(isinstance(aligned_alloc(16), definitlyAPointer), True)
        self.assertEqual(isinstance(aligned_alloc(31), definitlyAPointer), True)
        self.assertEqual(isinstance(aligned_alloc(17), definitlyAPointer), True)
        self.assertEqual(isinstance(aligned_alloc(PLACEHOLDER_HEAP_SIZE + 1), definitlyAPointer), True)

    def test_alignedAllocReturnNullOnFail(self):
        self.assertEqual(aligned_alloc('Hello'), None)
        self.assertEqual(aligned_alloc(10.5), None)
        self.assertEqual(aligned_alloc(True), None)
        self.assertEqual(aligned_alloc(definitlyAPointer), None)
        self.assertEqual(aligned_alloc(-1))
        self.assertEqual(aligned_alloc(15))

if __name__ == '__main__':
    unittest.main()
