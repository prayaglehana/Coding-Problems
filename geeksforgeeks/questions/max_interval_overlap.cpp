#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool mycompare(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first) return a.second>b.second;
    return a.first<b.first;
}
int main(){

int t;
cin>>t;
vector<pair<int,int>> v;
while(t--){
    v.clear();
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        v.push_back(make_pair(x,1));
    }

    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        v.push_back(make_pair(x,0));
    }

    sort(v.begin(),v.end(),mycompare);

//    for(int i=0;i<2*n;++i){
//        cout<<v[i].first<<" "<<v[i].second<<endl;
//    }

    int MP=0;
    int TIME=-1;
    int CP=0;

    for(int i=0;i<2*n;++i){
        if(v[i].second){
            ++CP;
        }
        else{
            --CP;
        }
        if(MP<=CP){
            MP=CP;
            TIME=v[i].first;
        }

    }
    cout<<MP<<" "<<TIME<<endl;


}


return 0;}
