class Solution(object):
  def two_sum(self, nums, target):
    num_to_idx = {}

    for i, num in enumerate(nums):
      if target - num in num_to_idx:
        return [i, num_to_idx[target - num]]
      
      num_to_idx[num] = i

    return []

