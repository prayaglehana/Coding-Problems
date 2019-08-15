#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long long int dp[91]={0};
long long int calc(int n){

    if(dp[n]!=0) return dp[n];

    return dp[n]=calc(n-1)+calc(n-2);
}

int main(){
int T;
cin>>T;
dp[0]=1;
dp[1]=2;
dp[2]=3;
while(T--){
    int N;
    cin>>N;
    cout<<calc(N)<<endl;

}

return 0;
}
