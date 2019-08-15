#include<iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){


ll t;
cin>>t;
ll *C=new ll[100000];
ll *L=new ll[100000];
while(t--){
    priority_queue<ll,vector<ll>,greater<ll>> p;
    ll n;
    cin>>n;


    for(ll i=0;i<n;++i)cin>>C[i];
    for(ll i=0;i<n;++i)cin>>L[i];

    ll ci=0;
    ll totalCost=0;

    while(ci!=n){
            p.push(C[ci]);
            ll ptop=p.top();
            totalCost+=ptop*(L[ci]);
            ++ci;
        }
    cout<<totalCost<<endl;
    }


return 0;}
