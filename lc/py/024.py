# 024 - Swap nodes in pairs

# Given a linked list, swap every two adjacent nodes and return its head
# E.g for 1->2->3->4 return 2->1->4->3

# Store the previous node, swap and append in pairs
# Time - O(n)
# Space - O(1)

class Node:
  def __init__(self, val):
    self.val = val
    self.nxt = None
  def __str__(self):
    ls = [self.val]
    nxt = self.nxt
    while nxt:
      ls.append(nxt.val)
      nxt = nxt.nxt
    return str(ls)

class Solution:
  def swap_pairs(self, head):
    prev = dummy = Node(None)

    while head and head.nxt:
      # so we store the head for the next iteration
      nxt_head = head.nxt.nxt
      # store (head.nxt) since it's going to be "floating" soon
      prev.nxt = head.nxt
      # link (head.nxt) to the original head, 
      head.nxt.nxt = head
      # replace prev with head???
      prev = head 
      # update the head for the next iteration
      head = nxt_head

    prev.nxt = head
    return dummy.nxt

a = Node(1)
a.nxt = Node(2)
a.nxt.nxt = Node(3)
a.nxt.nxt.nxt = Node(4)
a.nxt.nxt.nxt.nxt = Node(5)
print(a)
print(Solution().swap_pairs(a))
