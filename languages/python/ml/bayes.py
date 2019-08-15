import numpy as np
import matplotlib.pyplot as plt
X=[1,2,3,4,5,6]
Y=[3,6,7,8,10,14]

Y_p=[2.6,5.6,7.2,8.1,10.2,14.1]

plt.scatter(X,Y)
plt.plot(X,Y_p, color='blue', linewidth=3)
plt.show()
SSR=0
for i in range(0,len(Y)):
    SSR=SSR+(Y[i]-Y_p[i])**2
SST=0
y_mean=np.mean(Y)
for i in range(0,len(Y)):
    SST=SST+(Y[i]-y_mean)**2

print('Rsq',1-(SSR/SST))
