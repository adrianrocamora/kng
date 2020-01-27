# 031 - Next permutation

# Implement next permutation, which rearranges numbers into the 
# lexicographically next greater permutation of numbers.
# If such arrangement is not possible, it must rearrange it as 
# the lowest possible order (i.e. sorted in ascending order)
# The replacement must be in-place, do not allocate extra memory

# Starting from the last number, move forward 
# to find the first decrease nums[i],
# Find the smallest number bigger than nums[i] (nums[j])
# Swap nums[i] and nums[j]
# Reverse all from i+1 onwards, or the whole array if no 
# decrease is found in the first step
# Time - O(n)
# Space - O(1)

class Solution:
  def next_permutation(self, nums):
    if not nums or len(nums) == 1:
      return 

    # starting at back, find the first decrease
    # increasing it will increment the permutation
    i = len(nums) - 2
    while i >= 0 and nums[i] >= nums[i+1]:
      i -= 1

    # if any decrease then find the smalles larger number to swap with
    if i != -1:
      j = i + 1
      while j < len(nums) and nums[j] > nums[i]:
        j += 1
      j -= 1
      nums[i], nums[j] = nums[j], nums[i]

    # reverse all from i+1 onwards since they were decreasing and since
    # increasing minimises permutation
    left = i+1
    right = len(nums) - 1
    while left < right:
      nums[left], nums[right] = nums[right], nums[left]
      left += 1
      right -= 1

nums = [1,3,2]
print(nums)
Solution().next_permutation(nums)
print(nums)

nums = [0,1,0]
print(nums)
Solution().next_permutation(nums)
print(nums)



