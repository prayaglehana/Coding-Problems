#include<iostream>
using namespace std;
int main(){
int T;

cin>>T;

while(T--){
  int K,N;
    int Price[1001];
    Price[0]=0;
    int T[11][1001];

    cin>>K;
    cin>>N;


    for(int y=0;y<=N;++y){T[0][y]=0;}
    for(int x=0;x<=K;++x){T[x][0]=0;}



    for(int i=1;i<=N;++i){
        cin>>Price[i];
    }
    for(int k=1;k<=K;++k){
        for(int j=1;j<=N;++j){
            int max_=T[k][j-1];
            for(int m=1;m<j;++m){
                if(max_<T[k-1][m]+(Price[j]-Price[m])){
                    max_=T[k-1][m]+(Price[j]-Price[m]);
                }

            }
            T[k][j]=max_;
        }
    }
    //cout<<"T";
//    for(int k=1;k<=K;++k){
//        for(int j=1;j<=N;++j){
//            cout<<T[k][j]<<" ";
//        }
//        cout<<endl;
//    }
cout<<T[K][N]<<endl;


}
return 0;}

