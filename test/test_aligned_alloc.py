import unittest
from aligned_alloc import *

class TestTest(unittest.TestCase):

    def test_alignedAllocReturnsAlignedValue(self):
        #Should Pass
        self.assertEqual(aligned_alloc(32), 32)
        self.assertEqual(aligned_alloc(31), 32)

        #Should Fail
        self.assertNotEqual(aligned_alloc(31), 31)
        self.assertNotEqual(aligned_alloc(32), 16)

        #Should Throw Exception
        self.assertRaises(ValueError, aligned_alloc, -1)
        self.assertRaises(ValueError, aligned_alloc, 15)

if __name__ == '__main__':
    unittest.main()