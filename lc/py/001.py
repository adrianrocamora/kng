# Given an array of integers, return indices of the two numbers such that they add up to a specific target.
# You may assume that each input would have exactly one solution

# Maintain a mapping from each number to its index.
# Check if the target - num has already been found
# Time - O(n)
# Space - O(n) for the dictionary

class Solution(object):
  def two_sum_best(self, nums, target):
    num_to_idx = {}

    for i, num in enumerate(nums):
      if target - num in num_to_idx:
        res = [i, num_to_idx[target - num]]
        res.sort()
        return res
      
      num_to_idx[num] = i

    return []

  def two_sum(self, nums, target):
    num_to_idx = {}

    for i, num in enumerate(nums):
      num_to_idx[num] = i

    for i, num in enumerate(nums):
      if target - num in num_to_idx:
        res = [i, num_to_idx[target - num]]
        res.sort()
        return res
    return []


sol = Solution()
nums = [6, 9, 2, 3]
target = 11 
# nums = [2, 3, 6, 9]
# target = 9
print(nums)
print(target)
print(sol.two_sum(nums, target))

