#include<iostream>
using namespace std;

int binSearch(int *a,int key,int s,int e){
    if(s>e) return -1;

int mid=(s+e)/2;

if(a[mid]==key) return mid;

else if(a[mid]>key) return  binSearch(a,key,s,mid-1);

else if(a[mid]<key) return binSearch(a,key,mid+1,e);


}


int main(){
    int N;
    cin>>N;
    int a[100000];

    for(int i=0;i<N;++i)cin>>a[i];

    int M;
    cin>>M;

    cout<<binSearch(a,M,0,N-1);
    return 0;
}
