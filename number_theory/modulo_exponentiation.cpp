#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long int modexponent(long long int a,long long int b,long long int c){ //a^bmodc
        long long int res=1;
        long long int p=a%c;
        while(b>0){
            if(b&1) res=(res*p)%c;
            p=(p*p)%c;
            b=b>>1;
        }
        return res;
}
int main(){
long long int a,b,c;
cin>>a>>b>>c;
cout<<modexponent(a,b,c);

return 0;}
