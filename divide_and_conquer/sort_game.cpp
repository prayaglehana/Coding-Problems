#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool compare(pair<string,int> a,pair<string,int> b) {
    if(a.second==b.second )
                return a.first<b.first;
   // cout<<"l"<<a.second<<" "<<b.second<<endl;
    return a.second>b.second;

    }
int main(){
    int X,N;
    cin>>X;
    vector< pair<string,int> > persons;

    cin>>N;

    for(int i=0;i<N;++i) {
        string name;
        int sal;
        cin>>name>>sal;
        persons.push_back(make_pair(name,sal));

    }


    sort(persons.begin(),persons.end(),compare);
//    cout<<endl;
//     for(it=persons.begin();it!=persons.end();++it){
//        if(it->second<X) persons.erase(it);
//    }
    for(pair<string,int> p:persons){
        if(p.second>=X)
        cout<<p.first<<" "<<p.second<<endl;
    }



}
