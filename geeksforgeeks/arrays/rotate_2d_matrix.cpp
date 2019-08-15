#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
int T;
cin>>T;
while(T--){
    int a[100];
    int N;
    cin>>N;
    for(int i=0;i<N*N;++i){
            cin>>a[i];
    }

    for(int j=0;j<N;++j){
       for(int i=N-1;i>=0;--i){
        int indx=i*N+j;
        cout<<a[indx]<<" ";
       }
    }
    cout<<endl;
}
return 0;
}
