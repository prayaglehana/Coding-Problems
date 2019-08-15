#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){

int n1;
cin>>n1;
int a1[n1];
for(int i=0;i<n1;++i) cin>>a1[n1-i-1];

int n2;
cin>>n2;
int a2[n2];
for(int i=0;i<n2;++i) cin>>a2[n2-i-1];

int n=min(n1,n2);
int carry=0;

int ans[max(n1,n2)+1];

for(int i=0;i<n;++i){
    int sum=a1[i]+a2[i]+carry;
    ans[i]=sum%10;
    carry=sum/10;
}
if(n1<n2){
    for(int i=n1;i<n2;++i){
        ans[i]=(a2[i]+carry)%10;
        carry=(a2[i]+carry)/10;
    }
}
else if(n1>n2){
    for(int i=n2;i<n1;++i){
        ans[i]=(a1[i]+carry)%10;
        carry=(a1[i]+carry)/10;
    }
}
int len=max(n1,n2);

if(carry>0){

    ans[max(n1,n2)]=carry;
    ++len;
}

for(int i=len-1;i>=0;--i) cout<<ans[i]<<", ";
cout<<"END";



return 0;}
