import random
# Random float x, 0.0 <= x <= 1.0
print(random.random())
# Random float x, 1.0 <= x <= 10.0
print(random.uniform(1, 10))
# Integer from 0 to 9
print(random.randrange(10))
# Even integer from 0 to 100
print(random.randrange(0, 101, 2))
# Single random element
print(random.choice('abcdefghij'))
# Shuffle a list
items = [1, 2, 3, 4, 5, 6, 7]
random.shuffle(items)
print(items)
