#include<iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
unordered_map<ll,ll> mp;
int main(){

ll t;
cin>>t;
ll *a=new ll[100001];
while(t--){
    ll n;
    cin>>n;
    mp.clear();
    for(ll i=0;i<n;++i)cin>>a[i];
    ll csum=0;
    for(ll i=0;i<n;++i){
        csum+=a[i];
        ++mp[(csum%n+n)%n];
    }

    ll total=0;
    for(auto it=mp.begin();it!=mp.end();++it){
        //cout<<it->first<<" : "<<it->second<<endl;
        if(it->first==0) total+=it->second;
        total+=it->second*(it->second-1)/2;
    }
    cout<<total<<endl;
}

return 0;
}
