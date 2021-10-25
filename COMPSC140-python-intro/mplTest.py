import math

import matplotlib
import matplotlib.pyplot as plt

x_coords = [1, math.sqrt(3)/2, math.sqrt(2)/2, 1/2, 0]
y_coords = [0, 1/2, math.sqrt(2)/2, math.sqrt(3)/2, 1]

plt.plot(x_coords, y_coords)
plt.title("Unit circle quarter")
plt.grid(True)
plt.xlabel('X')
plt.ylabel('Y')

plt.show()
