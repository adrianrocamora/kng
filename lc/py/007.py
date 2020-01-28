# 007 Reverse Integer

# Reverse the digits of an integer

# Repeatedly multiply the previous result by 10 and add the last digit
# Time - O(n) where n is the number of digits
# Space - O(n) same number of digits in output as input

class Solution(object):
  def reverse_simple(self, x):
    xs = str(x)
    xs = xs[::-1]
    x = int(xs)
    return x
    
  def reverse(self, x):
    negative = x < 0
    x = abs(x)
    rev = 0

    while x != 0:
      rev = rev * 10 + x % 10
      x //= 10
    
    if rev > 2**31 - 1:
      return 0
    return rev if not negative else -rev

x = 1234
print(x)
print(Solution().reverse(x))
print()

x = -271
print(x)
print(Solution().reverse(x))
