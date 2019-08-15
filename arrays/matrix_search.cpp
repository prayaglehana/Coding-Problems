#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int a[31][101];

bool find_key(int n,int m,int &key){
    int i=0,j=m-1;

    while(j>=0 && i<n){
        if(a[i][j]==key) return true;

        if(a[i][j]>key) --j;
        else if(a[i][j]<key) ++i;
    }
    return false;

}
bool search_key(int s,int e,int &row,int &key){

    if(s>e) return false;
    int mid=(s+e)/2;

    if(a[row][mid]==key) return true;

    if(a[row][mid]>key) return search_key(s,mid-1,row,key);
    if(a[row][mid]<key) return search_key(mid+1,e,row,key);

    return false;
}
int main(){
int n,m;
cin>>n>>m;

for(int i=0;i<n;++i){
    for(int j=0;j<m;++j){
        int x;
        cin>>x;
        a[i][j]=x;
    }
}
int key;
cin>>key;

cout<<find_key(n,m,key)<<endl;



return 0;}
