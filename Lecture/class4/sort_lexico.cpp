#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool compare(string a,string b){
    if(a.length()==b.length())
            return a<b;
    else
       return a.length()<b.length();
}
int main(){
    vector <string> s;
    int N;
    cin>>N;
    for(int i=0;i<N;++i){
        string str;
        cin>>str;
        s.push_back(str);
    }

    sort(s.begin(),s.end(),compare);
    cout<<endl<<" ans "<<endl;

    for(string str:s){
        cout<<str<<" ";
    }



return 0;}



