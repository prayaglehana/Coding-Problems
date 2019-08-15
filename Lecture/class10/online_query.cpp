#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class compare{
public:
    bool operator()(int a,int b){
    return a<b;
    }
};

void printHeap( priority_queue<int,vector<int>,compare> h){
    while(!h.empty()){
        cout<<h.top()<<" ";
        h.pop();
        cout<<endl;
    }
}

int main(){
    int k;
    cin>>k;
    cout<<" instream "<<endl;
    int x;

    priority_queue<int,vector<int>,compare> a;


    while(true){
        cin>>x;
        if(x==-2) break;

        if(x==-1){
           printHeap(a);
        }
          if(a.size()<(k)){

                a.push(x);

        }

        if(a.top()<x){
            a.pop();
            a.push(x);
        }


