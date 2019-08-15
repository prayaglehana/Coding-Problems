
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long int calculate_power(int x,int p){
    if(p==0) return 1;
    if(p&1) return calculate_power(x,p/2)*calculate_power(x,p/2)*x;
    else return calculate_power(x,p/2)*calculate_power(x,p/2);
}
int main(){

    int x;
    int p;
    cin>>x;
    cin>>p;
    cout<<calculate_power(x,p);


    return 0;
}

