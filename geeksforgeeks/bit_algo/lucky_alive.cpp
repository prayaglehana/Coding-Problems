#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int T=0;
int main(){
cin>>T;

while(T--){
    int N;
    cin>>N;


    cout<<3+((N-(1<<int(log2(N))))-1)*2<<endl;
}
return 0;
}
