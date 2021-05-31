import unittest
from malloc import *

class TestTest(unittest.TestCase):

    def test_mallocReturnsInput(self):
        #Should Pass
        self.assertEqual(malloc(5), 5)
        self.assertEqual(malloc(100), 100)

        #Should Fail
        self.assertNotEqual(malloc(5), 4)
        self.assertNotEqual(malloc(5), -2)

        #Should Throw Exception
        self.assertRaises(ValueError, malloc, -1)

if __name__ == '__main__':
    unittest.main()