#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){

int t;
cin>>t;
int a[1001];
int dp[1001];
while(t--){
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    dp[1]=0;

    for(int i=2;i<=(n);++i){
            dp[i]=INT_MAX;
            for(int j=1;j<i;++j){
                if(a[j]>=(i-j)){

                          dp[i]=min(dp[i],dp[j]+1);
                }

            }
    }
//    cout<<" dp "<<endl;
//    for(int i=1;i<=n;++i)
//        cout<<dp[i]<<" ";
//    cout<<endl;

    cout<<dp[n]<<endl;


}

return 0;}
