#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int board[11][11];
int count_=0;
bool ispossible(int x,int y,int &n){

    for(int i=0;i<x;++i)
        if(board[i][y]) return false;

    for(int i=x,j=y;i>=0&&j>=0;--i,--j)
        if(board[i][j]) return false;

   for(int i=x,j=y;i>=0&&j<n;--i,++j)
        if(board[i][j]) return false;

    return true;
}
void showBoard(int &n){

        for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    cout<<board[i][j]<<" ";
                }
                cout<<endl;
            }
        cout<<endl;
}
void solveQ(int row,int &n){

        if(row==n){
            //showBoard(n);
            ++count_;
            return;

        }
        for(int j=0;j<n;++j){

            if(ispossible(row,j,n)){
                board[row][j]=1;
                solveQ(row+1,n);
                board[row][j]=0;
            }

        }
        return;

}
int main(){


int n;
cin>>n;

for(int i=0;i<n;++i){
    for(int j=0;j<n;++j){
        board[i][j]=0;
    }
}
solveQ(0,n);
cout<<count_<<endl;


return 0;}
