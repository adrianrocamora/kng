def findRepeatedDnaSequences(s):
  # we can use a hashmap since it should take around 5MB of RAM
  found = {}

  for start_idx in range(len(s) - 9):
    curr_substr = s[start_idx:start_idx + 10]
    if curr_substr in found:
      found[curr_substr] += 1
    else:
      found[curr_substr] = 0
  res = []
  for k in found:
    if found[k] > 0:
      res.append(k)
  return res


def findRepeatedDnaSequencesSlow(s):
  res = []
  for start_idx in range(len(s) - 1):
    for next_start_idx in range(start_idx + 1, len(s)):
      if s[start_idx:start_idx + 10] == s[next_start_idx:next_start_idx + 10]:
        res.append(s[start_idx:start_idx + 10])
  res = list(set(res))
  res.sort()
  return res

print(findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"), 'Expect: ', ["AAAAACCCCC","CCCCCAAAAA"])
print(findRepeatedDnaSequences("AAAAAAAAAAAAA"), 'Expect: ', ["AAAAAAAAAA"])

