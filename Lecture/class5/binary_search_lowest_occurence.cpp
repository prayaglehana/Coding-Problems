#include<iostream>
using namespace std;
int getIndexBS(int* a,int s,int i,int j,int foundAt){

if(i>=j) return foundAt;

int mid=(i+j)/2;


if(a[mid]==s) {foundAt=mid;}

    if(s<=a[mid])
        return getIndexBS(a,s,i,mid-1,foundAt);
    else
        return getIndexBS(a,s,mid+1,j,foundAt);


}
int main(){
int a[]={1,2,2,2,2,2,2,2};
int N=sizeof(a)/sizeof(int);
int s=2;
cout<<"ans "<<getIndexBS(a,s,0,N-1,-1);
return 0;}



