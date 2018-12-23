import numpy as np
import matplotlib
# matplotlib.use('TkAgg')
import matplotlib.pyplot as plt
import seaborn as sns

# sns.set()
sns.set(style='darkgrid')

# Scale plot elements
sns.set(context='notebook')    # notebook, paper, talk, poster
# TODO: Fix margins in some plots? 

# plt.xkcd()

t = np.arange(0.0, 2.0, 0.01)
s = np.sin(2*np.pi*t)
plt.plot(t, s)

plt.xlabel('time (s)')
plt.ylabel('voltage (mV)')
plt.title('About as simple as it gets, folks')
# plt.grid(True)
plt.savefig("test.png")
plt.show()
