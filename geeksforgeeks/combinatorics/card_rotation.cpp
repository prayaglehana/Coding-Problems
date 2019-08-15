#include <bits/stdc++.h>
using namespace std;

int main() {
    queue <pair<int,int>> q;

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map <int,int> mp;

        for(int i=1;i<=n;++i)
            q.push(make_pair(i,-1));

        int x=1;
        while(!q.empty()){
            for(int i=1;i<=x;++i){
                q.push(q.front());
                q.pop();
            }
            pair<int,int> p=q.front();
            mp[p.first]=x++;

            q.pop();
        }

        for(auto it=mp.begin();it!=mp.end();++it ){
            cout<<it->second<<" ";
        }
        cout<<endl;
    }


	//code
	return 0;
}
