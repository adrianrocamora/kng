# 021 - Merge two sorted lists

# Merge two sorted linked lists and return it as a new list.
# The new list should be made by splicing together the nodes of the first two lists

# While there are nodes in both lists, link to lowest head node and increment that list.
# Finally, link to the list with remaining nodes
# Time - O(m+n)
# Space - O(1)

class Node:
  def __init__(self, val):
    self.val = val
    self.nxt = None

  def __str__(self):
    sl = [self.val]
    nxt = self.nxt
    while nxt:
      sl.append(nxt.val)
      nxt = nxt.nxt
    return str(sl)

class Solution:
  def merge_two_lists(self, l1, l2):
    # new dummy head for the merged list
    prev = dummy = Node(None)

    while l1 and l2:

      # link prev to the lowest node
      if l1.val < l2.val:
        prev.nxt = l1
        l1 = l1.nxt
      else:
        prev.nxt = l2
        l2 = l2.nxt

      prev = prev.nxt

    # only one list remains so just append it
    prev.nxt = l1 or l2

    return dummy.nxt


a = Node(1)
a.nxt = Node(3)
a.nxt.nxt = Node(7)
a.nxt.nxt.nxt = Node(11)
a.nxt.nxt.nxt.nxt = Node(17)
print(a)
b = Node(2)
b.nxt = Node(4)
b.nxt.nxt = Node(5)
print(b)
print(Solution().merge_two_lists(a, b))
