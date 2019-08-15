#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void showArray(int *a,int n){
  //  cout<<" number : ";
    for(int i=0;i<n;++i)
        cout<<a[i]<<" ";
    cout<<endl;
}
void showMap(unordered_map<int,int> m){
    cout<<"map : \n";
        for(auto it=m.begin();it!=m.end();++it){
        cout<<it->first<<" : "<<it->second<<endl;
    }

}
int main(){
    int N,K;
    cin>>N>>K;
    unordered_map<int,int> m;
    int *ar=new int[N];
    for(int i=0;i<N;++i){
            int x;
            cin>>x;
            m[x]=i;
            ar[i]=x;
    }

//showMap(m);
    int num=N;
    int i=0;
    while(K>0 && num>0){
        int pos=m[num];
        if(pos!=(i)){
            int idx=m[ar[i]];
            m[ar[i]]=m[num];
            m[num]=idx;
            --K;
            swap(ar[pos],ar[i]);

        }
         //showMap(m);
         //showArray(ar,N);
        --num;
        ++i;


    }
    showArray(ar,N);





    return 0;
}

