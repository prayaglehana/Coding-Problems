#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
                int n,k;
                priority_queue<int,vector<int>,greater<int>> h;
                cin>>n>>k;

                while(n--){
                    int x;
                    cin>>x;
                    if(h.size()<k){
                        h.push(x);
                    }
                    else{
                        cout<<h.top()<<" ";
                        h.pop();
                        h.push(x);
                    }
                }

                while(!h.empty()){
                    cout<<h.top()<<" ";
                    h.pop();
                }
                cout<<endl;

    }

return 0;}
