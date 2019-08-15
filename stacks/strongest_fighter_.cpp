#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void showQ(deque <int> q){
    cout<<"Que ";
    while(!q.empty()){
            cout<<q.front()<<" ";
            q.pop_front();
    }
    cout<<" end ";
    cout<<endl;
}
void addelement(deque <int> &q,int *a,int s,int e){

        while(!q.empty() && q.front()<s){
            q.pop_front();
        }
        while(!q.empty() && a[q.back()]<a[e]){
            q.pop_back();
        }
        q.push_back(e);

}

int main(){

int n;
cin>>n;
int *a=new int[n];

deque <int> q;

for(int i=0;i<n;++i)cin>>a[i];

int k;
cin>>k;
for(int i=0;i<k;++i){
     addelement(q,a,0,i);
}
//showQ(q);
cout<<a[q.front()]<<" ";
for(int i=k;i<n;++i){
    addelement(q,a,i-k+1,i);
    //showQ(q);
    cout<<a[q.front()]<<" ";
}


return 0;
}


