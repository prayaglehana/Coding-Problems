#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,ans=0;
    cin>>N;
    int ar[100000];
    for(int i=0;i<N;++i){cin>>ar[i];}

    for(int i=0;i<N;++i){
        ans=ans^ar[i];
    }
    cout<<ans;
return 0;
}
