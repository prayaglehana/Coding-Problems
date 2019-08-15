#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int *dp=new int[n+1]{0};

int main(){
int DP[1000];
DP[1]=0;

int N;
cin>>N;

for(int i=2;i<=N;++i){
     =
        DP[i]=1+DP[i-1];
        if(i%2==0) DP[i]=min(DP[i],1+DP[i/2]);
        if(i%3==0) DP[i]=min(DP[i],1+DP[i/3]);
}

cout<<"ans "<<DP[N];

return 0;}
