#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dp[100];
int fib(int n){
    if(dp[n]!=-1) return dp[n];
    if(n==0 ) return 1;
    if(n==1) return 2;
    return dp[n]=fib(n-1)+fib(n-2);
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<=100;++i) dp[i]=-1;
    for(int i=1;i<=t;++i){
        int n;
        cin>>n;
        cout<<"#"<<i<<" : "<<fib(n)<<endl;
    }
return 0;
}
