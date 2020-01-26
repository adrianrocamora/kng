# 027 - Remove element

# Given an array and a value, remove all instances
# of that value in place and return the new length.
# Do not allocate extra space for another array,
# you must do this in place with constant memory.
# The order of elements can be changed. It doesn't
# matter what you leave beyond the new length

# Maintain a pointer to the next index to be used for any 
# number not equal to val
# Time - O(n)
# Space - O(1)

class Solution:
  def remove_element(self, nums, val):
    nxt_free = 0

    for num in nums:
      if num != val:
        nums[nxt_free] = num
        nxt_free += 1
    return nxt_free

nums = [2, 4, 1, 3, 7, 3, 5, 4, 9]
val = 3
print(nums)
print(Solution().remove_element(nums, val))







