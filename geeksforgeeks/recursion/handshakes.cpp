#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int totalWays(int N){

    if(N==0) return 1;
    else if(N<0 )return 0;



    int sum=0;
    for(int i=2;i<=N;i+=2){

        int x=totalWays(N-i);
        int y=totalWays(i-2);
       // cout<<"N "<<N<<"i "<<i<<" sum "<<x+y<<endl;
        sum+=(x*y);



    }

    return sum;
}
int main(){
int x,y;
int T;
cin>>T;
while(T--){
    int N;
cin>>N;
cout<<totalWays(N)<<endl;
}




return 0;
}
