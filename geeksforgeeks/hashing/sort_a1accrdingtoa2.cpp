#include <bits/stdc++.h>
using namespace std;


// bool mycompare(int a,int b ){

//     if(!mp[a].first && !mp[b].first) return a<=b;
//     if(mp[a].first && !mp[b].first) return a<=b;
//     if(!mp[a].first && mp[b].first) return b<=a;

//     return mp[a].second<=mp[b].second;
// }
int main() {
int t;
cin>>t;
  unordered_map <int,pair<bool,int> > mp;
while(t--){
    mp.clear();
   vector <int> a1;
   vector <int> a2;

    int n,m;
    cin>>n>>m;



    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        a1.push_back(x);
    }
    for(int i=0;i<m;++i){
        int x;
        cin>>x;
        a2.push_back(x);
        mp.insert(make_pair(x,make_pair(true,i)));
    }
//        cout<<"mp"<<endl;
//    for(auto it=mp.begin();it!=mp.end();++it)cout<<it->first<<" "<<it->second.second<<endl;

    unordered_map <int,int> freq;

    for(int i=0;i<n;++i){
        if(mp[a1[i]].first){
            ++freq[a1[i]];
        }
    }
    vector <int> ans;
    vector <int> temp;
    for(int i=0;i<m;++i){

        if(freq[a2[i]]){
            for(int j=1;j<=freq[a2[i]];++j){
                ans.push_back(a2[i]);
            }
        }
    }


    for(int i=0;i<n;++i){
        if(!mp[a1[i]].first) temp.push_back(a1[i]);
    }

    sort(temp.begin(),temp.end());

     for(int x:temp)ans.push_back(x);
  //  cout<<"freq"<<endl;
 //   for(auto it=freq.begin();it!=freq.end();++it)cout<<it->first<<" "<<it->second<<endl;

   // sort(a1.begin(),a1.end(),mycompare);

    for(int x:ans)cout<<x<<" ";
    cout<<endl;
}
	return 0;
}
