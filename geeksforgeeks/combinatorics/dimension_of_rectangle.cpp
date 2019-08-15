#include<bits/stdc++.h>
using namespace std;

int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;

    int ans=0;
    for(int i=1;i<=floor(sqrt(n));++i){

        if((n%i)==0){
            if((n/i)%2!=0 or (i)%2!=0 ){
                  //cout<<i<<" "<<n/i<<endl;
                ++ans;
            }
            else{
                ans+=((i*i)==n);
            }
        }
    }

    cout<<ans<<endl;
}


return 0;}
