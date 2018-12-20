import scipy.stats

physics = [15, 12, 8, 8, 7, 7, 7, 6, 5, 3]
history = [10, 25, 17, 11, 13, 17, 20, 13, 9, 15]
pearsonRVal, _ = scipy.stats.pearsonr(physics, history)
print(pearsonRVal)
print(round(pearsonRVal*1000)/1000)





