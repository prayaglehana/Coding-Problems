#include<iostream>
using namespace std;
int M=1000000007;

int DPT[100000];



int totalTiles(int x,int y){


if(y<0) return 0;

if(DPT[y]!=-1) return DPT[y];
//cout<<"x,y"<<x<<y<<endl;
DPT[y]=(totalTiles(x,y-1)%M+totalTiles(x,y-x)%M)%M;
return DPT[y];
}
int main(){


int T;
cin>>T;
while(T--){
    int N,M;
    DPT[0]=1;
    for(int i=1;i<100000;++i) {DPT[i]=-1;}
    cin>>N>>M;
    //if(M>N) cout<<1;
    //else if(M==N) cout<<2;
    //else
     cout<<totalTiles(M,N)<<endl;

}

return 0;}
