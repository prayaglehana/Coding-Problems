#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
}

int main(){
int n;
cin>>n;

vector <pair<int,int> > v;
v.reserve(100001);
for(int i=0;i<n;++i){
    int c,r;
    cin>>c>>r;
    v.push_back(make_pair(c-r,c+r));
}

sort(v.begin(),v.end(),compare);

int removed=0;
int pe=v[0].second;

for(int i=1;i<n;++i){
    if(v[i].first>=pe)pe=v[i].second;
    else ++removed;
}
cout<<removed<<endl;

return 0;}
