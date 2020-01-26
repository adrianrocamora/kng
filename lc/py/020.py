# 020 - Valid Parentheses

# Given a string containing just the characters:
# '(', ')', '{', '}', '[', ']'
# determine if the input string is valid.
# The brackets must close in the correct order

# Maintain a stack of opening brackets
# For each closing bracket pop the stack and check if it matches
# Time - O(n)
# Space - O(n)

class Solution(object):
    def is_valid_paren(self, s):
        stack = []
        match = {'(' : ')', '[' : ']', '{' : '}'}

        for c in s:
          if c in match:
            stack.append(c)
          else:
            if not stack or match[stack.pop()] != c:
              return False

        # Return true if the stack is empty
        return not stack

s = '[({}{})[]]'
print(s)
print(Solution().is_valid_paren(s))
print()
s = '[{}{})[]]'
print(s)
print(Solution().is_valid_paren(s))
