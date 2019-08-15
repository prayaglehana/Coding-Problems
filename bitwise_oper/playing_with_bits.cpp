#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int Q;
    cin>>Q;
    while(Q--){
        int a,b;
         cin>>a>>b;
         int ans=0;
        for(int P=a;P<=b;++P){
            int x=P;
            while(x>0){
                ans=ans+(x&1);
                 x=x>>1;
            }
        }
        cout<<ans<<endl;
    }

}
