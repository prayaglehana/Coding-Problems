#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll getScore(ll i,ll j,ll &key,ll *csum,vector<pair<ll,ll>> &v){
    if(i>j) return -1;


    ll mid=(i+j)/2;



    if(csum[mid]<key){

        if((key-csum[mid])<=(v[mid].second-v[mid].first+1))
            return (key-csum[mid]+v[mid].first-1);

        return getScore(mid+1,j,key,csum,v);
    }
    else{
        return getScore(i,mid-1,key,csum,v);
    }

}
int main() {
	ll t;
	cin>>t;
	vector <pair<ll,ll>> v;
	v.reserve(100000);
	ll *csum=new ll[100001];

	while(t--){
	    ll n,q;
	    cin>>n>>q;


	    for(ll i=0;i<n;++i){
	        ll s,e;
	        cin>>s>>e;
	        v[i]=make_pair(s,e);
	    }
	     csum[0]=0;
	    for(ll i=1;i<n;++i){
	        csum[i]=csum[i-1]+(v[i-1].second-v[i-1].first+1);
	    }

	    //for(ll i=0;i<n;++i)cout<<csum[i]<<" ";cout<<endl;

	    for(ll i=0;i<q;++i){
	        ll key;
	        cin>>key;
	        cout<<getScore(0,n-1,key,csum,v)<<" ";
	    }
	    cout<<endl;




	}
	return 0;
}
