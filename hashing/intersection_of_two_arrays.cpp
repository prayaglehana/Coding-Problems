#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    map <int,int> m;
    int N;
    cin>>N;
    for(int i=0;i<N;++i){
        int x;
        cin>>x;
        ++m[x];
    }
    vector<int> ans;
    for(int i=0;i<N;++i){
        int x;
        cin>>x;
        if(m.find(x)!=m.end()) {
                --m[x];
            if(m[x]==0) m.erase(x);
            ans.push_back(x);}

    }

    sort(ans.begin(),ans.end());
//    for(auto it=m2.begin();it!=m2.end();++it){
//        cout<<it->first<<" ";
//    }

cout<<"[";
int i=0;
for(;i<(ans.size()-1);++i)cout<<ans[i]<<", ";
cout<<ans[i]<<"]";

cout<<endl;



    return 0;
}

