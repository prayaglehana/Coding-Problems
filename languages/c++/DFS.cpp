#include<iostream>
#include<stack>
using namespace std;
stack <int>s;
int N=4;
int vis[]={0,0,0,0};
int main(){

 int adj_matrix[][4]={
            {0,1,1,1},
             {1,0,1,0},
             {1,1,0,1},
             {1,0,1,0}
             };
s.push(0);
 while(!s.empty()){
    bool flag=true;

    int cur=s.top();


    for(int i=0;i<N;++i){
        if(adj_matrix[cur][i]&&vis[i]!=1)
            {cout<<i<<" ";s.push(i);flag=false;vis[i]=1;break;
            }
    }
    if(flag)
        s.pop();


 }

}
