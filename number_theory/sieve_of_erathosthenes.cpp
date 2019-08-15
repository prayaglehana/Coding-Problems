#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int sieve_of_erathos(int n,int nth){
    if(nth<=10) n=100;
    bool *primes=new bool[n+1]{true};

    for(int i=0;i<=n;++i) primes[i]=true;

    for(int p=2;p*p<=n;++p){
           if(primes[p]==true){
                for(int i=p*p;i<=n;i+=p)
                    primes[i]=false;
        }

    }
    int ith=0;
    for(int i=2;i<=n;++i){

        if(primes[i]==true){
            //cout<<i<<" ";
            ++ith;
        }
        if(ith==nth) return i;
    }
}
int main(){

int nth;
cin>>nth;

int n=nth*(log(nth)+log(log(nth)))+1;
cout<<sieve_of_erathos(n,nth);

return 0;}
