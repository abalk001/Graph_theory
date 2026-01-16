import matplotlib.pyplot as plt 

degrees = [1,3,2,2]

plt.hist(degrees, bins=range(min(degrees), max(degrees) + 2), density=True, rwidth = 0.8)
plt.show()
