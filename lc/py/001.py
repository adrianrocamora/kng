def sort(arr):
    return arr

t1a = [2, 7, 11, 15]
t1t = 9

# find the indices of the numbers that add up to the target

print("O(n**2) - sort and search")

def solution(arr, tar):
    arr = sort(arr)
    for i in range(0, len(arr)):
        for j in range(0, len(arr)):
            if i < j:
                if arr[i] + arr[j] == tar:
                    return [i,j]

print("Result is:")
idxs = solution(t1a, t1t)
print(idxs)


