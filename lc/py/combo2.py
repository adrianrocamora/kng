def combo2(lst, n):
  if n == 0:
    return [[]]
  l = []
  for i in range(0, len(lst)):
    m = lst[i]
    remLst = lst[i+1:]
    for p in combo2(remLst, n - 1):
      l.append([m] + p)
  return l

print(combo2(list('abc'), 2))

