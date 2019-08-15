#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
int m,n;
cin>>m>>n;
int a[11][11];

for(int i=0;i<m;++i){
    for(int j=0;j<n;++j){
        cin>>a[i][j];
    }
}
bool flip=false;
for(int j=0;j<n;++j){
    for(int i=0;i<m;++i){
            if(flip) cout<<a[m-i-1][j]<<", ";
            else cout<<a[i][j]<<", ";
    }
     flip=!flip;
}
cout<<" END";

return 0;}
