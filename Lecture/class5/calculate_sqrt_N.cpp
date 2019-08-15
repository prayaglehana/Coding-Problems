
#include<iostream>
using namespace std;
int getIndexBS(int i,int j,int ans,int N){

if(i>=j) return ans;

int mid=(i+j)/2;

int square=mid*mid;


    if(square<=N){ans=mid;
        return getIndexBS(mid+1,j,ans,N);}
    else
        return getIndexBS(i,mid-1,ans,N);


}
int main(){
int N;
int X;
cin>>X;

cout<<"ans "<<getIndexBS(0,X-1,-1,X);
return 0;}



