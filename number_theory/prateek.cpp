#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool *primes;
int *nthprime;
int prepare(int n){
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
            nthprime[ith]=i;
        }
    }
}
int sieve_of_erathos(int nth){

    int ith=0;
    for(int i=2;i<=20000000;++i){

        if(primes[i]==true){
            //cout<<i<<" ";
            ++ith;
        }
        if(ith==nth) return i;
    }
}
int main(){
int n=20000000;
primes =new bool[n+1];
for(int i=0;i<=n;++i) primes[i]=true;
nthprime=new int[n+1];
prepare(n);

int t;
cin>>t;
while(t--){
int nth;
cin>>nth;
cout<<nthprime[nth]<<endl;
}


return 0;}

