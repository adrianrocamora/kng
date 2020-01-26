
results = [[]]
print(results)
print()
for i in [0,1]:
  temp = []
  for result in results:
    for letter in ['a', 'b', 'c']:
      temp.append(result + [letter])
      print('result + [letter]')
      print(result + [letter])
    print('temp')
    print(temp)
  results = temp
print()
print('results final')
print(results)
print(["".join(r) for r in results])

