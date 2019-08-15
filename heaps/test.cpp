#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class mycompare{
public:
    mycompare(){
    }
    bool operator()(int a,int b){
        return a<b;
    }
};
int main(){
set<int,mycompare> s;
s.insert(1);
s.insert(4);
s.insert(3);

s.erase(s.begin());
for(int x:s)cout<<x<<" ";
return 0;
}
