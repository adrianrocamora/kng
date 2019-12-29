def foo(a, b= None):
  if b == None:
    return a
  else:
    return a + b

print(foo(1))
print(foo(1,2))

