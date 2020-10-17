def searchMatrixSlow(matrix, target):
  for row in matrix:
    for col in row:
      if col == target:
        return True
  return False

def searchMatrixFaster(matrix, target):
  def binsearch(target, nums):
    lo = 0
    hi = len(nums) - 1
    if nums[lo] == target or nums[hi] == target:
      return True
    while lo <= hi:
      mid = (lo + hi) //2
      if nums[mid] == target:
        return True
      elif target < nums[mid]:
        hi = mid - 1
      else:
        lo = mid + 1
    return False

  for idx, row in enumerate(matrix):
    if row[0] < target < row[-1]:
      if binsearch(target, row):
        return True
      else:
        continue
    return False

def searchMatrix(matrix, target):
  def binsearch(target, nums, lo, hi):
    if lo <= hi:
      mid = (lo + hi) //2
      if nums[mid] == target:
        return True
      elif target < nums[mid]:
        return binsearch(target, nums, lo, mid - 1)
      else:
        return binsearch(target, nums, mid + 1, hi)
    else:
      return False
  
  if not matrix:
    return False

  if len(matrix) == 1:
    if not matrix[0]:
      return False
  
  lo = 0
  hi = len(matrix) - 1
  if target < matrix[lo][0] or target > matrix[hi][-1]:
    return False
  if matrix[lo][0] < target < matrix[lo][-1]:
    return binsearch(target, matrix[lo], 0, len(matrix[lo]) - 1)
  if matrix[hi][0] < target < matrix[hi][-1]:
    return binsearch(target, matrix[hi], 0, len(matrix[hi]) - 1)
  if matrix[lo][0] == target or matrix[lo][-1] == target:
    return True
  if matrix[hi][0] == target or matrix[hi][-1] == target:
    return True
  while lo <= hi:
    mid = (lo + hi) // 2
    if matrix[mid][0] < target < matrix[mid][-1]:
      return binsearch(target, matrix[mid],0, len(matrix[mid]) - 1)
    if target < matrix[mid][0]:
      hi = mid - 1
    elif target > matrix[mid][-1]:
      lo = mid + 1
    else:
      return False
  return False

mat0 = [[1,3,5,7],[10,11,16,20],[23,30,34,50]]

# print(searchMatrixSlow(mat0, 13), 'False')
# print(searchMatrixFaster(mat0, 13), 'False')
print(searchMatrix(mat0, 13), 'False')

# print(searchMatrixSlow(mat0, 3), 'True')
# print(searchMatrixFaster(mat0, 3), 'True')
print(searchMatrix(mat0, 3), 'True')

# print(searchMatrixSlow([], 3), 'False')
# print(searchMatrixFaster([], 3), 'False')
print(searchMatrix([], 3), 'False')

print(searchMatrix([[1]], 1), 'True')
