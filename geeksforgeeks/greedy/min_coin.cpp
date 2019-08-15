#include<bits/stdc++.h>
using namespace std;
int **dp;
int getMinCoins(int i,int sum,vector<int> &coins){


    if(sum<0) return INT_MAX;

    if(i<0 && sum==0) return 0;

    if(i<0 ) return INT_MAX;

    if(dp[i][sum]!=-1) return dp[i][sum];

    int ans=INT_MAX;
    if(sum>=coins[i]){
        ans=getMinCoins(i,sum-coins[i],coins);
        if(ans!=INT_MAX) ans+=1;
    }

    return dp[i][sum]=min(ans,getMinCoins(i-1,sum,coins));
}
int main(){
int t;
cin>>t;
dp=new int*[101];

for(int i=0;i<=100;++i){
    dp[i]=new int[1001];
}

while(t--){
    int n,sum;
    cin>>n>>sum;

    vector<int> coins;

    for(int i=0;i<=n;++i){
        for(int j=0;j<=sum;++j){
            dp[i][j]=-1;
        }
    }

    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        coins.push_back(x);
    }
    sort(coins.begin(),coins.end());

    int ans=getMinCoins(n-1,sum,coins);

    if(ans==INT_MAX) cout<<"-1"<<endl;
    else cout<<ans<<endl;

//    for(int i=0;i<n;++i){
//        for(int j=1;j<=sum;++j){
//           cout<<setw(2)<<dp[i][j]<<" ";
//        }
//        cout<<endl;
//    }



}

return 0;}
