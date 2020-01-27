# 033 - Search ina rotated sorted array

# Supposer a sorted array is rotated at some pivout unknown to you
# (e.g., 0 1 2 4 5 6 7 could be 4 5 6 7 0 1 2)
# You are given a target value to search. If found in the array
# return its index, otherwise return -1
# You may assume no duplicate exists in the array

# Binary search, if one side is sorted and target is in that region
# then recurse on that side or else the other side
# Time - O(log n), half of the array is eliminated for every recursion 
# Space - O(1)

class Solution:
  def search(self, nums, target):
    left, right = 0, len(nums) - 1

    while left <= right
