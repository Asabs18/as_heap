import unittest
from free import *

class TestTest(unittest.TestCase):

    def test_freeReturnsZero(self):
        #Should Pass
        self.assertEqual(free(32), 0)
        self.assertEqual(free(5), 0)

        #Should Fail
        self.assertNotEqual(free(1), 1)
        self.assertNotEqual(free(31), 32)

if __name__ == '__main__':
    unittest.main()