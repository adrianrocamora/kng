import scipy.stats

print(scipy.stats.binom.sf(2, 6, 1.09/2.09))
print(scipy.stats.binom.pmf(3, 6, 1.09/2.09) +
      scipy.stats.binom.pmf(4, 6, 1.09/2.09) +
      scipy.stats.binom.pmf(5, 6, 1.09/2.09) +
      scipy.stats.binom.pmf(6, 6, 1.09/2.09))
