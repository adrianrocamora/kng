def add_nums(n):
  # Add increasing numbers till n

  def rec_add_nums(accum, curr, end_num):
    if curr == end_num:
      return accum + curr
    return rec_add_nums(accum + curr, curr + 1, end_num)

  res = rec_add_nums(0, 1, n)
  print(res)

add_nums(1)
add_nums(2)
add_nums(3)
add_nums(100)
