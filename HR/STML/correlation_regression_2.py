import scipy.stats

physics = [15, 12, 8, 8, 7, 7, 7, 6, 5, 3]
history = [10, 25, 17, 11, 13, 17, 20, 13, 9, 15]
# Physics is the independent variable
# Python tuples are cool
slope = scipy.stats.linregress(physics, history)[0]
print(slope)
print(round(slope*1000)/1000)





