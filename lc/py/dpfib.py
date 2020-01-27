def fib_slow(n):
  if n == 0:
    return 0
  if n == 1:
    return 1
  return fib(n - 1) + fib(n - 2)

fibdi = {}
def fib(n):
  if n == 0:
    return 0
  if n == 1:
    return 1
  if n in fibdi:
    return fibdi[n]
  fibdi[n] = fib(n - 1) + fib(n - 2)

  return fibdi[n]

print(fib(1))
print(fib(2))
print(fib(3))
print(fib(4))
print(fib(5))
print(fib(6))
print(fibdi)
