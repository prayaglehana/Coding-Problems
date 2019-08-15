#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int convertToNumber(char* s,int i,int len){
 if(i>=len) return 0;
 else return ((pow(10,len-i-1)*(int(s[i])-48))+convertToNumber(s,i+1,len));
}
int main(){
char s[10000];
cin>>s;


cout<<convertToNumber(s,0,strlen(s));
return 0;}
