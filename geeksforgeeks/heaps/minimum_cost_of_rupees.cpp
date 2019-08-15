#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        priority_queue<long long int,vector<long long int>,greater<long long int>> h;


                for(int i=0;i<n;++i){
                    int x;
                    cin>>x;
                    h.push(x);
                }
                long long int ans=0;
                while(h.size()!=1){
                        //cout<<" top "<<h.top()<<" ";
                        long long int x1=h.top();h.pop();
                        long long int x2=h.top();h.pop();
                        long long sum=x1+x2;
                        ans=ans+sum;
                        h.push(sum);
                    }
                cout<<ans;



        cout<<endl;





    }
}
