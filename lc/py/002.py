inp = [[2, 4, 3] , [5, 6, 4]]
out = [7, 0, 8]

class Node:
  # No multiple constructors in python?
  # def __init__(self, val):
    # self.val = val
    # self.next = None

  def __init__(self, val, nxt):
    self.val = val
    self.nxt = nxt

  #is this the function?
  def __string__(self):
    nxt = self.next
    val = self.val
    print(val)

a = Node(2, Node(4, Node(3, None)))
print(a)




