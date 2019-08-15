#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];

int makePrice(int *v,int i,int w){

    if(dp[i][w]!=-2) return dp[i][w];

    if(w==0 && i>=0  ) return dp[i][w]=0;
    if(i<=0) return dp[i][w]=-1;

    int x=-1,y=-1;

    if(v[i]!=-1){
        if(i<=w){
             int m=makePrice(v,i-1,w-i);
             if(m!=-1) x=v[i]+m ;
        }

    }



    y=makePrice(v,i-1,w);


//<<" i "<<i<<" w "<<w<<" x "<<x<<" y "<<y<<endl;

    if(x==-1) x=INT_MAX;
    if(y==-1) y=INT_MAX;

    if(min(x,y)==INT_MAX) return dp[i][w]=-1;

    return dp[i][w]=min(x,y);

}

int main(){

int n,w;
int v[1001];

cin>>n>>w;

for(int i=1;i<=n;++i){
    cin>>v[i];
}
for(int i=0;i<=n;++i){
    for(int j=0;j<=w;++j){
        dp[i][j]=-2;
    }
}

int ans=makePrice(v,n,w);
if(ans<=0) cout<<-1;
else cout<<ans;
//cout<<"dp table "<<endl;
//for(int i=0;i<=n;++i){
//    for(int j=0;j<=w;++j){
//        cout<<dp[i][j]<<" ";
//    }
//    cout<<endl;
//}

return 0;}



