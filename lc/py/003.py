# 003 - Length of longest substring

# Given a string. Find the length of the longest substring without repeating characters.

# Maintain a sliding window, updating the start whenever we see a character repeated
# Time - O(n)
# Space - O(1), dictionary is limited by fixed size alphabet

class Solution(object):
  def length_of_longest_substring(self, s):
    last_seen = {} # last seen char to index
    start = 0
    longest = 0

    for i, c in enumerate(s):
      if c in last_seen and last_seen[c] >= start:
        start = last_seen[c] + 1
      else:
        longest = max(longest, i - start + 1)

      last_seen[c] = i # update the last sighting index

    return longest

sol = Solution()
s = 'abcda'
print(s)
print(sol.length_of_longest_substring(s))
print()

s = 'ebbda'
print(s)
print(sol.length_of_longest_substring(s))
print()

s = 'abcdefgh'
print(s)
print(sol.length_of_longest_substring(s))
