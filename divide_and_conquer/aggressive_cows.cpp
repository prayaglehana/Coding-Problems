#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool checkIfPossible(int *a,int N,int C,int MIN_DIST){

    int preCINDX=0;
    int c=1;

    for(int i=1;i<N;++i){
        if((a[i]-a[preCINDX])>=MIN_DIST){
            ++c;
            preCINDX=i;
        }

    }
    if(c>=C) return true;
    else return false;
}

int findMaxMin(int *a,int maxMin,int s,int e,int C,int N){
    if(s>e) return maxMin;

    int mid=(s+e)/2;
    //cout<<"mid"<<mid<<endl;
    bool check=checkIfPossible(a,N,C,mid);

    if(check) {maxMin=mid; return  findMaxMin(a,maxMin,mid+1,e,C,N);}

    else return findMaxMin(a,maxMin,s,mid-1,C,N);
}

int main(){
    int N,C;
    int a[10000];
    cin>>N>>C;

    for(int i=0;i<N;++i) cin>>a[i];

    sort(a,a+N);

    cout<<findMaxMin(a,0,0,a[N-1]-a[0],C,N);



return 0;}
