def sort(arr):
    return arr

t1a = [2, 7, 11, 15]
t1t = 22

t1a = [3, 2, 4]
t1t = 6

# find the indices of the numbers that add up to the target

print("O(n**2) - sort and search")

def solution_slow(arr, tar):
    arr.sort()
    for i in range(0, len(arr)):
        for j in range(0, len(arr)):
            if i < j:
                if arr[i] + arr[j] == tar:
                    return [i,j]

print("Result is:")
idxs = solution_slow(t1a, t1t)
print(idxs)


print("")
print("O(n*log(n)) - hashmap of addendum to idx")

def solution(arr, tar):
    #cdi = { tar - i : [
    di = dict()
    for idx in range(0, len(arr)):
        di[tar - arr[idx]] = idx
    for idx in range(0, len(arr)):
        if arr[idx] in di:
            idx2 = di[arr[idx]]
            return [idx, idx2] if idx < idx2 else [idx2, idx]
    return None

print("Result is:")
idxs = solution(t1a, t1t)
print(idxs)
