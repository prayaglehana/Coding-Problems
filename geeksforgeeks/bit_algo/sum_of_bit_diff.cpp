#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int N;
int main(){

int T;
cin>>T;
while(T--){
        cin>>N;

        int a[10];

        int max_diff=0;
        for(int i=0;i<N;++i) cin>>a[i];
        for(int i=0;i<N;++i){
            for(int j=i+1;j<N;++j){
                  max_diff+= __builtin_popcount(a[i]^a[j]);


            }
        }
        cout<<max_diff<<endl;
}

return 0;}
