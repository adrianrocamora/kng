# 006 - ZigZag Conversion

# The string "PAYPALISHIRING" is written in a zigzag pattern 
# on a given number of rows like this:
# P   A   H   N
# A P L S I I G 
# Y   I   R
# And then read line by line "PAHNAPLSIIGYIR"
# Write the code that will take a string and make this conversion
# given a number of rows

# Build a list of chars for each row by tracking the direction of movement up or down and reversing direction at end rows.
# Time - O(n), use a list of chars and join instead of adding to immutable strings
# Space - O(n)

class Solution(object):
  def convert(self, s, num_rows):
    if num_rows == 1:
      return s

    zigzag = [[] for _ in range(num_rows)]
    row = 0
    direction = -1 # -1 for up, +1 for down

    for c in s:
      zigzag[row].append(c)
      if row == 0 or row == num_rows - 1: # change direction
        direction = -direction
      row += direction

    # flatten the list of lists
    return "".join([c for r in zigzag for c in r])

print(Solution().convert("hello", 3))
print('h o')
print('el') 
print('l')
print()

print(Solution().convert("abcdefghi", 4))
print('a  g')
print('b fh')
print('ce i')
print('d ')
