#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int getMax(int n,char ch,int k,string &str){


    int amax=INT_MIN;
    inr bmax=INT_MIN;
    if(str[n]=='a'){
        amax=getMax(n-1,'a',k);
        if(k>0)
            bmax=getMax(n-1,'b',k-1);
        return max(amax,bmax);
    }
    else{

    }

}

int main(){

int k;
cin>>k;
string str;
cin>>str;




return 0;}



