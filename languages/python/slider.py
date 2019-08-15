N=int(input())
A=[int(x) for x in input().split()]
B=[int(x) for x in input().split()]
C=[0]*N
for i in range (0,N):
    C[i]=B[i]-A[i]

ptr=0
ans=True
while(True):
    if(ptr==N):
        break
    if(C[ptr]<0):
        ans=False
    elif(C[ptr]==0):
        ptr=ptr+1
    else:
        C[ptr]=C[ptr]-1
        if(ptr+1<N):
            C[ptr+1]=C[ptr+1]-2
        if(i+2<N):
            C[ptr+2]=C[ptr+2]-3
if ans is True:
    print('yes')
else:
    print('no')
    
    

