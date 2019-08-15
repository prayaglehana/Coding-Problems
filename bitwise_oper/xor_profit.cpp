#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int get_ith_bit(string b,int i,int max_len){
    return ((int(b[max_len-i-1])-48));
}
int main(){
    int L,R;
    cin>>L;
    cin>>R;
     int x=L^R;
 //cout<<"L  "<<bitset<8>(L).to_string()<<endl;
  //cout<<"R  "<<bitset<8>(R).to_string()<<endl;
   //cout<<"XOR"<<bitset<8>(x).to_string();

    int p=0;
    while(x>0){
        x=x>>1;
        p=p+1;
    }
    //cout<<"p"<<p;

  int t=0;
  if(L==R) cout<<x;
  else{
      while(t<p-1) {L=L|(1<<t) ;++t;} L=(~(1<<t))&L; t=0;
    while(t<p-1) {R=(~(1<<t))&R ;++t;}   R=R|(1<<t) ;

    //cout<<"new L"<<bitset<8>(L).to_string();
      //cout<<"new R"<<bitset<8>(R).to_string();
      int ans=L^R;
 cout<<ans;


  }

    return 0;
}





