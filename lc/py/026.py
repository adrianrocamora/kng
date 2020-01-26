# 026 - Remove duplicates from sorted array

# Given a sorted array, remove the duplicates in place such that
# each element appears only once.
# Return the new length
# Do not allocate extra space for another array. 
# you must do this in place and with constant memory

# Maintain a pointer to the next index to be filled with a new number
# Check every number against the previous num
# (if any) and if different , move to the next_new index
# Time - O(n)
# Space - O(1)

class Solution:
  def remove_duplicates(self, nums):
    # index where the next unique number is to be moved to
    nxt_new = 0

    for i in range(len(nums)):
      if i == 0 or nums[i] != nums[i - 1]:
        nums[nxt_new] = nums[i]
        nxt_new += 1

    return nxt_new

nums = [1,1,3,4,4,4,5,6]
print(nums)
print(Solution().remove_duplicates(nums))

