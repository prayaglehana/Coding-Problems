#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){

string s;
cin>>s;

string ans="";

for(int i=0;i<s.length()-1;++i){
    ans+=s[i];
    int x=s[i+1]-s[i];
    char ch;
    if(x<0){
        ans+='-';
        ans+=to_string(abs(x));
   //    ans+=(abs(x)+'0');
    }
    else ans+=to_string(x);
}
ans+=s[s.length()-1];

cout<<ans<<endl;
return 0;}
