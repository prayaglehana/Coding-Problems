
#include<iostream>
using namespace std;

void getNext(int* a,int i,int M,int N){
    if(i>=N) {cout<<endl;return;}
    if(a[i]==M) cout<<i<<" ";
     getNext(a,i+1,M,N);

}

int main(){
int M,N;
cin>>N;
int a[1000];
for(int i=0;i<N;++i) cin>>a[i];
cin>>M;
getNext(a,0,M,N);


return 0;}
