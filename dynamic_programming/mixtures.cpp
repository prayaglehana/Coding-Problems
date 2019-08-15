#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int sum(int *a,int i,int j){
    long long ans=0;
    for(int indx=i;indx<=j;++indx){
        ans+=a[indx];
        ans%=100;
    }
    return ans;

}
int main(){
    int n;
    cin>>n;
    int m[101];
    int dp[101][101];

    for(int i=1;i<=n;++i)cin>>m[i];


    for(int e=n;e>=1;--e){
        for(int i=1;i<=e;++i){
            int j=i+n-e;

            dp[i][j]=INT_MAX;
            if(i==j){
                dp[i][j]=0;
            }
            else{
                   for(int k=1;k<=(n-e);++k){
                   //cout<<"i "<<i<<" j "<<j<<" column "<<i<<","<<j-k<<" rows "<<j-k+1<<","<<j<<endl;
                     dp[i][j]=min(dp[i][j],dp[i][j-k]+dp[j-k+1][j]+sum(m,j-k+1,j)*sum(m,i,j-k));
                   }

            }

        }
    }

//    for(int i=1;i<=n;++i){
//        for(int j=1;j<=n;++j){
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<endl;
//    }


    cout<<dp[1][n];


return 0;}



