from logging import PlaceHolder
import unittest
from malloc import *

PLACEHOLDER_HEAP_SIZE = 10000
definitlyAPointer = []

class TestMalloc(unittest.TestCase):
    def test_mallocReturnsPointer(self):
        self.assertEqual(isinstance(malloc(5), definitlyAPointer), True)
        self.assertEqual(isinstance(malloc(100), definitlyAPointer), True)
        self.assertEqual(isinstance(malloc(PLACEHOLDER_HEAP_SIZE + 1), definitlyAPointer), True)

    def test_mallocThrowsException(self):
        self.assertRaises(ValueError, malloc, 0)
        self.assertRaises(ValueError, malloc, -10)
        self.assertRaises(ValueError, malloc, -10.5)

    def test_mallocReturnNullOnFail(self):
        self.assertEqual(malloc('Hello'), None)
        self.assertEqual(malloc(10.5), None)
        self.assertEqual(malloc(True), None)
        self.assertEqual(malloc(definitlyAPointer), None)

if __name__ == '__main__':
    unittest.main()
