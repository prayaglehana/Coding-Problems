#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int getTotalWays(int x,int cx,int n){

if(x<0) return 0;
if(x==0) return 1;

int sum=0;
cout<<"x "<<x<<"-> ";
for(int cx_=cx;cx_<=floor(pow(x,1.0/n));++cx_) {
    int y=getTotalWays(x-pow(cx_,n),cx_+1,n);
    if(y){//`   cout<<"square of"<<cx_;
     sum+=y;}
    }
//if(sum>0) cout<<"x"<<x<<"cx"<<cx<<"sum"<<sum<<endl<<endl;
cout<<endl;
return sum;
}

int main(){
int T;
cin>>T;
while(T--){
    int X,N;
    cin>>X>>N;


    cout<<getTotalWays(X,1,N)<<endl;


}

return 0;}





