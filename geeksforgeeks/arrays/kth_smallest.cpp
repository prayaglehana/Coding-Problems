#include <bits/stdc++.h>
using namespace std;

int medium(int x,int y,int z,int *a){

    int min_=min(a[x],min(a[y],a[z]));
    int max_=max(a[x],max(a[y],a[z]));

    if(a[x]==min_){
        if(a[y]==max_) return z;
        else return y;
    }
     if(a[y]==min_){
        if(a[x]==max_) return z;
        else return x;
    }
    if(a[z]==min_){
        if(a[x]==max_) return y;
        else return x;
    }


}
int kthelement(int s,int e,int &k,int *a){

    if(s>=e) return a[s];

    int piv_indx=medium(s,e,(s+e)/2,a);
    int pivot=a[piv_indx];

    //cout<<"pivot "<<pivot<<" "<<piv_indx<<" "<<int((s+e)/2)<<endl;
    swap(a[piv_indx],a[e]);


    int i=s,j=e-1;

    while(i<=j){

        while(i<=j && a[i]<=pivot )++i;
        while(i<=j && a[j]>=pivot )--j;


        if(i>j) break;
        swap(a[i],a[j]);
    }

    int p=i;
    swap(a[e],a[p]);

    //for(int i=s;i<=e;++i)cout<<a[i]<<" ";cout<<endl;


    if(p==(k-1)) return a[p];

    if(p>(k-1)) return kthelement(s,p-1,k,a);
    else        return kthelement(p+1,e,k,a);
}
int main() {
    int t;
    cin>>t;
    while(t--){
            int n;
            cin>>n;
            int *a=new int[n];
            for(int i=0;i<n;++i)cin>>a[i];
            int k;

            cin>>k;
            cout<<kthelement(0,n-1,k,a)<<endl;
        }

	return 0;
}
