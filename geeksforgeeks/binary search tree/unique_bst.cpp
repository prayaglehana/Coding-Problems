#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
int A[20];
A[0]=1;
A[1]=1;
A[2]=2;
A[3]=5;
for(int i=2;i<=11;++i){
    int sum_=0;
   // cout<<"new i "<<i<<endl;
    for(int j=floor(i/2);j<i;++j){
      //  cout<<" J "<<j<<" ";
        sum_+=A[j]*A[i-j-1];
    }


    sum_=2*sum_;
    if(i&1) {

            int j=floor(i/2);
            sum_=sum_-A[j]*A[i-j-1];
    }
    A[i]=sum_;
    //cout<<endl;

}
//for(int i=0;i<11;++i){
//    cout<<A[i]<<" ";
//}
int T;
cin>>T;
while(T--){
    int x;
    cin>>x;
    cout<<A[x]<<endl;
}


return 0;
}

