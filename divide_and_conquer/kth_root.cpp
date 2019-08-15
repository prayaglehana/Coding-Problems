#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long int getkroot(long long int ans,long long int s,long long int e,long long int N,int K){
    if(s>e) return ans;
    long long int mid=s+ (e-s)/2;
    //cout<<"s"<<s<<"emd"<<e<<" mid "<<mid << " round mid^k "<<round(pow(mid,K))<<endl;
   // if(K>1 && log10(mid)*K>18)  return getkroot(ans,s,mid-1,N,K);

    if(round(pow(mid,K))>N){
        return getkroot(ans,s,mid-1,N,K);
    }

    if(round(pow(mid,K))<=N){
        ans=mid;
        return getkroot(ans,mid+1,e,N,K);
    }

}



int main(){
int T;
cin>>T;

while(T--){

    long long int n,k;

    cin>>n>>k;
    cout<<getkroot(-1,0,n,n,k)<<endl;
}

}
