#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){

string s;
cin>>s;
int count_=1;

string ans="";
ans=s[0];
for(int i=1;i<s.length();++i){
    if(s[i]==s[i-1])++count_;
    else{
        ans+=to_string(count_);
        count_=1;
        ans+=s[i];
    }
}
ans+=to_string(count_);
cout<<ans;
return 0;}
