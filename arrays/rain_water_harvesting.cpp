#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        int *a=new int[n];
        for(int i=0;i<n;++i) cin>>a[i];

        int *LH=new int[n];
        int *RH=new int[n];

        LH[0]=a[0];
        for(int i=1;i<n;++i) LH[i]=max(a[i],LH[i-1]);
        RH[n-1]=a[n-1];
        for(int i=n-1;i>=0;--i) RH[i]=max(a[i],RH[i+1]);

        int *water=new int[n];
        for(int i=0;i<n;++i)water[i]=min(LH[i],RH[i])-a[i];

        //for(int i=0;i<n;++i)cout<<LH[i]<<" ";cout<<endl;
        //for(int i=0;i<n;++i)cout<<RH[i]<<" ";cout<<endl;
        //for(int i=0;i<n;++i)cout<<water[i]<<" ";cout<<endl;

        cout<<accumulate(water,water+n,0)<<endl;
    }



return 0;}
