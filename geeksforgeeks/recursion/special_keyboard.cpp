#include<iostream>
using namespace std;
int M[76]={0};
int getMaxA(int i,int N,int totalA){
  if(i>N) return totalA;

  int X=getMaxA(i+1,N,1+totalA);
  int Y =getMaxA(i+3,N,2*totalA);

 // cout<<"i "<<i<<" X "<<X<<" Y "<<Y<<" totalA "<<totalA<<endl;
 if(X>Y) return X;
 else return Y;


}
int main(){
int T;
cin>>T;

M[1]=1;M[2]=2,M[3]=3,M[4]=4;
        for(int i=5;i<76;++i){

           int max_=0;
            for(int x=1;x<=(i-3);++x){
                if(max_<(M[x]+M[x]*(i-(x+2)))){
                    max_=M[x]+M[x]*(i-(x+2));
                }
            }
            M[i]=max(M[i-1]+1,max_);
        }
//        for(int i=1;i<20;++i){
//           cout<<M[i]<<" ";
//        }

    while(T--){

        int N;
        cin>>N;
        cout<<M[N]<<endl;



    }



return 0;
}
