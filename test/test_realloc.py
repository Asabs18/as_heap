import unittest
from realloc import *

class TestTest(unittest.TestCase):

    def test_reallocReturnsSecondNumber(self):
        #Should Pass
        self.assertEqual(realloc(32, 16), 16)
        self.assertEqual(realloc(5, 32), 32)

        #Should Fail
        self.assertNotEqual(realloc(7, 32), 7)
        self.assertNotEqual(realloc(80, 20), 60)

        #Should Throw Exception
        self.assertRaises(ValueError, realloc, -10, 0)
        self.assertRaises(ValueError, realloc, 20, -10)

if __name__ == '__main__':
    unittest.main()