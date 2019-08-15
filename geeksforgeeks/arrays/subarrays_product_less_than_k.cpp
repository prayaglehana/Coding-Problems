#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
long long int t;
cin>>t;
long long int *a=new long long int[10001];

while(t--){

    long long int n,k;
    cin>>n>>k;

    for(long long int i=0;i<n;++i)cin>>a[i];

    long long int i=0,j=0;
    long long int prod=1;

    long long int total=0;
    while( i<=j && j<n)
    {
        //cout<<" i "<<i<<" j "<<j<<" prod :"<<prod<<endl;

        if(prod*a[j]<k){

            prod*=a[j];
            total+=(j-i+1);

            ++j;

        }
        else{

            while(i<=(j) && prod*a[j]>=k){

                    prod=prod/a[i];
                    ++i;

            }
            if(i>j){++j;prod=1;}


        }
    }

    cout<<total<<endl;
}




return 0;}
