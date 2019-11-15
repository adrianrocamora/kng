# find the indices of the numbers that add up to the target

print("O(n**2) - sort and search")

def solution(arr, tar):
    arr.sort()
    for i in range(0, len(arr)):
        for j in range(0, len(arr)):
            if i < j:
                if arr[i] + arr[j] == tar:
                    return [i,j]

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
