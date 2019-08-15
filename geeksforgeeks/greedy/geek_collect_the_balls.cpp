#include<bits/stdc++.h>
using namespace std;

int func(int *a,int *b,int n,int m,bool take){
    unordered_map <int,int> amap;

    for(int i=0;i<n;++i){
        int x;
        x=a[i];
       if(take ){
            if(amap.find(x)==amap.end())amap[x]=i;
       }
        else
            amap[x]=i;
    }

    vector <int> newa;
    vector <int> newb;

//    for(auto it=amap.begin();it!=amap.end();++it){
//        cout<<it->first<<" : "<<it->second<<endl;
//    }


    int i=0,j=0;
    int bsum=0,asum=0;
    while(i<n && j<m){

        if(amap.find(b[j])!=amap.end()){

            asum=0;
            while(i<amap[b[j]]) asum+=a[i++];
            newa.push_back(asum);
            newa.push_back(a[i++]);

            newb.push_back(bsum);
            amap.erase(b[j]);

            newb.push_back(b[j++]);


            bsum=0;

        }
        else bsum+=b[j++];
    }


    asum=0;
    while(i<n) asum+=a[i++];
    newa.push_back(asum);

    while(j<m) bsum+=b[j++];
    newb.push_back(bsum);

    int ans=0;

    for(int i=0;i<newa.size();++i){
        ans+=max(newa[i],newb[i]);
    }


//    for(int e:newa)cout<<e<<" ";cout<<endl;
//    for(int e:newb)cout<<e<<" ";cout<<endl;
//
//    cout<<endl;

    return ans;
}
int main(){

int t;
cin>>t;

while(t--){
    int n,m;
    cin>>n>>m;



    int *a=new int[n];
    int *b=new int[m];



    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        a[i]=x;
     //   if(amap.find(x)==amap.end())
        //amap[x]=i;
    }

    for(int i=0;i<m;++i){
        int x;
        cin>>x;
        b[i]=x;
    }
    cout<<max(func(a,b,n,m,false),func(a,b,n,m,true))<<endl;



}



return 0;
}
