#include<iostream>
#include<bits/stdc++.h>
using namespace std;
map<long long int,long long int> m;
long long int getMax(long long int n){

    if(m.find(n)!=m.end()) return m[n];
    if(n==0) return m[n]=0;
    if(n==1) return m[n]=1;

    long long int x=0,y=0,z=0;
     x=getMax(n/2);
     y=getMax(n/3);
     z=getMax(n/4);
    //cout<<"n "<<n<<" x "<<x<<" y "<<y<<" z "<<z<<endl;

    m[n]=max(n,x+y+z);
    return m[n];

}

int main(){
long long int n;

while(cin>>n){

	cout<<getMax(n)<<endl;

}


return 0;}
