#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void showQ(queue <int> calling){
    cout<<"queue ";
    while(!calling.empty()){
        cout<<calling.front()<<" ";
        calling.pop();
    }
    cout<<endl;
}

int main(){

int n;
cin>>n;
queue <int> calling;
queue <int> ideal;


for(int i=0;i<n;++i) {int x;cin>>x;calling.push(x);}
for(int i=0;i<n;++i) {int x;cin>>x;ideal.push(x);}

int cost=0;
while(!ideal.empty()){
    while(calling.front()!=ideal.front()){
        int f=calling.front();
        calling.pop();
        calling.push(f);
        ++cost;
    }
    //showQ(calling);
    ++cost;
    ideal.pop();
    calling.pop();



}
cout<<cost;

return 0;}
