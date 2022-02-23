# moon umbrellas
# import itertools
def remove_adjacent(seq): # works on any sequence, not just on numbers
  i = 1
  n = len(seq)
  while i < n: # avoid calling len(seq) each time around
    if seq[i] == seq[i-1]:
      del seq[i]
      # value returned by seq.pop(i) is ignored; slower than del seq[i]
      n -= 1
    else:
      i += 1
T = int(input())
for t in range(T):
  x_y_s = input()
  x = int(x_y_s.split(' ')[0])
  y = int(x_y_s.split(' ')[1])
  s = x_y_s.split(' ')[2]
  s = list(s)
  question_idx = [i for i, ltr in enumerate(s) if ltr == '?']
  # print(question_idx)
  if len(question_idx) == len(s):
    cost = 0
  else:

    # we only change costs with the index before and after a ?
    # if J's are not contiguous it's easy
    # if they are, choose the same value, 
    # just check the cost for each case
    # transform s to remove duplicate '?'
    # s = [k for k, g in itertools.groupby(s)]
    # print('s', s)
    chosen_letters = []
    for i, c in enumerate(s):
      cost_j = 0
      cost_c = 0
      if i == 0:
        cost_j += y if s[i+1] == 'C' else 0
        cost_c += x if s[i+1] == 'J' else 0
      elif i == len(s) - 1:
        cost_j += x if s[i-1] == 'C' else 0
        cost_c += y if s[i-1] == 'J' else 0
      else:
        cost_j += x if s[i-1] == 'C' else 0
        cost_j += y if s[i+1] == 'C' else 0
        cost_c += y if s[i-1] == 'J' else 0
        cost_c += x if s[i+1] == 'J' else 0

      # if i in question_idx:
      if c == '?':
        chosen_letters.append('C' if cost_c < cost_j else 'J')

    # print('chosen', chosen_letters)

    # print('s', s)
    chosen_idx = 0
    for i, c in enumerate(s):
      if c == '?':
        s[i] = chosen_letters[chosen_idx]
        chosen_idx += 1
    # print('answer', s)


    cost = 0
    for i, c in enumerate(s):
      if i == len(s) - 1:
        break
      cost += x if c == 'C' and s[i+1] == 'J' else 0
      cost += y if c == 'J' and s[i+1] == 'C' else 0
    # print('cost', cost)

  output = cost
  print('Case #' + str(t+1) + ': ' + str(output))

"""
# C?C -> min: 0
CJC
CCC 0

# C?J -> min: CJ
CJJ
CCJ 

# C?C -> min: JC
JJC
JCC 

# C?C -> min: 0
JJJ 0
JCJ 
"""
"""
# C??C -> min: 0
CCCC    0
CCJC
CJCC
CJJC

# C??J  -> min: CJ
CCCJ    CJ
CCJJ    CJ
CJCJ    CJ JC CJ
CJJJ    CJ

# J??C -> min: JC
JCCC    JC
JCJC    JC CJ JC
JJCC    JC
JJJC    JC

# J??J -> min: 0
JCCJ
JCJJ
JJCJ
JJJJ    0
"""
"""
# C???C -> 0
# J???J -> 0
# C???J -> 
CCCCJ   -> CJ
CCCJJ   -> CJ
CCJCJ
CCJJJ   -> CJ
CJCCJ
CJCJJ
CJJCJ
CJJJJ   -> CJ
# J???C -> 
JCCCC   -> JC
JCCJC
JCJCC
JCJJC
JJCCC   -> JC
JJCJC
JJJCC
JJJJC

"""
