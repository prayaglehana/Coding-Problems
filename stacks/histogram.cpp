#include<iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void showStack(stack<ll> s){
    cout<<"Stack ";
    while(!s.empty()){
        cout<<s.top()<<" ";s.pop();
    }
    cout<<endl;
}
int main(){

stack <ll> stck;

ll n;
cin>>n;
ll *h=new ll[n];
for(ll i=0;i<n;++i)cin>>h[i];
ll max_area=0;
ll i=0;
while(i<n){
    //showStack(stck);
    //cout<<"max_are "<<max_area<<"for i "<<i<<endl;
    if(stck.empty() || h[stck.top()]<=h[i]){
        stck.push(i);
         ++i;
    }
    else{
        while(!stck.empty() && h[stck.top()]>h[i]){
            int cur=stck.top();
            stck.pop();
            if(stck.empty())  max_area=max(max_area,h[cur]*i);
            else max_area=max(max_area,h[cur]*(i-stck.top()-1));

        }

    }

}
while(!stck.empty()){
            max_area=max(max_area,h[stck.top()]*(i-stck.top()));
            stck.pop();
        }
cout<<max_area;
return 0;}
