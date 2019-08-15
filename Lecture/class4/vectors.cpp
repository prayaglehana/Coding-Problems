#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool compare(pair<string,int> a,pair<string,int> b){
return a.second<b.second;
}
int main(){

vector<pair<string,int>> v;

for(int i=0;i<3;++i){
    string fruit;
    int price;
    cin>>fruit;
    cin>>price;
    v.push_back(make_pair(fruit,price));
}


sort(v.begin(),v.end(),compare);
cout<<endl;

for(pair<string,int> x:v){
    cout<<x.first<<" "<<x.second;
    cout<<endl;
}
return 0;}
