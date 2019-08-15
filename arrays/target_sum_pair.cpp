#include<iostream>
#include<bits/stdc++.h>
using namespace std;

unordered_map <int,int> m;
set <pair<int,int>> s;
int main(){
    int n;
    cin>>n;

    int a[1000];

    for(int i=0;i<n;++i)cin>>a[i];

    int k;
    cin>>k;

    for(int i=0;i<n;++i){
            if(m.find(k-a[i])!=m.end()){
                //cout<<min(k-a[i],a[i])<<" and "<<max(k-a[i],a[i])<<endl;
                s.insert(make_pair(min(k-a[i],a[i]),max(k-a[i],a[i])));
            }
            ++m[a[i]];
    }

    for(pair<int,int> p: s){
        cout<<p.first<<" and "<<p.second<<endl;
    }
return 0;
}
