#include <iostream>
#define ll long long int
using namespace std;



ll mergeCross(ll s1,ll e1,ll s2,ll e2,ll *a){
    ll *temp=new ll[e2-s1+1];

    ll i=s1,j=s2,k=0;
    ll inverse=0;
    while(i<=e1 && j<=e2){
        if(a[i]<=a[j]) temp[k++]=a[i++];
        else{
            inverse+=(e1-i+1);
            temp[k++]=a[j++];

        }
    }

    while(i<=e1)temp[k++]=a[i++];
    while(j<=e2)temp[k++]=a[j++];

    k=0;
    for(ll i=s1;i<=e2;++i,++k){
        a[i]=temp[k];
    }

    return inverse;


}
ll inversions(ll i,ll j,ll *a){

    if(i>=j) return 0;

    ll mid=(i+j)/2;

    ll left=inversions(i,mid,a);
    ll right=inversions(mid+1,j,a);

    ll cross=mergeCross(i,mid,mid+1,j,a);

    //cout<<" i "<<i<<" j "<<j<<" left "<<left<<" right "<<right<<" cross "<<cross<<endl;

    return left+right+cross;
}
int main() {
    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;
        ll *a=new ll[n];

        for(ll i=0;i<n;++i)cin>>a[i];


        cout<<inversions(0,n-1,a)<<endl;

        //for(ll i=0;i<n;++i)cout<<a[i]<<" ";  cout<<endl;
    }
	return 0;
}
