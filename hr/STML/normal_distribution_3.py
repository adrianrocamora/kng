import scipy.stats

def f(x):
    return scipy.stats.norm.cdf(x, loc = 70, scale = 10)

# Probability that the students scored higher than 80
print(1 - f(80))
# Probability that the students passed
print(1 - f(60))
# Probability that the students failed
print(f(60))
