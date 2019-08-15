#include<iostream>
using namespace std;

int main(){
int n,cap;
cin>>n>>cap;
int **dp=new int*[n+1];
for(int i=0;i<=n;++i){
    dp[i]=new int[cap+1];
}

for(int j=0;j<=cap;++j){
    for(int i=0;i<=n;++i){
            dp[i][j]=0;
    }
}
int w[1001];
int v[1001];


for(int i=1;i<=n;++i) cin>>w[i];
for(int i=1;i<=n;++i) cin>>v[i];

for(int i=1;i<=n;++i){
    dp[i][1]=dp[i-1][1];
    if(w[i]<=1){
        dp[i][1]=max(v[i],dp[i][1]);
    }
}
for(int j=1;j<=cap;++j){
    dp[1][j]=dp[1][j-1];
    if(w[1]<=j){
        dp[1][j]=max(v[1],dp[1][j]);
    }
}


for(int j=2;j<=cap;++j){
    for(int i=2;i<=n;++i){

            dp[i][j]=dp[i-1][j];
            if(j>=w[i]){
                dp[i][j]=max(dp[i][j],dp[i][j-w[i]]+v[i]);
            }
    }
}

//for(int j=1;j<=cap;++j){
//    for(int i=1;i<=n;++i){
//
//            cout<<dp[i][j]<<" ";
//    }
//    cout<<endl;
//}

cout<<dp[n][cap];
return 0;
}

