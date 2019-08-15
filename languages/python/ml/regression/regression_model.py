import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

def calErr(y_pred,Y):
    e=0
    for i in range(0,len(y_pred)):
        e=e+(y_pred[i]-Y[i])**2
    return e/len(y_pred)
        

data = pd.read_csv('sample_data.csv')

X=data['X'].values
Y=data['Y'].values

#plt.axis([0,10,0,10])

x_mean=np.mean(X)
y_mean=np.mean(Y)

alpha=0.01
b1=0.2
b0=y_mean-b1*x_mean

y_pred=[(b0+b1*x) for x in X]

e=calErr(y_pred,Y)
print(e)

plt.scatter(X,Y)
plt.plot(X,y_pred, color='blue', linewidth=3)
plt.show()
del_e=1
print('y',y_pred)
while(del_e>0.03):
  for i in range(0,len(X)):
    err=(Y[i]-(b0+b1*X[i]))
    b1=b1+alpha*err*X[i]
 
  b0=y_mean-b1*x_mean
  
  y_pred=[(b0+b1*x) for x in X]
  e_new=calErr(y_pred,Y)

  del_e=e-e_new
  e=e_new
  print(del_e)

  plt.scatter(X,Y)
  plt.plot(X,y_pred, color='blue', linewidth=3)
  plt.show()

    
print(y_pred)
plt.scatter(X,Y)
plt.plot(X,y_pred, color='blue', linewidth=3)
plt.show()



