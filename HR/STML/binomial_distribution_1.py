import scipy.stats

print(scipy.stats.binom.sf(2, 4, 0.8))
print(scipy.stats.binom.pmf(3, 4, 0.8) + scipy.stats.binom.pmf(4, 4, 0.8))
print(" ")
print(scipy.stats.binom.cdf(1, 4, 0.8))
print(scipy.stats.binom.pmf(0, 4, 0.8) + scipy.stats.binom.pmf(1, 4, 0.8))
