import numpy as np
import matplotlib.pyplot as plt

# Load data
data = np.loadtxt("data.txt")

# Scatter plot for data
plt.figure(figsize=(10, 4))
plt.scatter(data[:, 0], data[:, 1], color="red", alpha=1.0, s=5)
plt.ylabel("Random Number Value")
plt.xlabel("Iteration")
plt.savefig("drand48rn.pdf", dpi=600)


# Histogram of the second column
histy, bin_edges = np.histogram(data[:, 1], bins=20, range=(-1, 1))
bin_centers = 0.5 * (bin_edges[1:] + bin_edges[:-1])

# Plot histogram
plt.figure(figsize=(9, 6))
plt.plot(bin_centers, histy, drawstyle='steps-mid', color="blue")
plt.xlabel("Random Number Value")
plt.ylabel("Frequency")
plt.ylim(0,1000)
plt.savefig("drand48rn_hist.pdf",dpi=600)

