class Solution(object):
  def reverse(self, x):
    xs = str(x)
    xs = xs[::-1]
    x = int(xs)
    return x
    

sol = Solution()
x = 1234
print(x)
print(sol.reverse(x))

