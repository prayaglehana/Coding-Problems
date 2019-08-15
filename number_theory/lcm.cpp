#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(b==0) return a;

    return gcd(b,a%b);
}
int lcm(int a,int b){
    if(a>b)
        return a*b/gcd(a,b);
    else
        return a*b/gcd(b,a);
}

int main(){

int a,b;
cin>>a>>b;

cout<<lcm(a,b);

return 0;
}
