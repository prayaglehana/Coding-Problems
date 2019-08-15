#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void getDoublet(int *a,int s,int e,int target,set<pair<int,int>> &myset){
    if(e<=s) return;

    if((a[s]+a[e])==target) {
        myset.insert(make_pair(a[s],a[e]));
        getDoublet(a,s+1,e-1,target,myset);
        return;
    }
    if(a[s]+a[e]>target) getDoublet(a,s,e-1,target,myset);
    if(a[s]+a[e]<target) getDoublet(a,s+1,e,target,myset);


}
void getTriplet(int *a,int n,int &target){
    set<pair<int,int>> myset;
    set<string> output;
    for(int i=n-1;i>=2;--i){
        myset.clear();
        getDoublet(a,0,i-1,target-a[i],myset);


        if(myset.size()>0){
               for(pair<int,int> p: myset){
                    output.insert(to_string(p.first)+to_string(p.second)+to_string(a[i]));
                    //cout<<p.first<<", "<<p.second<<" and "<<a[i]<<endl;
               }

        }
    }

    for(string s:output){
        cout<<s[0]<<", "<<s[1]<<" and "<<s[2]<<endl;
    }


}
int main(){
    int n;
    cin>>n;

    int a[1000];

    for(int i=0;i<n;++i)cin>>a[i];
    int k;
    cin>>k;

    sort(a,a+n);

    getTriplet(a,n,k);

return 0;
}

