def bin_search(xs, x):
  low = 0
  high = len(xs) - 1

  while low <= high:
    mid = (low + high) // 2
    if xs[mid] < x:
      low = mid + 1
    elif xs[mid] > x:
      high = mid - 1
    else:
      return mid

  return None


a = [1, 3, 3, 4, 5, 7, 11, 11, 12]

print(bin_search(a, 1))
print(bin_search(a, 3))
print(bin_search(a, 4))
print(bin_search(a, 6))
print(bin_search(a, 12))
print(bin_search(a, 16))



