import scipy.stats

physics = [15, 12, 8, 8, 7, 7, 7, 6, 5, 3]
history = [10, 25, 17, 11, 13, 17, 20, 13, 9, 15]
# Physics is the independent variable
# Python tuples are cool
reg = scipy.stats.linregress(physics, history)
m = reg[0]
b = reg[1]
histVal = m * 10 + b
print(histVal)
print(round(histVal*10)/10)





