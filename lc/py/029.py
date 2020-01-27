# 029 - Divide two integers

# Divide two integers without using multiplication, division and the modulus
# If overflow, return MAX_INT

# Repeatedly double the divisor until
# it would exceed the dividend.
# Then repeatedly halve the divisor, 
# subtracting it from the dividend whenever possible

class Solution:
  def divide(self, dividend, divisor):

    if divisor == 0:
      return None
    # Do they have a different sign? Use XOR
    diff_sign = (divisor < 0) ^ (dividend < 0)
    dividend = abs(dividend)
    divisor = abs(divisor)

    result = 0
    max_divisor = divisor
    shift_count = 1

    while dividend >= (max_divisor << 1):
      # find divisor * 2^i where divisor * 2 ^(i+1) > dividend
      max_divisor <<= 1
      shift_count <<= 1

    while shift_count >= 1:
      # subtract max_divisor whenever possible
      if dividend >= max_divisor:
        dividend -= max_divisor
        result += shift_count
      shift_count >>= 1
      max_divisor >>= 1

    if diff_sign:
      result = -result

    # Set ranges for max_uint and min_uint
    return max(min(result, 2**31-1), -2**31)


dtop = 24
dbot = 4
print(dtop)
print(dbot)
print(Solution().divide(dtop, dbot))






