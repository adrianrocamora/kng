# 005 - Longest Palindrome

# Given a string S, find the longest palindromic substring in S.
# You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

# For each center point of a character or between 2 characters, expand the palindrome if the end characters are the same.
# Return early by starting with the middle center and ruling out later centers that could not have longer substrings than the palindrome already found.
# Time - O(n^2)
# Space - O(n) to store the result

# Note: Manacher's algorithm provides a O(n) time solution

class Solution(object):
  def longest_palindrome(self, s):
    longest = ""

    # create list of 2n-1 possible centers
    # there is one center for each letter and between each pair 
    # even indices represent letters
    # odd indices represent between letters
    # start with middle index that potentially creates longest palindrome
    centers = [len(s) - 1]
    for diff in range(1, len(s)): # build list of indices from long to short
      centers.append(centers[0] + diff)
      centers.append(centers[0] - diff)

    for center in centers:
      if (min(center + 1, 2 * len(s) - 1 - center) <= len(longest)):
        break # if we cannot make a longer palindrome

      if center % 2 == 0:
        left, right = (center // 2) - 1, (center // 2) + 1
      else:
        left, right = center // 2, (center // 2) + 1

      while left >= 0 and right < len(s) and s[left] == s[right]:
        left -= 1
        right += 1
      # left and right are now beyond the ends of the substring

      if right - left - 1  > len(longest):
        longest = s[left + 1:right]

    return longest

s = 'aserolo'
print(s)
print(Solution().longest_palindrome(s))
print()

s = 'abcde'
print(s)
print(Solution().longest_palindrome(s))
print()

s = 'abeedr'
print(s)
print(Solution().longest_palindrome(s))
