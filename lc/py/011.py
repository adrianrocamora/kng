# 011 - Container with most water

# Given n non-negative integers a1, a2, ..., an
# where each represents a point at coordinate (i, ai)
# n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0)
# Find two lines, which together with x-axis forms a container, 
# such that the container contains the most water

# Start with the widest separation of lines.
# To form a greater area, any lesser separation must have a greater minimum boundary height
# Time - O(n)
# Space - O(1)

class Solution:
  def max_area(self, heights):
    left = 0
    right = len(heights) - 1
    max_area = (right -  left) * min(heights[right], heights[left])

    while left < right:
      if heights[left] < heights[right]:
        left += 1
      else:
        right -= 1
      max_area = max(max_area, (right - left) * min(heights[right], heights[left]))

    return max_area

h = [1,4,1]
print(h)
print(Solution().max_area(h))
print()

h = [1,4,4,1]
print(h)
print(Solution().max_area(h))
print()

h = [1,2,3,4,5]
print(h)
print(Solution().max_area(h))
print()
