def minDominoRotations(A, B):
  import math
  candidates = []
  min_rot = math.inf
  for num in range(1, 7):
    good_run = True
    rotA = 0
    rotB = 0
    for idx, a in enumerate(A):
      if num == A[idx] and num == B[idx]:
        rotA += 0
        rotB += 0
      elif num == B[idx]:
        rotA += 1
      elif num == A[idx]:
        rotB += 1
      else: # if num != A[idx] and num != B[idx]:
        good_run = False
        break

    if good_run:
      min_rot = min(min_rot, rotA, rotB)

  if min_rot < math.inf:
    return min_rot
  else:
    return -1

A, B = [2,1,2,4,2,2], [5,2,6,2,3,2]
print(A, B, minDominoRotations(A, B), 'Expect', 2)
print()
print(minDominoRotations([3,5,1,2,3], [3,6,3,3,4]), 'Expect', -1)
print()
print(minDominoRotations([1,1,1,1,1,1,1,1], [1,1,1,1,1,1,1,1]), 'Expect', 0)
print()
print(minDominoRotations([1,2,1,1,1,2,2,2], [2,1,2,2,2,2,2,2]), 'Expect', 1)
