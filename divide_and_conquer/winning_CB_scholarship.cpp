#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool checkIfPossible(long long int P,long long int N,long long int M,long long int X,long long int Y){

        long long int total_token=M+(N-P)*Y;
        return ((total_token-(P*X))>=0) ;
}

long long int findMaxMin(long long int maxMin,long long int s,long long int e,long long int N,long long int M,long long int X,long long int Y){

    if(s>e) return maxMin;

    long long int mid=s+((e-s)/2);
    //cout<<"mid"<<mid<<endl;
    //bool check=checkIfPossible(mid,N,M,X,Y);

    if((M+(N-mid)*Y)>=(mid*X)) {maxMin=mid; return  findMaxMin(maxMin,mid+1,e,N,M,X,Y);}

    else return findMaxMin(maxMin,s,mid-1,N,M,X,Y);
}

int main(){
    long long int N,M,X,Y;
    cin>>N>>M>>X>>Y;


    cout<<findMaxMin(0,0,N,N,M,X,Y);

return 0;}
