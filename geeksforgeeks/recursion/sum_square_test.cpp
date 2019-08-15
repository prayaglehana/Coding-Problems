#include <bits/stdc++.h>
using namespace std;

bool isPresent(vector<int> v,int key){
    for(int e:v){
        if(e==key) return true;
    }
    return false;
}

void counts(int n,int x,set<vector<int>> &s,vector<int> v){
    if(x<0) return ;
    if(x==0 ){
        sort(v.begin(),v.end());
        s.insert(v);
        return ;
    }






    for(int i=1;pow(i,n)<=(x);++i){
             if(!isPresent(v,i)){
                v.push_back(i);
                counts(n,x-round(pow(i,n)),s,v);
                v.pop_back();
             }
    }
    return ;

}

int main() {
	int t;
	cin>>t;
    set <vector<int>> s;
    vector<int> v;
    for(int i=0;i<=5;++i){
        for(int j=0;j<=1000;++j){
            dp[i][j]=-1;
        }
    }
	while(t--){
	    int n,x;
	    s.clear();
        v.clear();

	    cin>>x>>n;


       counts(n,x,s,v);
//	    for(vector<int> v:s){
//            for(int e:v) cout<<e<<" ";
//            cout<<endl;
//	    }

	}
	return 0;

}
