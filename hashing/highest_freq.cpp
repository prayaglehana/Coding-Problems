#include<iostream>
#include<bits/stdc++.h>
using namespace std;
map <int,int> m;
class D{
public:
    int d;
    int freq;
    D(){
        d=0;
        freq=0;
    }

};
int main(){
int N;
cin>>N;
while(N--){
        int x;
        cin>>x;
        ++m[x];
}
D obj;
for(auto it=m.begin();it!=m.end();++it){

    if(obj.freq<it->second){
        obj.d=it->first;
        obj.freq=it->second;
    }

}
cout<<obj.d<<endl;


return 0;}
