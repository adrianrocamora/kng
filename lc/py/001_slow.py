# find the indices of the numbers that add up to the target

print("O(n**2) - sort and search")

def solution_slow(arr, tar):
    arr.sort()
    for i in range(0, len(arr)):
        for j in range(0, len(arr)):
            if i < j:
                if arr[i] + arr[j] == tar:
                    return [i,j]

print()

print("Result is:")
t1a = [2, 7, 11, 15]
t1t = 22
idxs = solution_slow(t1a, t1t)
print(tla)
print(tlt)
print(idxs)
print()

t1a = [3, 2, 4]
t1t = 6
idxs = solution_slow(t1a, t1t)
print(tla)
print(tlt)
print(idxs)
