#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){

int n;
cin>>n;
stack<int> s;
int totalCost=0;
while(n--){
        int Q;
        cin>>Q;
        if(Q==2){
            int c;cin>>c;
            s.push(c);
        }
        else{
            if(s.empty()) cout<<"No Code"<<endl;
            else {
                 cout<<s.top()<<endl;
                 s.pop();
            }

        }
}


return 0;}


