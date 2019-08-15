#include<iostream>
#include<bits/stdc++.h>
using namespace std;

map < pair<int,int> ,int > dp;
int a[10000];
void showArray(int *a,int n){
    cout<<" array : ";
    for(int i=1;i<=n;++i) cout<<a[i]<<" ";
    cout<<endl;
}
int calcMaxProfit(int &n,int i,int j){


     if(dp.find(make_pair(i,j))!=dp.end())
        return dp.at(make_pair(i,j));


    if(i<0 || j<0 || i>n || j>n) return 0;

    //cout<<" i "<<i<<" j " <<j<<endl;
    //showArray(a,n);
    if((j-i+1)==2){
        dp.insert(make_pair(make_pair(i,j),max(a[i],a[j]))) ;
        return max(a[i],a[j]);
    }


    if( i==j){
        dp.insert(make_pair(make_pair(i,j),0));
        return 0;
    }


    int op1=a[i]+min(calcMaxProfit(n,i+2,j),calcMaxProfit(n,i+1,j-1));
    int op2=a[j]+min(calcMaxProfit(n,i,j-2),calcMaxProfit(n,i+1,j-1));

    dp.insert(make_pair(make_pair(i,j),max(op1,op2)));
    return max(op1,op2);

}

int main(){

int n;
cin>>n;

//int **dp=new int*[n+1];
//for(int i=0;i<n+1;++i)
//    dp[i]=new int[n+1];
//
//for(int i=1;i<=n;++i){
//    for(int j=1;j<=n;++j){
//        dp[i][j]=-1;
//    }
//}



for(int i=1;i<=n;++i) cin>>a[i];

//showArray(a,n);

cout<<calcMaxProfit(n,1,n);




return 0;}
