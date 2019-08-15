#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int *a=new int[n];

for(int i=0;i<n;++i)cin>>a[i];

int max_=INT_MIN;

for(int i=0;i<n;++i){
    max_=max(max_,a[i]);
}
cout<<max_<<endl;
return 0;}
