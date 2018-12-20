import unittest
import solution as s

class TestFoobar(unittest.TestCase):
    def testBaseLessThanTwo(self):
        self.assertEqual(s.toBaseB(10, 0), None)
        self.assertEqual(s.toBaseB(10, 1), None)
        self.assertEqual(s.toBaseB(0, 1), None)
        self.assertEqual(s.toBaseB(1, 1), None)
        
    def testNIsZero(self):
        for i in range(2, 111):
            self.assertEqual(s.toBaseB(0, i), [0])
        
    def testNIsOne(self):
        for i in range(2, 111):
            self.assertEqual(s.toBaseB(1, i), [1])

    def testBaseTwo(self):
        self.assertEqual(s.toBaseB(2, 2), [1, 0])
        self.assertEqual(s.toBaseB(7, 2), [1, 1, 1])
        self.assertEqual(s.toBaseB(8, 2), [1, 0, 0, 0])
        self.assertEqual(s.toBaseB(9, 2), [1, 0, 0, 1])

    def testBase16(self):
        self.assertEqual(s.toBaseB(0, 16), [0])
        self.assertEqual(s.toBaseB(10, 16), [10])
        self.assertEqual(s.toBaseB(16, 16), [1, 0])
        self.assertEqual(s.toBaseB(250, 16), [15, 10])
        self.assertEqual(s.toBaseB(255, 16), [15, 15])

    def testListPalindromeTrue(self):
        self.assertTrue(s.isListPalindrome([]))
        self.assertTrue(s.isListPalindrome([1]))
        self.assertTrue(s.isListPalindrome([8]))
        self.assertTrue(s.isListPalindrome([238]))

        self.assertTrue(s.isListPalindrome([8, 8]))
        self.assertTrue(s.isListPalindrome([1, 1, 1]))
        self.assertTrue(s.isListPalindrome([13, 0, 13]))
        self.assertTrue(s.isListPalindrome([5, 3, 6, 3, 5]))

    def testListPalindromeFalse(self):
        self.assertFalse(s.isListPalindrome([8, 2]))
        self.assertFalse(s.isListPalindrome([1, 2, 3]))
        self.assertFalse(s.isListPalindrome([1, 0, 0]))
        self.assertFalse(s.isListPalindrome([13, 0, 1]))
        self.assertFalse(s.isListPalindrome([1, 3, 6, 3, 5]))

    def testSamples(self):
        self.assertEqual(s.answer(0), 2)
        self.assertEqual(s.answer(9), 2)
        self.assertEqual(s.answer(42), 4)

if __name__ == '__main__':
    unittest.main()
