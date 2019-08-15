#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,ans=0;
    cin>>N;
    int ar[100000];
    int setA[100000];
    int setB[100000];

    for(int i=0;i<N;++i){cin>>ar[i];}

    int sab_ka_xor=0;
    for(int i=0;i<N;++i){
        sab_ka_xor=sab_ka_xor^ar[i];
    }
    int p=0;
    int temp=sab_ka_xor;
    //cout<<"sab_xor  "<<temp<<" "<<bitset<8>(temp).to_string()<<endl;
    while(temp>0){

        if(temp&(1)) break;
        temp=temp>>1;
        ++p;
    }
    //cout<<"pos"<<p<<endl;
    for(int i=0;i<N;++i){
        if(ar[i]&(1<<p)) setA[i]=ar[i];
        else setB[i]=ar[i];
    }
    //for(int i=0;i<N;++i)cout<<setA[i];cout<<endl;
    //for(int i=0;i<N;++i)cout<<setB[i];cout<<endl;

    for(int i=0;i<N;++i)ans=(ans^setA[i]);

    if(ans<(ans^sab_ka_xor)) cout<<ans<<" "<<(ans^sab_ka_xor);
    else     cout<<(ans^sab_ka_xor)<<" "<<ans;



return 0;
}

