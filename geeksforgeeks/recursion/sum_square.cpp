#include <bits/stdc++.h>
using namespace std;
int dp[1001];
bool isPossible(vector<int> v,int key){
    for(int e:v){
        if(key<=e) return false;
    }
    return true;
}

int counts(int n,int x,vector<int> &v){


    if(x<0) return 0;


    if(x==0 ){

        string str="";
        for(int e:v) {
            str+=to_string(e);
            str+=' ';
        }
      // cout<<str<<endl;

        return 1;
    }
    //if(dp[x]!=-1) return dp[x];


    int thisCounts=0;

    for(int i=1;round(pow(i,n))<=(x);++i){
             if(isPossible(v,i) ){
                v.push_back(i);
                thisCounts+=counts(n,x-round(pow(i,n)),v);
                v.pop_back();
            }
    }
    return dp[x]=thisCounts;

}

int main() {
	int t;
	cin>>t;

    vector<int> v;



	while(t--){
	    int n,x;

        v.clear();

	    cin>>x>>n;

        for(int i=0;i<=x;++i) dp[i]=-1;


       cout<<counts(n,x,v)<<endl;


    //      for(int i=1;i<=x;++i)cout<<dp[i]<<" ";



	}
	return 0;

}
