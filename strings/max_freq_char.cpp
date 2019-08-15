#include<iostream>
#include<bits/stdc++.h>
using namespace std;

unordered_map<char,int> m;
int main(){
string s;
cin>>s;

for(int i=0;i<s.length();++i){
    m[s[i]]++;
}
//for(auto it=m.begin();it!=m.end();++it){
//    cout<<it->first<<" "<<it->second<<endl;
//}


char max_char='n';
int max_freq=0;
for(auto it=m.begin();it!=m.end();++it)
    if(it->second>max_freq){
        max_freq=it->second;
        max_char=it->first;
    }
cout<<max_char<<endl;


return 0;}
