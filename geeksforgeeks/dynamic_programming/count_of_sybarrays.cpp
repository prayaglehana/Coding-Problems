#include<iostream>
using namespace std;
int main(){
int T;
cin>>T;
while(T--){

    int N,K;
    cin>>N>>K;
    int ar[100];
    int T[100][100];

    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            T[i][j]=0;
        }
    }
    int count_=0;
    for(int i=0;i<N;++i)cin>>ar[i];

    for(int len=N;len>0;--len){

        for(int m=0;m<len;++m){
                if(N==len){
                    T[m][m]=ar[m];
                }
                else{
                        T[m][m+(N-len)]=max( T[m+1][m+(N-len)], T[m][m+(N-len)-1]);
                }
                if(T[m][m+(N-len)]>K) ++count_;

        }
    }
//
//    for(int i=0;i<N;++i){
//        for(int j=0;j<N;++j){
//            cout<<T[i][j]<<" ";
//        }
//        cout<<endl;
//    }

    cout<<count_<<endl;

}

return 0;}
