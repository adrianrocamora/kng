def buddy_strings(A, B):
  # it would be nice to know which are the indices to test
  # a bitwise xor would work in other cases
  if len(A) != len(B):
    return False

  if A == B:
    if len(set(A)) != len(A):
      return True


  diff_idx = []
  for idx, c in enumerate(A):
    if A[idx] != B[idx]:
      diff_idx.append(idx)

  if len(diff_idx) != 2:
    print(diff_idx)
    return False

  if A[diff_idx[0]] == B[diff_idx[1]] and A[diff_idx[1]] == B[diff_idx[0]]:
    return True

  return False

print(buddy_strings('ab', 'ba'), 'expect: true')
print(buddy_strings('ab', 'ab'), 'expect: false')
print(buddy_strings('aa', 'aa'), 'expect: true')
print(buddy_strings('aaaaaaabc', 'aaaaaaacb'), 'expect: true')
print(buddy_strings('', 'aa'), 'expect: false')
