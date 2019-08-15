#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int getLatest(int *a,int i,int j,int r){
    for(int indx=i;indx<=j;++indx)
                if(a[indx]>=r)
                    return indx;
    return i;
}
void findChildren(int *a,int i,int j){
         //cout<<"i,j"<<i<<j<<endl;
         if(i>j) return;
         if((j-i)<=1) {cout<<a[j]<<" ";return;}

         int right=getLatest(a,i+1,j,a[i]);
         findChildren(a,i+1,right-1);
         findChildren(a,right,j);

}



int main(){
int T;
cin>>T;
while(T--){
    int N;
    stack <int>s;
    cin>>N;
    int x;
    int a[100];
    for(int i=0;i<N;++i) cin>>a[i];
    findChildren(a,0,N-1);cout<<endl;
}


return 0;
}
