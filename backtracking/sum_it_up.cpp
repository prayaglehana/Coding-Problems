#include<iostream>
#include<bits/stdc++.h>
using namespace std;
set <string> myset;
void showVector(vector<int> &v){
    for(int x:v)cout<<x<<" ";
    cout<<endl;
}
void findSumCombS(int i,vector<int> v,int *a,int &n,int k){
        //cout<<i<<endl;
        if(i==n){
            if(k==0){
                sort(v.begin(),v.end());
                string str="";
                for(int x:v)str+=to_string(x)+" ";
                str.erase(str.length()-1);
                myset.insert(str);
            }

            return;
        }
        if(a[i]<=k){
                v.push_back(a[i]);
                findSumCombS(i+1,v,a,n,k-a[i]);
                v.pop_back();
        }
        findSumCombS(i+1,v,a,n,k);
}
int main(){
int n;
cin>>n;
int *a=new int[n];

for(int i=0;i<n;++i)cin>>a[i];
int k;
cin>>k;
vector<int> v;
findSumCombS(0,v,a,n,k);

for(string s:myset)cout<<s<<endl;

return 0;}
