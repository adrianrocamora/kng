# 014 Longest Common Prefix

# Write a function to find the longest common prefix string amongst an array of strings

# Sort strings and find the longest prefix of first and last,
# which arer the most different.
# Alternatively, all strings could be inserted into a trie
# and we find the first node with more than one child
# Time - O(k*n log n) where k is the length of the longest string and n is the number of strings
# Space - O(1)

class Solution(object):
    def longest_common_prefix(self, strs):
        if not strs:
            return ''
        strs.sort()
        first = strs[0]
        last = strs[-1]

        i = 0
        while i < len(first) and i < len(last) and first[i] == last[i]:
            i += 1
        return first[:i]


s = ['avery', 'avemaria']
print(s)
print(Solution().longest_common_prefix(s))
print()

s = ['a', 'b', 'c']
print(s)
print(Solution().longest_common_prefix(s))
print()

s = ['ebeler', 'ernt']
print(s)
print(Solution().longest_common_prefix(s))
