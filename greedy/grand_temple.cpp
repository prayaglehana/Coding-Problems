#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;

int *x=new int[n];
int *y=new int[n];

for(int i=0;i<n;++i){
    int X,Y;
    cin>>X>>Y;
    x[i]=X;
    y[i]=Y;
}

int delY=0,delX=0;
sort(x,x+n);
sort(y,y+n);

for(int i=0;i<n-1;++i)delY=max(delY,y[i+1]-y[i]-1);
for(int i=0;i<n-1;++i)delX=max(delX,x[i+1]-x[i]-1);

cout<<delX*delY<<endl;
return 0;}
