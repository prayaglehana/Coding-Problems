
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    int N;
    while(T--){
         cin>>N;
        cout<<__builtin_popcount(N)<<endl;

    }
    return 0;
}


