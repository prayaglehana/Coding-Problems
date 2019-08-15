
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool compare(pair<string,pair<int,int>> a,pair<string,pair<int,int>> b){
double d1=sqrt(((a.second).first)*((a.second).first)+((a.second).second)*((a.second).second));
double d2=sqrt(((b.second).first)*((b.second).first)+((b.second).second)*((b.second).second));
return d1<d2;
}
int main(){

vector<pair<string,pair<int,int>>> v;

for(int i=0;i<3;++i){
    string car;
    int x,y;
    cin>>car;
    cin>>x;
    cin>>y;
    v.push_back(make_pair(car,make_pair(x,y)));
}


sort(v.begin(),v.end(),compare);
cout<<endl;

for(pair<string,pair<int,int>> x:v){
    cout<<x.first<<" ";
    cout<<endl;
}
return 0;}
