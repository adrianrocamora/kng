import matplotlib.pyplot as plt
import numpy as np

t = np.arange(10)
plt.plot(t, np.sin(t))
print("Please click")

# Get unlimited clicks
x = plt.ginput(0)
print("Clicked", x)
plt.show()

# middle mouse button stops input
# left mouse button adds input
# right mouse button pops previous input
