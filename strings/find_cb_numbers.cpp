#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long int dp[100];
string substring(string &s,long long int i,long long int j){
    string ans="";
    for(long long int k=i;k<=j;++k){
        ans+=s[k];
    }
    return ans;
}

long long int string_to_integer(string &s){
    int n=s.length();
    long long int number =0;
    for(int i=n-1;i>=0;--i){
        int x=s[i]-'0';
        number+=x*round(pow(10,n-1-i));
    }
    return number;

}
bool isCB(string s,long long int i,long long int j){
    string str=substring(s,i,j);
    //cout<<" str "<<str<<endl;
    long long int number=string_to_integer(str);

    if(number==0 || number==1) return false;

    long long int CB[]={2,3,5,7,11,13,17,19,23,29};

    for(long long int k=0;k<10;++k)if(number==CB[k]) return true;

    for(long long int k=0;k<10;++k)if(number%CB[k]==0) return false;

    return true;
}
long long int getMaxCB(long long int i,long long int n,string &s){
    long long int max_len=0;

    if(i>=n) return 0;
    if(dp[i]!=-1) return dp[i];

    for(long long int k=i;k<n;++k){
        long long int next_max_CBS=getMaxCB(k+1,n,s);
        bool iscb=isCB(s,i,k);

        if(iscb) max_len=max(max_len,1+next_max_CBS);
        else max_len=max(max_len,next_max_CBS);
    }


    return dp[i]=max_len;
}
int main(){
long long int n;
cin>>n;
string s;
cin>>s;

for(long long int i=0;i<=n;++i)dp[i]=-1;

cout<<getMaxCB(0,n,s)<<endl;
//for(long long int i=0;i<n;++i)cout<<dp[i]<<" ";

return 0;}
