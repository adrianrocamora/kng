# 022 - Generate Parentheses

# Given n pairs of parentheses, 
# write a function to generate all combinations of well-formed parentheses

# Recursively add an opening left bracket if any remain, 
# and a closing right bracked if more left brackets have been used.
# Time - O(2^n) each recursion can generate 2 recursive calls although in practice this is an upper bound
# Space - O(2^n)

class Solution:
  def generate_parens(self, n):
    result = []
    self.generate([], n, n, result)
    return result

  # generates all parens given a starting prefix and 
  # remaining left and right brackets
  def generate(self, prefix, left, right, result):
    print(prefix)
    if left == 0 and right == 0:
      result.append("".join(prefix))
    if left > 0:
      self.generate(prefix + ['('], left - 1, right, result)
    if right > left:
      self.generate(prefix + [')'], left, right - 1, result)

n = 0
print(n)
print(Solution().generate_parens(n))
print()
n = 1
print(n)
print(Solution().generate_parens(n))
print()
n = 2
print(n)
print(Solution().generate_parens(n))
print()
n = 3
print(n)
print(Solution().generate_parens(n))
