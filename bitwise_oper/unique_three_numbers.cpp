#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
int ar[100000];
   int bit_count[8];
   int max_len=8;

   int N;
   cin>>N;
   for(int i=0;i<N;++i){cin>>ar[i];}

   for (int i=0;i<max_len;++i){
        for(int j=0;j<N;++j){

            bit_count[i]=bit_count[i]+((ar[j]>>i)&1);
        }
        //cout<<"bit_count["<<i<<"] "<<bit_count[i]<<endl;
   }
   int ans=0;
 //for (int i=0;i<max_len;++i) {cout<<bit_count[i]%3;}
   for (int i=0;i<max_len;++i) {ans=ans+((bit_count[i]%3)*(1<<i));}
   cout<<ans<<endl;



    return 0;
}
