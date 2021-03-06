# 001 - Two Sum
# Given an array of integers, return indices of the two numbers such that they add up to a specific target.
# You may assume that each input would have exactly one solution

# Maintain a mapping from each number to its index.
# Check if the target - num has already been found
# Time - O(n)
# Space - O(n) for the dictionary

def two_sum_best(nums, target):
  num_to_idx = {}

  for i, num in enumerate(nums):
    if target - num in num_to_idx:
      res = [i, num_to_idx[target - num]]
      res.sort()
      return res
    
    num_to_idx[num] = i

  return []

def two_sum(nums, target):
  num_to_idx = {}

  for i, num in enumerate(nums):
    num_to_idx[num] = i

  for i, num in enumerate(nums):
    if target - num in num_to_idx:
      res = [i, num_to_idx[target - num]]
      res.sort()
      return res
  return []


nums = [6, 9, 2, 3]
target = 11 
print(nums)
print(target)
print(two_sum(nums, target))
print()

nums = [2, 3, 6, 9]
target = 8
print(nums)
print(target)
print(two_sum(nums, target))
