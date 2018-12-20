import scipy.stats

def f(x):
    return scipy.stats.norm.cdf(x, loc = 20, scale = 2)

# Probability the assembly will take less than 19.5 hours
print(f(19.5))
# Probability the assembly will take between 20 and 22 hours
print(f(22) - f(20))
