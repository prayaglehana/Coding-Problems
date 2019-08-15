#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int sud[10][10];

bool ispossible(int num,int x,int y,int &n){
    for(int j=0;j<n;++j){
        if(num==sud[x][j]) return false;
    }

    for(int i=0;i<n;++i){
        if(num==sud[i][y]) return false;
    }
    int ox=3*floor(x/3);
    int oy=3*floor(y/3);

    for(int i=ox;i<(ox+3);++i){
        for(int j=oy;j<(oy+3);++j){
            if(num==sud[i][j]) return false;
        }
    }
    return true;

}

bool solveSudoku(int x,int y,int &n){
     //cout<<" x "<<x<<" y "<<y<<endl;
    if(x==n) return true;

    if(sud[x][y]==0){
        for(int num=1;num<=9;++num){
            if(ispossible(num,x,y,n)){
                sud[x][y]=num;
                if(y==n-1 && solveSudoku(x+1,0,n)) return true;
                else if(y!=n-1 && solveSudoku(x,y+1,n)) return true;
            }
        }
        sud[x][y]=0;
    }
    else{
            if(y==n-1 && solveSudoku(x+1,0,n)) return true;
            else if(y!=n-1 && solveSudoku(x,y+1,n)) return true;
    }

    return false;

}
int main(){
int n;
cin>>n;

for(int i=0;i<n;++i){
    for(int j=0;j<n;++j){
        cin>>sud[i][j];
    }
}

if( solveSudoku(0,0,n)){
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cout<<sud[i][j]<<" ";
        }
        cout<<endl;
    }
}


return 0;}
