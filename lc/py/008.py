# 008 String to Integer (atoi)

# Implement atoi to convert a string to an integer. 

# Return the integer up to any non-digit
# Time - O(n)
# Space - O(n)

class Solution(object):
  def atoi(self, s):
    # remove padding spaces
    s = s.strip()

    # remove leading + or -
    negative = False

    if s and s[0] == '-':
      negative = True
    if s and (s[0] == '+' or s[0] == '-'):
      s = s[1:]
    if not s:
      return None

    digits = {i for i in '012345689'}
    res = 0
    # record integer up to first non-digit
    for c in s:
      if c not in digits:
        break
      res = res * 10 + int(c)

    if negative:
      res = -res

    # keep within 4 byte signed for online judges
    res = max(min(res, 2**31 - 1), -2**31)

    return res

s = '  -1234.4asdf2 '
print(s)
print(Solution().atoi(s))
print()

s = '342'
print(s)
print(Solution().atoi(s))
