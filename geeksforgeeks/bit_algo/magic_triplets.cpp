#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
while(T--){
    int N;
    int a[10000];
    cin>>N;
    for(int i=0;i<N;++i)cin>>a[i];

    int cnt_ar[10000]={0};

    for(int i=0;i<N;++i)
        for(int j=0;j<i;++j){
            if(a[j]<a[i])++cnt_ar[i];
        }
 // for(int i=0;i<N;++i)cout<<cnt_ar[i];cout<<endl;

  int ans[10000]={0};
  int sum=0;
     for(int i=N-1;i>=0;--i)
        for(int j=0;j<i;++j){
            if(a[j]<a[i])ans[i]+=cnt_ar[j];

        }

  //for(int i=0;i<N;++i)cout<<ans[i];
  for(int i=0;i<N;++i)sum+=ans[i];


  cout<<sum<<endl;


}

return 0;}
