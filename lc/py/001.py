# find the indices of the numbers that add up to the target

print("O(n*log(n)) - hashmap of addendum to idx")

def solution(arr, tar):
  di = dict()
  for idx in range(0, len(arr)):
    if tar - arr[idx] != arr[idx]:
      di[tar - arr[idx]] = idx
  print(di)
  for idx in range(0, len(arr)):
    if arr[idx] in di:
      idx2 = di[arr[idx]]
      return [idx, idx2] if idx < idx2 else [idx2, idx]
  return None

print()

print("Result is:")
arr = [2, 7, 11, 15]
tar = 22
idxs = solution(arr, tar)
print(arr)
print(tar)
print(idxs)
print()

arr = [3, 2, 4]
tar = 6
idxs = solution(arr, tar)
print(arr)
print(tar)
print(idxs)
