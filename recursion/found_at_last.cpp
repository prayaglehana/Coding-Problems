#include<iostream>
using namespace std;

int getPrev(int* a,int i,int M){
    if(i<0) return -1;
    if(a[i]==M) return i;
    else return getPrev(a,i-1,M);

}

int main(){
int M,N;
cin>>N;
int a[1000];
for(int i=0;i<N;++i) cin>>a[i];
cin>>M;

cout<<getPrev(a,N-1,M);


return 0;}
