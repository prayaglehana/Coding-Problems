#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
int n,m,k,s;
char a[101][101];
cin>>n>>m>>k>>s;

for(int i=0;i<n;++i){
    for(int j=0;j<m;++j){
        cin>>a[i][j];
    }
}


for(int i=0;i<n && s>=k;++i){
    for(int j=0;j<m && s>=k;++j){
        if(j!=0)--s;
        if(a[i][j]=='.')s-=2;
        else if(a[i][j]=='*')s+=5;
        else if(a[i][j]=='#') break;

    }
}
if(s<k) cout<<"No"<<endl;
else {
    cout<<"Yes"<<endl;
    cout<<s<<endl;
}

return 0;}
