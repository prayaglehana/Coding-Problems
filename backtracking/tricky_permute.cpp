#include<iostream>
#include<bits/stdc++.h>
using namespace std;
set<string> myset;
void permute(string &str,string output,int status,int &n){

    if(status==0){

        myset.insert(output);
    }
    for(int i=0;i<n;++i){
        if((status>>i)&1){

            output+=str[i];

            permute(str,output,(status&(~(1<<i))),n);

            output.erase(output.length()-1);
        }
    }
}

int main(){
    string str;
    cin>>str;
    int n=str.length();
    int status=(1<<n)-1;
    string output="";
    permute(str,output,status,n);

    for(string s:myset){
        cout<<s<<endl;
    }
return 0;}
