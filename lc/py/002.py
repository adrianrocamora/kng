# You are given two linked lists representing two non-negative numbers.
# The digits are stored in reverse order and each of their nodes contain a single digit.
# Add the two numbers and return the result as a linked list

# Iterate over lists. Add to result a node with the sum of input nodes plus carrymod 10.
# Time - O(max(m, n)) where m and n are input list lengths
# Space - O(max(m, n)), out put  will be at most one digit more than the longest input 

class Node(object):
  def __init__(self, val):
    self.val = val
    self.next = None

  def __str__(self):
    res = [self.val]
    nxt = self.next
    while nxt:
      res.append(nxt.val)
      nxt = nxt.next
    return str(res)

class Solution(object):
  def add_two_numbers(self, l1, l2):
    prev = res = Node(None)     # dummy head
    carry = 0 

    while l1 or l2 or carry:
      if l1:
        carry += l1.val
        l1 = l1.next
      if l2:
        carry += l2.val
        l2 = l2.next
      prev.next = Node(carry % 10)
      prev = prev.next
      carry //= 10

    return res.next

a = Node(9)
a.next = Node(4)
a.next.next = Node(8)
print(a)

b = Node(1)
print(b)

sol = Solution()
print(sol.add_two_numbers(a, b))



