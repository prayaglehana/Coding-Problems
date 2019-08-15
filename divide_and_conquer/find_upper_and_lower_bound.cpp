#include<iostream>
using namespace std;

int binSearchUB(int *a,int UB,int key,int s,int e){
    if(s>e) return UB;

int mid=(s+e)/2;

if(a[mid]==key) UB=mid;

if(a[mid]>key) return  binSearchUB(a,UB,key,s,mid-1);
else if(a[mid]<=key) return binSearchUB(a,UB,key,mid+1,e);


}


int binSearchLB(int *a,int LB,int key,int s,int e){
    if(s>e) return LB;

int mid=(s+e)/2;

if(a[mid]==key) LB=mid;

if(a[mid]>=key) return  binSearchLB(a,LB,key,s,mid-1);

else if(a[mid]<key) return binSearchLB(a,LB,key,mid+1,e);


}


int main(){
    int N;
    cin>>N;
    int a[100000];

    for(int i=0;i<N;++i)cin>>a[i];

    int T,key;
    cin>>T;
    while(T--){
        cin>>key;
      cout<<binSearchLB(a,-1,key,0,N-1)<<" "<<binSearchUB(a,-1,key,0,N-1)<<endl;
    }

    return 0;
}
