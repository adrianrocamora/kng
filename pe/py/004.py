# 004 - Largest Palindromic Number

# Largest from the 2-digit nums multiplied is 9009 = 91 x 99

def largest_palindromic_num_O_n_2(n):
  def is_palindrome(num):
    num_str = str(num)
    return num_str == num_str[::-1]

  start = 10 ** (n - 1)
  finish = 10 ** n - 1 

  max_prod = 0
  for p1 in range(start, finish + 1):
    for p2 in range(start, finish + 1):
      prod = p1 * p2
      if is_palindrome(prod):
        if prod > max_prod:
          max_prod = prod

  return max_prod

def largest_palindromic_num(n):
  def is_palindrome(num):
    num_str = str(num)
    return num_str == num_str[::-1]

  start = 10 ** (n - 1)
  finish = 10 ** n - 1 

  max_prod = 0
  for p1 in range(star, (start + finish + 1)//2):
    max_prod_local = 0
    lo = p1
    hi = finish
    mid = (lo + hi) // 2

    while lo < hi:
      curr_prod = p1 * 
      if p1 * mid > max_prot

    for p2 in range(start, finish + 1):
      prod = p1 * p2
      if is_palindrome(prod):
        if prod > max_prod:
          max_prod = prod

  return max_prod
  
print(largest_palindromic_num(2))
print()
print(largest_palindromic_num(3))
print()
#print(largest_palindromic_num(4))
