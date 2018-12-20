import scipy.stats

def f(x):
    return scipy.stats.norm.cdf(x, loc = 30, scale = 4)

# Probability of x < 40
print(f(40))
# Probability of x > 21
print(1 - f(21))
# Probability of 30 < x < 35
print(f(35) - f(30))
