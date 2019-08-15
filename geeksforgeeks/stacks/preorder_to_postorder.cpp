
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;

    while(t--){
        int n;
        cin>>n;
        int *pre=new int[n];

        for(int i=0;i<n;++i) cin>>pre[i];

        stack<pair<int,int>> s;

        s.push(make_pair(pre[0],INT_MAX));

        for(int i=1; i<n && !s.empty();++i){
            if(pre[i]<=s.top().first){
                s.push(make_pair(pre[i],s.top().first));
            }
            else{
                    while(!s.empty() && (pre[i]>s.top().first && pre[i]>s.top().second )) {
                        cout<<s.top().first<<" ";
                        s.pop();
                    }
                   s.push(make_pair(pre[i],s.top().second));
            }
        }

        while(!s.empty()) {
            cout<<s.top().first<<" "; s.pop();
        }
    }
	return 0;
}
