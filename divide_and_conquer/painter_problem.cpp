#include<iostream>
#include<bits/stdc++.h>

using namespace std;
long long int m= 10000003;

bool checkIfPossible(long long int maxtime,long long int *a,long long int N,long long int K){
    long long int p=1,sum_p=0;
    for(long long int i=0;i<N;++i){
            if((sum_p+a[i])>maxtime){
                ++p;
                sum_p=a[i];
                if(sum_p>maxtime) return false;
            }
            else{
                sum_p=(sum_p+(a[i]));
            }
    }
    if(p<=K) return true;

    return false;
}

long long int findMinMax(long long int s,long long int e,long long int *a,long long int N,long long int K,long long int minMax){
    if(s>e) return minMax;

    long long int mid=(s+e)/2;
    //cout<<"mid"<<mid<<endl;
    bool check=checkIfPossible(mid,a,N,K);

    if(check) {minMax=mid; return  findMinMax(s,mid-1,a,N,K,minMax);}

    else return findMinMax(mid+1,e,a,N,K,minMax);
}



 int main(){

    long long int N,K,PPU;
    long long int a[10000];

    cin>>N>>K>>PPU;

    for(long long int i=0;i<N;++i) cin>>a[i];

    sort(a,a+N);
    long long int sum_=0;

    for(long long int i=0;i<N;++i) sum_+=a[i];


    cout<<(findMinMax(0,sum_,a,N,K,sum_)*PPU)% m<<endl;




return 0;
}
