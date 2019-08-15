#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    string ans="";

    int i=0;
    while(((str[i])-'0')==9){ans+=str[i];++i;}
//332711047202
//332211042202
    for(;i<str.length();++i){
        int d=(str[i])-'0';
        if( d>=5)d=9-d;
        char ch=d+'0';
        ans=ans+ch;
    }
    cout<<ans;
return 0;}
