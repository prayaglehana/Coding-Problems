#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long int dp[10001]={0};

void defineUglyNumbers(){
    for(int i=1;i<=6;++i)dp[i]=i;
    dp[7]=8;

    for(int i=8;i<=10000;++i){
        int j=i-2;
        dp[i]=2*dp[i-1];
        while(5*dp[j]>dp[i-1] && j>=1){

                if(dp[j]*2>dp[i-1]) dp[i]=min(dp[i],dp[j]*2);
                if(dp[j]*3>dp[i-1]) dp[i]=min(dp[i],dp[j]*3);
                if(dp[j]*5>dp[i-1]) dp[i]=min(dp[i],dp[j]*5);
                --j;
       }
    }
}
void _defineUglyNumbers(){
    int i2=1,i3=1,i5=1;
    dp[1]=1;
    for(int i=2;i<=10000;++i){

        long long int next_ugly=min(dp[i2]*2,min(dp[i3]*3,dp[i5]*5));

        dp[i]=next_ugly;
        if(next_ugly==dp[i2]*2)++i2;
        if(next_ugly==dp[i3]*3) ++i3;
        if(next_ugly==dp[i5]*5) ++i5;

    }
}
int main(){
int n;


defineUglyNumbers();
int t;
cin>>t;

while(t--){
    cin>>n;
    cout<<dp[n]<<endl;
//    for(int i=1;i<=n;++i)
//       cout<<dp[i]<<" ";
}


return 0;
}

