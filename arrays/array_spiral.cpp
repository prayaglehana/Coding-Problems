#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){

int m,n;
cin>>m>>n;

int a[m][n];

for(int i=0;i<m;++i)
    for(int j=0;j<n;++j)
        cin>>a[i][j];

 int lenD=m;
 int lenR=n;
int x,y;
int count_=0;
 while(count_<m*n){

        for( x=(m-lenD);x<lenD && count_<m*n;++x,++count_)cout<<a[x][m-lenD]<<", ";

        for(y=(n-lenR)+1;y<lenR && count_<m*n;++y,++count_)cout<<a[lenD-1][y]<<", ";

        for( x=(lenD-2);x>=(m-lenD) && count_<m*n;--x,++count_)cout<<a[x][lenR-1]<<", ";

        for( y=(lenR-2);y>(n-lenR) && count_<m*n;--y,++count_)cout<<a[n-lenR][y]<<", ";


        --lenD;
        --lenR;

 }
 cout<<"END";




return 0;}
