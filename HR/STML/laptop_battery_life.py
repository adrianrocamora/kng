import scipy.stats
import matplotlib.pyplot as plt

chargeTime = [2.81, 7.14, 2.72, 3.87, 1.90, 7.82, 7.02, 5.50, 9.15, 4.87, 8.08, 5.58, 9.13, 
              0.14, 2.00, 5.47, 0.80, 4.37, 5.31, 0.00, 1.78, 3.45, 6.13, 3.53, 4.61, 1.76, 
              6.39, 0.02, 9.69, 5.33, 6.37, 5.55, 7.80, 2.06, 7.79, 2.24, 9.71, 1.11, 8.38, 
              2.33, 1.83, 5.94, 9.20, 1.14, 4.15, 8.43, 5.68, 8.21, 1.75, 2.16, 4.93, 5.75, 
              1.26, 3.97, 4.39, 7.53, 1.98, 1.66, 2.04, 11.72,4.64, 4.71, 3.77, 9.33, 1.83, 
              2.15, 1.58, 9.29, 1.27, 8.49, 5.39, 3.47, 6.48, 4.11, 1.85, 8.79, 0.13, 1.44, 
              5.96, 3.42, 1.89, 1.98, 5.26, 0.39, 6.05, 1.99, 1.58, 3.99, 4.35, 6.71, 2.58, 
              7.37, 5.77, 3.97, 3.65, 4.38, 8.06, 8.05, 1.10, 6.65]

batteryLife = [5.62, 8.00, 5.44, 7.74, 3.80, 8.00, 8.00, 8.00, 8.00, 8.00, 8.00, 8.00, 8.00, 
               0.28, 4.00, 8.00, 1.60, 8.00, 8.00, 0.00, 3.56, 6.90, 8.00, 7.06, 8.00, 3.52, 
               8.00, 0.04, 8.00, 8.00, 8.00, 8.00, 8.00, 4.12, 8.00, 4.48, 8.00, 2.22, 8.00, 
               4.66, 3.66, 8.00, 8.00, 2.28, 8.00, 8.00, 8.00, 8.00, 3.50, 4.32, 8.00, 8.00, 
               2.52, 7.94, 8.00, 8.00, 3.96, 3.32, 4.08, 8.00, 8.00, 8.00, 7.54, 8.00, 3.66, 
               4.30, 3.16, 8.00, 2.54, 8.00, 8.00, 6.94, 8.00, 8.00, 3.70, 8.00, 0.26, 2.88, 
               8.00, 6.84, 3.78, 3.96, 8.00, 0.78, 8.00, 3.98, 3.16, 7.98, 8.00, 8.00, 5.16, 
               8.00, 8.00, 7.94, 7.30, 8.00, 8.00, 8.00, 2.20, 8.00]

chargeTimeTillCT4 = []
batteryLifeTillCT4 = []
for i in range(0, len(chargeTime)):
    if chargeTime[i] < 4:
        chargeTimeTillCT4.append(chargeTime[i])
        batteryLifeTillCT4.append(batteryLife[i])

plt.plot(chargeTime, batteryLife, 'ro')
plt.show()
plt.plot(chargeTimeTillCT4, batteryLifeTillCT4, 'ro')
plt.show()
# From the plot above we can see that there are potentially 3 regions 


reg = scipy.stats.linregress(chargeTimeTillCT4, batteryLifeTillCT4);
m = reg[0]
b = reg[1]
print('Slope is : ' + str(m))
print('Intercept is : ' + str(b))

x = float(raw_input())
if x < 4:
    res = m * x + b
else:
    res = 8;

print(res)

# Python 3
# x = float(input())
# print(m * x + b)




