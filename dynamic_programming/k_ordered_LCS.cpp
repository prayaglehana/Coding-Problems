#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dp[2001][2001][6];
int getLCS_K(int *a1,int *a2,int i,int j,int k){

    if(dp[i][j][k]!=-1) return dp[i][j][k];

    if(i==0 || j==0) return dp[i][j][k]=0;



    dp[i][j][k]=max(getLCS_K(a1,a2,i,j-1,k),getLCS_K(a1,a2,i-1,j,k));

    if(k>0)
        dp[i][j][k]=max(dp[i][j][k],1+getLCS_K(a1,a2,i-1,j-1,k-1));

    if(a1[i-1]==a2[j-1]){
        dp[i][j][k]=max(dp[i][j][k],1+getLCS_K(a1,a2,i-1,j-1,k));
    }

    return dp[i][j][k];
}
int main(){

int a1[2000];
int a2[2000];
int n,m,k;
cin>>n>>m>>k;

for(int i=0;i<=n;++i){
    for(int j=0;j<=m;++j){
        for(int k_=0;k_<=k;++k_){
            dp[i][j][k_]=-1;
        }

    }
}


for(int i=0;i<n;++i) cin>>a1[i];
for(int j=0;j<m;++j) cin>>a2[j];


cout<<getLCS_K(a1,a2,n,m,k)<<endl;

return 0;}
