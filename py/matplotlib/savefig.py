import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(-5, 5, 100)
y = x **3

fig = plt.figure()
plt.plot(x,y)
fig.savefig('cubic.png')
fig.savefig('cubic.jpg') 


