import sympy as sp
x = sp.symbols('x')
f = x ** 2 + 4 * x + 16
print(sp.solve(f, x))
