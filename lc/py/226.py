# Invert a binary tree.

# Left substree is old right subtree inverted.
# Right subtree is old left subtree inverted.
# Time - O(n)
# Space - O(n)

class Node:
  def __init__(self, val):
    self.val = val
    self.left = self.right = None

def invert_tree(root):
  if not root:
    return None

  root.left, root.right = invert_tree(root.right), invert_tree(root.left)

  # OR:
  # invert(root.left)
  # invert(root.right)
  # temp = root.left
  # root.left = root.right
  # root.right = temp

  return root

# inorder traversal
def print_tree(root):
  if not root:
    return
  print_tree(root.left)
  print(root.val)
  print_tree(root.right)

n = Node(2)
n.left = Node(1)
n.right = Node(4)
n.right.left = Node(3)
n.right.right = Node(5)

print_tree(n)
print()
invert_tree(n)
print_tree(n)
