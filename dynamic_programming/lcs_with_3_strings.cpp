
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dp[200][200][200];

int LCS(int i,int j,int k,string &s1,string &s2,string &s3){

    if(dp[i][j][k]!=-1) return dp[i][j][k];

    if(i==0 || j==0 || k==0) return dp[i][j][k]=0;

    if(s1[i-1]==s2[j-1] && s2[j-1]==s3[k-1])
        dp[i][j][k]=1+LCS(i-1,j-1,k-1,s1,s2,s3);

    else{
        int a,b,c;
        a=b=c=0;

        a=LCS(i-1,j,k,s1,s2,s3);
        b=LCS(i,j-1,k,s1,s2,s3);
        c=LCS(i,j,k-1,s1,s2,s3);

        dp[i][j][k]=max(max(a,b),c);

    }

    return dp[i][j][k];


}



int main(){

string s1,s2,s3;
cin>>s1>>s2>>s3;

for(int i=0;i<=s1.length();++i){
    for(int j=0;j<=s2.length();++j){
        for(int k=0;k<=s3.length();++k)
            dp[i][j][k]=-1;
    }
}
cout<<LCS(s1.length(),s2.length(),s3.length(),s1,s2,s3);



return 0;}
