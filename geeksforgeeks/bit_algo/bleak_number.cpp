#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){

        int N;
        cin>>N;
        bool flag=true;
        for(int i=(N-ceil(log2(N)));i<N;++i)
            if(i+__builtin_popcount(i)==N) flag=false;
        if(flag) cout<<"1"<<endl;
        else cout<<"0"<<endl;
    }
return 0;
}
