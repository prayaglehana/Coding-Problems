#include<iostream>
#include<bits/stdc++.h>
using namespace std;
unordered_map <int,int> freq;

class Pair{
public:
    int data;
    int freq;
    Pair(int d,int f){
        data=d;
        freq=f;
    }
};
class mycompare{
public:
    bool operator()(Pair a,Pair b){
        if(a.freq==b.freq)return a.data>b.data;

        return (a.freq<b.freq);
    }
};
void showHeap(priority_queue<Pair,vector<Pair>,mycompare> hp,int k){
    map <int,int> temp;
    while(!hp.empty() && k--){
        Pair p=hp.top();
        ++temp[p.data];
        if(temp[p.data]==1)
            cout<<p.data<<" ";
        else ++k;
        hp.pop();
    }

}
void showMap(){
    cout<<"heap status "<<endl;
    for(auto it=freq.begin();it!=freq.end();++it){
        cout<<it->first<<" : "<<it->second<<endl;
    }

}

int main(){
int t;
cin>>t;
priority_queue<Pair,vector<Pair>,mycompare> hp;

while(t--){
    freq.clear();
    while(!hp.empty())hp.pop();
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        ++freq[x];
        Pair p(x,freq[x]);
        hp.push(p);
       // showMap();
        showHeap(hp,k);
    }
    cout<<endl;
}
return 0;}
