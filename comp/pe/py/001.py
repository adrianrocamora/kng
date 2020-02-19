# Multiples of 3 and 5

# Show the sum of the multiples of 3 or 5 below N

def sum(n):
  res = 0
  for num in range(1, n):
    if num % 3 == 0 or num % 5 == 0:
      res += num
  return res

print(sum(10))
print(sum(1000))

