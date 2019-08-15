#include<iostream>
#include<bits/stdc++.h>
using namespace std;
map <int,vector<int>> m;
void showVector(vector<int> v){
    cout<<"show vector ";
    for(int x:v)cout<<x<<" ";
    cout<<endl;

}

void buildMap(int *ar,int h,int i,int N){
    if(i>N) return;
    if(ar[i]!=-1){
        vector <int> v;
        if(m.find(h)!=m.end()){
            //cout<<"helo "<<ar[i]<<endl;
            v=m.find(h)->second;
        }


        v.push_back(ar[i]);
        //showVector(v);
        //m.find(h)->second=v;
        m.erase(h);
        m.insert(make_pair(h,v));
    }
    buildMap(ar,h-1,2*i,N);
    buildMap(ar,h+1,2*i+1,N);

    return;
}

int main(){
    int levels;
    cin>>levels;
    int N=(1<<levels)-1;

    int ar[10000];
    for(int i=1;i<=N;++i){
        cin>>ar[i];
    }
    buildMap(ar,0,1,N);


    for(auto it=m.begin();it!=m.end();++it){
           // cout<<it->first<<" : ";

        vector<int> v=it->second;

        for(int x:v)cout<<x<<" ";
    cout<<endl;
    }








return 0;}
