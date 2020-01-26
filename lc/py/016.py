# 016 - 3Sum closest

# Given an array nums of n integers, find three integer in nums such that the sum is closest to a given number, target.
# Return the sum of the three integers. You may assume that each input would have exactly one solution

# Sort the array, for each starting index bidirectional
# search in the rest of the array
# Time - O(n**2)
# Space - O(1)

class Solution:
  def three_sum_closest(self, nums, target):
    nums.sort()

    # default if len(nums) < 3 
    closest = float('inf')

    for i in range(len(nums) - 2):
      j = i + 1
      k = len(nums) - 1

      while j < k:
        triple = nums[i] + nums[j] + nums[k]
        if triple == target:
          # early return, cannot do better
          return target
        if abs(triple - target) < abs(closest - target):
          closest = triple 

        if triple > target:
          k -= 1
        else:
          j += 1

    return closest

nums = [-10, 2, -4, -5, 23, 2]
target = 8
print(nums)
print(target)
print(Solution().three_sum_closest(nums, target))
print()

nums = [-10, 2, -4, -5, 23, 2]
target = 11
print(nums)
print(target)
print(Solution().three_sum_closest(nums, target))
print()

nums = [-10, 2, -4, -5, 23, 2]
target = -38
print(nums)
print(target)
print(Solution().three_sum_closest(nums, target))
print()
