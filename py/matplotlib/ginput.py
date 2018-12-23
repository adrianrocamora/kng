import matplotlib.pyplot as plt
import numpy as np

t = np.arange(10)
plt.plot(t, np.sin(t))
print("Please click")

# Get two clicks from the user (will only render 1 mark)
x = plt.ginput(2)
print("Clicked", x)
plt.show()
