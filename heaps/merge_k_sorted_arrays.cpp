#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    int i,j;
    node(int d,int i,int j){
        this->data=d;
        this->i=i;
        this->j=j;
    }
};
class mycompare{
public:
   bool operator()(node a,node b){
        return a.data>b.data;
   }
};
int main(){
int N,K;
cin>>K>>N;
int **a=new int*[K];

for(int i=0;i<K;++i){
    a[i]=new int[N];
}

for(int i=0;i<K;++i){
    for(int j=0;j<N;++j){
        long long int x;
        cin>>x;
        a[i][j]=x;
    }

}

priority_queue<node,vector<node>,mycompare> h;
for(int i=0;i<K;++i){
    node n(a[i][0],i,0);
    h.push(n);
}
while(!h.empty()){
    node p=h.top();
    cout<<p.data<<" ";
    h.pop();
    if((p.j+1)<N){
        node n(a[p.i][p.j+1],p.i,p.j+1);
        h.push(n);
    }


}




    return 0;
}
