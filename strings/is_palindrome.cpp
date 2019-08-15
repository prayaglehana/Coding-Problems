#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int* s,int n){

    for(int i=0;i<n/2;++i){
        if(s[i]!=s[n-i-1]) return false;
    }
    return true;

}
int main(){
int n;
cin>>n;
int *s=new int[n];

for(int i=0;i<n;++i)cin>>s[i];

if(isPalindrome(s,n)) cout<<"true"<<endl;
else cout<<"false"<<endl;

return 0;}
