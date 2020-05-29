import numpy as np
import matplotlib.pyplot as plt
import pandas as pd


def f(x,y):
 return pow(x, 2) - 15 * x*y + 44 * x + pow(y, 3) - 6 * pow(y, 2) - 93 * y + 251
n=150
data1 = np.loadtxt("vect.txt")
x = np.linspace(-274, 274, n)
y = np.linspace(-40, 40, n)
X, Y = np.meshgrid(x, y)
Z=f(X,Y)
fig = plt.figure(facecolor='white')
ax1 = fig.add_subplot(1,1,1)
ax1.contour(X,Y,Z)

ax1.plot(data1[:,0],data1[:,1])

plt.show()