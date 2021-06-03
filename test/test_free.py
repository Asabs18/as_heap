import unittest
from free import *

definitlyAPointer = []

class TestFree(unittest.TestCase):

    def test_freeReturnsNothing(self):
        self.assertEqual(free(definitlyAPointer), None)
        self.assertEqual(free(10), None)
        self.assertEqual(free(True), None)
        self.assertEqual(free(10.5), None)

    def test_freeDestroysPointer(self):
        self.assertEqual(definitlyAPointer, [])
        free(definitlyAPointer)
        self.assertEqual(definitlyAPointer, None)
        definitlyAPointer = []

    def test_freeTwiceStillNull(self):
        free(definitlyAPointer)
        self.assertEqual(definitlyAPointer, None)
        free(definitlyAPointer)
        self.assertEqual(definitlyAPointer, None)
        definitlyAPointer = []

if __name__ == '__main__':
    unittest.main()
