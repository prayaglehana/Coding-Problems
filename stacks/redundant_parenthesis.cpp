#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void showStack(stack<char> stck){
    cout<<"stack : ";
    while(!stck.empty()){
        cout<<stck.top()<<" ";
        stck.pop();
    }
    cout<<endl;
}

bool isRedundant(string &s){
    int n=s.length();
    stack<char> stck;
    int i=0;
    while(i<n){
        //showStack(stck);
        if(!stck.empty() && stck.top()=='(' && s[i]==')') return true; //is redundant

        if(s[i]==')'){
            while(stck.top()!='('){
                    stck.pop();
                }
            stck.pop();

        }
        else{
            stck.push(s[i]);
        }
        ++i;
    }
    return false;
}

int main(){

int t;
cin>>t;

while(t--){
    string s;
    cin>>s;

    if(isRedundant(s)) cout<<"Duplicate"<<endl;
    else cout<<"Not Duplicates"<<endl;




}



return 0;}
