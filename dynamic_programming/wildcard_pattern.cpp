#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int **dp;

bool checkIfPossible(string &str,int i,string &pat,int j){
    //cout<<"i"<<i<<"j"<<j<<endl;
 //   if(i==-1 && j==0 && pat[j]=='*' ) return true; //*a


    if(i==-1 && j==-1) return true; //saare kat gye

    if(j<0) return false; // patter mei kuch reh gya

    if(i<0){
        for(int m=0;m<=j;++m)
            if(pat[m]!='*') return false;
        return true;

    }
    if(dp[i][j]!=-1) return dp[i][j];

    bool check;
    if(pat[j]=='?' || pat[j]==str[i]){
        check=checkIfPossible(str,i-1,pat,j-1);
         dp[i][j]=check;
        return check;
    }
    if(pat[j]=='*'){

                check=checkIfPossible(str,i-1,pat,j) || checkIfPossible(str,i,pat,j-1);
                dp[i][j]=check;
                return check;
    }
dp[i][j]=0;
return false;


}

int main(){

string str,pat;
cin>>str;
cin>>pat;

dp=new int*[str.length()];
for(int i=0;i<=str.length();++i){
    dp[i]=new int[pat.length()];
}
for(int i=0;i<str.length();++i){
    for(int j=0;j<pat.length();++j){
        dp[i][j]=-1;
    }
}
cout<<checkIfPossible(str,str.length()-1,pat,pat.length()-1);

return 0;}
