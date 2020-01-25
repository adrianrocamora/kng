# 008 String to Integer (atoi)

# Implement atoi to convert a string to an integer. 


class Solution(object):
  def atoi(self, s):
    s = s.strip()   # remove padding spaces
    char_to_digit = { str(x):x for x in range(0,10) }
    digit_to_char = { x:str(x) for x in range(0,10) }

    print(char_to_digit)
    print(digit_to_char)

Solution().atoi('1234')

