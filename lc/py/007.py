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
    reversed = 0

    while x != 0:
      reversed = reversed * 10 + x % 10
      x //= 10
    
    if reversed > 2**31 - 1:
      return 0
    return reversed if not negative else -reversed

x = 1234
print(x)
print(Solution().reverse(x))
