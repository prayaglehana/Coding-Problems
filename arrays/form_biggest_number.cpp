#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool compare(int a,int b){
    string s1=to_string(a);
    string s2=to_string(b);
    return (s1+s2)>(s2+s1);
    //return stoi(s1+s2)>stoi(s2+s1);

}
int main(){

int t;
vector <int> v;
cin>>t;
while(t--){
    int n;
    cin>>n;
    v.clear();
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
       v.push_back(x);
    }
    sort(v.begin(),v.end(),compare);

    for(int i=0;i<n;++i) cout<<v[i];
    cout<<endl;
}


return 0;}
