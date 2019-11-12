def sort(arr):
    return arr

t1a = [2, 7, 11, 15]
t1t = 9

# find the indices of the numbers that add up to the target

arr = t1a
tar = t1t
for idx in range(0, len(arr)):
    print(str(idx) + " " + str(arr[idx]))

print("O(n**2) - sort and search")

arr = sort(arr)
for i in range(0, len(arr)):
    for j in range(0, len(arr)):
        if i != j:
            print(str(i) +", " + str(j))


