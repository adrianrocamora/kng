# 002 - Even fibonnaci numbers

# Consider the terms in the fibonacci sequence whose values do not exceed four million and find the the sum of the even-valued terms

def even_fib():
  res = 0
  curr = 1
  prev = 1
  while True:
    curr, prev = curr + prev, curr
    if prev % 2 == 0:
      res += prev
    if curr > 4000000:
      return res

print(even_fib())
