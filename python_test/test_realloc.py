import unittest
from realloc import *

PLACEHOLDER_HEAP_SIZE = 10000
definitlyAPointer = []

class TestRealloc(unittest.TestCase):

    def test_reallocReturnsPointer(self):
        self.assertEqual(isinstance(realloc(16, 32), definitlyAPointer), True)
        self.assertEqual(isinstance(realloc(16, 16), definitlyAPointer), True)
        self.assertEqual(isinstance(realloc(16, 31), definitlyAPointer), True)
        self.assertEqual(isinstance(realloc(34, 17), definitlyAPointer), True)
        self.assertEqual(isinstance(realloc(16, PLACEHOLDER_HEAP_SIZE + 1), definitlyAPointer), True)

    def test_test(self):
        self.assertTrue(True)
        
    
    def test_reallocReturnsNothingOnFail(self):
        self.assertEqual(realloc(16, 'Hello'), None)
        self.assertEqual(realloc(16, 10.5), None)
        self.assertEqual(realloc(16, True), None)
        self.assertEqual(realloc(16, definitlyAPointer), None)
        self.assertEqual(realloc(-10, 0), None)
        self.assertEqual(realloc(20, -10), None)

if __name__ == '__main__':
    unittest.main()
