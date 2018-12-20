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
    def left(self,left):
        self._left = left
    
    @property
    def right(self):
        return self._right

    @right.setter
    def right(self,right):
        self._right = right



def print_data(root):
    print('printing data')
    if root.data != None:
        print(root.data)

treeA = TreeNode()
print_data(treeA)
    
treeB = TreeNode()
treeB.data = 42
print_data(treeB)


    
        

