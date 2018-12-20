li = [x for x in range(1, 10) if x % 3 == 0]
print(li)
print(' ')

sqA = []
for x in range(10):
    sqA.append(x**2)
print(sqA)

sqB = [x**2 for x in range(10)]
print(sqB)

sqC = map(lambda x: x**2, range(10))
print(sqC)
