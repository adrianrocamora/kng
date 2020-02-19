# 003 - Largest prime factor

# What is the biggest prime factor of 600851475143?

import math

def max_prime_factor(n):
  if n < 1:
    return None
  if n < 4:
    return n

  curr = 2
  last_prime_factor = curr
  to_factor = n
  while curr <= to_factor:
    if to_factor % curr == 0:
      to_factor //= curr
      last_prime_factor = curr
    else:
      curr += 1
  return last_prime_factor

print(max_prime_factor(13195))
print()
print(max_prime_factor(600851475143))
