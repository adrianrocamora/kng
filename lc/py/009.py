# 009 - Palindrome Number

# Determine whether an integer is a palindrome. 
# Do this without extra space

# Check equivalence of first and last characters, moving inwards
# Time - O(n)
# Space - O(1)

class Solution(object):
  def is_palindrome(self, x):
    s = str(x)
    left, right = 0, len(s) - 1

    while left < right:
      if s[left] != s[right]:
        return False
      left += 1
      right -= 1

    return True

x = 34843
print(x)
print(Solution().is_palindrome(x))
print()

x = 1234
print(x)
print(Solution().is_palindrome(x))
