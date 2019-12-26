import unittest
from copy import deepcopy

class TreeNode:

    def __init__(self):
        self.data = None
        self.left = None
        self.right = None

    @property
    def data(self):
        return self._data

    @data.setter
    def data(self, data):
        self._data = data

    @property
    def left(self):
        return self._left

    @left.setter
    def left(self, left):
        self._left = left

    @property
    def right(self):
        return self._right

    @right.setter
    def right(self, right):
        self._right = right

def are_identical(root1, root2):
    if root1 == None and root2 == None:
        return True
    if root1 != None and root2 != None:
        return (root1.data == root2.data and
                are_identical(root1.left, root2.left) and
                are_identical(root1.right, root2.right)) 
    return False

class TestAreIdentical(unittest.TestCase):
    def test_upper(self):
        self.assertEqual('foo'.upper(), 'FOO')

            
class TestStringMethods(unittest.TestCase):

    def test_empty_trees(self):
        tree1 = TreeNode()
        tree2 = TreeNode()
        self.assertTrue(are_identical(tree1,tree2))

    def test_empty_tree_and_single_node_tree(self):
        tree1 = TreeNode()
        tree2 = TreeNode()
        tree1.data = 11
        self.assertFalse(are_identical(tree1,tree2))

    def test_equal_single_node_trees(self):
        tree1 = TreeNode()
        tree2 = TreeNode()
        tree1.data = 11
        tree2.data = 11
        self.assertTrue(are_identical(tree1,tree2))

    def test_single_node_tree_and_nested_tree(self):
        tree1 = TreeNode()
        tree2 = TreeNode()
        tree1.data = 11
        tree2.data = 11
        tree1.left = deepcopy(tree1)
        self.assertFalse(are_identical(tree1,tree2))

    def test_equal_nested_trees(self):
        tree1 = TreeNode()
        tree2 = TreeNode()
        tree1.data = 11
        tree2.data = 11
        tree1.left = deepcopy(tree1)
        tree2.left = deepcopy(tree2)
        self.assertTrue(are_identical(tree1,tree2))


if __name__ == '__main__':
    unittest.main()
    
