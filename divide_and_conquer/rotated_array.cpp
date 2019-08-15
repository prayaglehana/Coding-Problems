#include<iostream>
using namespace std;

int searchINDX(int *a,int s,int e,int key){
    if(s>e) return -1;
    int mid=(s+e)/2;
    //first line
    if(a[mid]==key) return mid;
    if(a[s]<=a[mid]){
            if(key>=a[s] && key<=a[mid]) return searchINDX(a,s,mid-1,key);
            else return searchINDX(a,mid+1,e,key);
    }
    else {
            if(key<=a[e] && key>=a[mid]) return searchINDX(a,mid+1,e,key);
                    else return   searchINDX(a,s,mid-1,key);
    }

}

int main(){
int N,key;
int a[100000];
cin>>N;


for(int i=0;i<N;++i) cin>>a[i];

cin>>key;

cout<<searchINDX(a,0,N-1,key);

return 0;}
