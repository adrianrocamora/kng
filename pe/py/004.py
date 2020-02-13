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

  # P = m n
  # P = 100,001 a + 10,010 b + 1100 c
  # P = 11(9091 a + 910 b + 100 c
  # So either a or b have a factor of 11

  # We can iterate over less numbers now
  # Previously (999 - 99) ** 2 == 810,000
  # Now 10*10*10 = 1000
  # 

  def is_palindrome(num):
    num_str = str(num)
    return num_str == num_str[::-1]

  # We iterate over all possible palindromes
  # and we check if they are a product of 3 digit
  # numbers one of which is a multiple of 11

  max_prod = 0
  for a in range(0, 10):
    for b in range(0, 10):
      for c in range(0, 10):
        candidate = 100001*a + 10010*b + 1100*c
        for m in range(110, 999, 11):
          if candidate % m == 0 and \
              100 <= candidate // m <= 999 and \
              candidate > max_prod:
            max_prod = candidate
  return max_prod
  
def largest_palindromic_num_4():

  def is_palindrome(num):
    num_str = str(num)
    return num_str == num_str[::-1]

  # We iterate over all possible palindromes
  # and we check if they are a product of 3 digit
  # numbers one of which is a multiple of 11

  max_prod = 0
  max_prods= None
  for a in range(0, 10):
    for b in range(0, 10):
      for c in range(0, 10):
        for d in range(0, 10):
          candidate = 10000001*a + 1000010*b + 100100*c + 11000*d
          for m in range(1001, 9999, 11):
            if candidate % m == 0 and \
                1000 <= candidate // m <= 9999 and \
                candidate > max_prod:
              max_prod = candidate
              max_prods = (m, candidate // m)
  print(max_prods)
  return max_prod
#print(largest_palindromic_num(2))
#print()
#print(largest_palindromic_num_O_n_2(3))
print(largest_palindromic_num_O_n_2(4))
print(largest_palindromic_num_4())
