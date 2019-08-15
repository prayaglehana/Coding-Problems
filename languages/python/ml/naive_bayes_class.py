import pandas as pd
import numpy as np

data = pd.read_csv('data_set.csv')

print(data)


play=data['play'].values

N=len(play)

#X=[str(s) for s in input().split()]
X=['sunny','cool','normal','T']
p_yes=np.count_nonzero(play=='yes')/len(play)
p_no=1-p_yes


p_yes_X=1
for j in range(0,len(X)):
    p1_d=0
    p1_n=0
  
    for i in range(0,N):
        if(play[i]=='yes'):
            p1_d=p1_d+1
            if(data.iloc[:,j][i]==X[j]):
                p1_n=p1_n+1

    p_yes_X=p_yes_X*(p1_n/p1_d)
    
p_yes_X=p_yes_X*p_yes

p_no_X=1
for j in range(0,len(X)):
    p1_d=0
    p1_n=0
  
    for i in range(0,N):
        if(play[i]=='no'):
            p1_d=p1_d+1
            if(data.iloc[:,j][i]==X[j]):
                p1_n=p1_n+1

    p_no_X=p_no_X*(p1_n/p1_d)
    
p_no_X=p_no_X*p_no

p_yes_X=p_yes_X/(p_yes_X+p_no_X)
p_no_X=1-p_yes_X

print(p_yes_X)
print(p_no_X)
if(p_yes_X>p_no_X):
    print('yes')
else:
    print('no')
