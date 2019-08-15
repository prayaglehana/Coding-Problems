#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
int t;
cin>>t;
map <char,int> m;
while(t--){
    m.clear();
    int max_freq=0;
    string s;
    cin>>s;
    int cfreq=0;
    for(int i=0;i<s.length();++i){

        if(m.find(s[i])!=m.end()){
            cfreq=m.at(s[i])+1;
            m.find(s[i])->second=cfreq;


        }
        else{
            cfreq=1;
            m.insert(make_pair(s[i],cfreq));

        }
    if(cfreq>max_freq){
                max_freq=cfreq;
            }

    }
   // cout<<"max freq "<<max_freq<<endl;
    int flag=0;
    if(s.length()%2!=0 && max_freq<=((s.length()/2)+1)) flag=1;
    else if(s.length()%2==0 && max_freq<=((s.length()/2))) flag=1;
    cout<<flag<<endl;



}
return 0;}
