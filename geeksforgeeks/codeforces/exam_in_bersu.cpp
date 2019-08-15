#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){
int N,M;
int ar[101];
int output[101];
cin>>N>>M;

for(int i=0;i<N;++i) cin>>ar[i];

int csum=0;
for(int i=0;i<N;++i) {
    sort(ar,ar+i);
    csum+=ar[i];
    int count_min=0;

    int tsum=csum;
    int cur=i-1;

    while(tsum>M){
        if(cur<0)
            break;
        tsum-=ar[cur];
        ++count_min;
        --cur;

    }
    output[i]=count_min;
}
for(int i=0;i<N;++i){
    cout<<output[i]<<" ";
}



return 0;}
