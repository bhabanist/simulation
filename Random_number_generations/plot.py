from numpy import loadtxt
import matplotlib.pyplot as plt
data=loadtxt("data.txt")
#print(data)
plt.figure(figsize=(10,4))
plt.scatter(data[:,0],data[:,1],color="red",alpha=1.0,s=5)
plt.ylabel("random number value")
plt.xlabel("iteration")
plt.savefig("drand48rn.pdf",dpi=600)

