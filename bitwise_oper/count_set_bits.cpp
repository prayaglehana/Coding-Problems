#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
int T;
cin>>T;
while(T--){
        int N=0;
    cin>>N;
    int count_=0;

    //cout<<"N "<<bitset<8>(N).to_string()<<endl;
    while(N>0)
        {count_=count_+(N&1);

        N=N>>1;}
    cout<<count_<<endl;
}
return 0;
}
