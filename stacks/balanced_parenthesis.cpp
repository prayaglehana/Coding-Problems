#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool balanced(string s){
    stack <char> stck;
    int n=s.length();
    int i=0;
    while(i<n){
        if(s[i]==')'){
            if(stck.empty()) return false;
            else stck.pop();
        }
        else{
            stck.push(s[i]);
        }
        ++i;

    }
    if(stck.empty()) return true;

    return false;

}
int main(){

string s;
cin>>s;

if(balanced(s)) cout<<"Yes"<<endl;
else cout<<"No"<<endl;


return 0;}
