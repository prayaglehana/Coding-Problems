#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main(){

int T;
cin>>T;
while(T--){
    int N;
    cin>>N;
    int a[51],ans[51];

    for(int i=0;i<N;++i) cin>>a[i];

    ans[0]=a[0];

    for(int i=1;i<N;++i){
        int x1,x2,x3;
        x1=ans[i-1]+a[i];
        x2=ans[i-1]-a[i];


        if(abs(x1)<abs(x2)) ans[i]=x1;
        else ans[i]=x2;

    }
    cout<<abs(ans[N-1])<<endl;

}
return 0;}
