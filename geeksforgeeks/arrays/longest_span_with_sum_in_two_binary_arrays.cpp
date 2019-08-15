#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    int a1[100];
    int a2[100];
    int a[100];
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;++i)cin>>a1[i];
        for(int i=0;i<n;++i)cin>>a2[i];

        for(int i=0;i<n;++i)a[i]=a1[i]-a2[i];



        int csum=0;
//        for(int i=0;i<n;++i)cout<<setw(1)<<a[i]<<" ";cout<<endl;
//
//        for(int i=0;i<n;++i){
//                csum+=a[i];
//                cout<<setw(1)<<csum<<" ";
//        }
//        cout<<endl;
        csum=0;

        unordered_map <int,int> mp;

        int max_len=0;
        for(int i=0;i<n;++i){
            csum+=a[i];
            if(csum==0)max_len=max(max_len,i+1);

            else if(mp.find(csum)!=mp.end()){

                 max_len=max(max_len,i-mp[csum]);
                 //cout<<max_len<<" : "<<csum<<" max_len at "<<i<<" "<<mp[csum]<<endl;
            }
            else
            mp.insert(make_pair(csum,i));
        }
//        for(auto it=mp.begin();it!=mp.end();++it){
//            cout<<it->first<<"::"<<it->second<<endl;
//        }

        cout<<max_len<<endl;



    }
	return 0;
}
