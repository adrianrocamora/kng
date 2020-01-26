# 015 - 3Sum

# Given an array S of n integers, 
# are there elements a, b, c in S 
# such that a + b + c = 0?
# Find all unique triplets in the array which follow this rule
# Note: The solution set must not contain duplicate triplets.

# Sort the array, 
# for each index i perform a bidirectional search on the higher values of the array
# Skip over duplicates.
# Increment i to the next new minimum number. 
# Time - O(n**2) for each i at least one of the j and k moves every iteration
# Space - O(n)

class Solution:
  def three_sum(self, nums):
    results = []
    nums.sort()

    i = 0
    while i < len(nums):
      j = i + 1
      k = len(nums) - 1

      while j < k:
        triple_sum = nums[i] + nums[j] + nums[k]

        if triple_sum == 0:
          # record result and move both j and k to the next new numbers
          results.append([nums[i], nums[j], nums[k]])

          # decrement k to the next new number
          k -= 1
          while k > j and nums[k] == nums[k + 1]:
            k -= 1

          # increment j to the next new number
          j += 1
          while j < k and nums[j] == nums[j - 1]:
            j += 1

        elif triple_sum > 0:
          # decrement k to the next new number
          k -= 1
          while k > j and nums[k] == nums[k + 1]:
            k -= 1

        else:
          # increment j to the next new number
          j += 1
          while j < k and nums[j] == nums[j - 1]:
            j += 1
      
      # increment i to the next new number
      i += 1
      while  i < len(nums) - 2 and nums[i] == nums[i - 1]:
        i += 1

    return results


nums = [-10, 2, 3, 8, 9]
print(nums)
print(Solution().three_sum(nums))
print()

nums = [0, 2, 3]
print(nums)
print(Solution().three_sum(nums))
print()

nums = [-10, -3, -2, 5, 8, 12,]
print(nums)
print(Solution().three_sum(nums))

