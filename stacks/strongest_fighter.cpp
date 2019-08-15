#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Pair{
public:
    int value;
    int i;
    Pair(int i,int v){
        this->value=v;
        this->i=i;
    }

};
class mycompare{
public:
    mycompare(){}
    bool operator()(Pair a,Pair b){
        return a.value<b.value;
    }
};
int main(){

int n;
cin>>n;
int *a=new int[n];
priority_queue <Pair,vector<Pair>,mycompare> maxHeap;

for(int i=0;i<n;++i)cin>>a[i];
int k;
cin>>k;
for(int i=0;i<k;++i){
        Pair p(i,a[i]);
        maxHeap.push(p);
}
cout<<maxHeap.top().value<<" ";
for(int i=k;i<n;++i){

    Pair p(i,a[i]);
    maxHeap.push(p);

    while(maxHeap.top().i<=(i-k)){
        maxHeap.pop();
    }
    cout<<maxHeap.top().value<<" ";
}
cout<<endl;

return 0;
}


