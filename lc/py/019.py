# 019 - Remove nth node from end of list

# Given a linked list, remove the nth node from the end of the list and return the list head

# Advance the first pointer n steps
# Then advance both  pointers at the same rate
# Time - O(n)
# Space - O(1)

class Node:
  def __init__(self, val):
    self.val = val
    self.nxt = None

  def __str__(self):
    sl = []
    sl.append(self.val)
    nxt = self.nxt
    while nxt:
      sl.append(nxt.val)
      nxt = nxt.nxt
    return str(sl)

class Solution:
  def remove_nth_from_end(self, head, n):
    first, second = head, head

    for i in range(n): 
      # move first n steps forward
      first = first.nxt
    if not first: 
      return head.nxt

    while first.nxt: 
      # move both pointers until first is at end
      first = first.nxt
      second = second.nxt
    # nth from end is second.nxt
    second.nxt = second.nxt.nxt
    return head


a = Node(1)
a.nxt = Node(2)
a.nxt.nxt = Node(3)
print(a)
print(Solution().remove_nth_from_end(a,1))
