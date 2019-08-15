#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printParenthesis(string output,int n,int opened){
    if(n==0){
        if(opened==0)
            cout<<output<<endl;
        return;
    }
    if(opened>0){
        output+=')';
        --opened;

        printParenthesis(output,n-1,opened);

        output.erase(output.length()-1);
        ++opened;
    }

    if(n>0){
        output+='(';
        ++opened;
        printParenthesis(output,n-1,opened);
    }

}
int main(){
    int n;
    cin>>n;
    string output="";
    printParenthesis(output,2*n,0);
}
