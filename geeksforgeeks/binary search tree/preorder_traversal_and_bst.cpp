#include <bits/stdc++.h>
using namespace std;

int indx(int s,int e,int *inor,int &key){
    if(s>e) return -1;

    int mid=(s+e)/2;

    if(inor[mid]==key) return mid;

    if(inor[mid]>key) return indx(s,mid-1,inor,key);

    else  return indx(mid+1,e,inor,key);
}

bool checkIfBst(int i,int j,int &p,int &n,int *pre,int *inor){
    if(p>=n or i>j) return true;

    int key=pre[p];
    ++p;

    int id=indx(i,j,inor,key);

    if(id==-1) {

            return false;}
    else{
        return checkIfBst(i,id-1,p,n,pre,inor) && checkIfBst(id+1,j,p,n,pre,inor);
    }

}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int *pre=new int[n];
	    int *inor=new int[n];
	    for(int i=0;i<n;++i){
	       cin>>pre[i];
	       inor[i]=pre[i];
	    }


	    sort(inor,inor+n);

//	    for(int i=0;i<n;++i){
//            cout<<inor[i]<<" ";
//	    }
	    int p=0;
	    cout<< checkIfBst(0,n-1,p,n,pre,inor)<<endl;

	}
	return 0;
}
