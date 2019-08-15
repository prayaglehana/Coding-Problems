#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;

    int *a=new int[1000000];

    int *Lmax=new int[1000000];
    int *Rmax=new int[1000000];

    int *ans=new int[1000000];

while(t--){
    int n;
    cin>>n;


    for(int i=0;i<n;++i )cin>>a[i];

    Lmax[0]=1;
    for(int i=1;i<n;++i){
        if(a[i]>a[i-1])
            Lmax[i]=Lmax[i-1]+1;
        else Lmax[i]=1;
    }
    Rmax[n-1]=1;

    for(int i=n-2;i>=0;--i){
        if(a[i]>a[i+1])
            Rmax[i]=Rmax[i+1]+1;
        else Rmax[i]=1;
    }
    int max_len=0;
    for(int i=0;i<n;++i)    max_len=max(max_len,(Lmax[i]+Rmax[i]-1));

    cout<<max_len<<endl;

}


return 0;}
