# 028 - Implement strstr(str1, str2)

# Returns the index of the first occurrence of str2 in str1
# or -1 if str2 is not in str1

# For each possible starting point str1, check characters matching
# with str2 and break if not 
# Alternatively, KMP would improve expected time complexity
# Time - O(n^2)
# Space - O(1)

class Solution:
  def strstr(self, str1, str2):
    for i in range(len(str1) - len(str2) + 1):
      for j in range(len(str2)):
        if str1[i+j] != str2[j]:
          break
      else:
        return i
    return -1

s1 = 'hello'
s2 = 'lo'
print(s1)
print(s2)
print(Solution().strstr(s1, s2))
