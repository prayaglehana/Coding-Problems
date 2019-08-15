#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int kadanes(int *a,int n){
    int max_sum=INT_MIN;
    int this_sum=0;
    for(int i=0;i<n;++i){
            if((a[i]+this_sum)>0)
                this_sum=a[i]+this_sum;
            else
                this_sum=0;
            max_sum=max(max_sum,this_sum);
    }
    return max_sum;
}
int main(){
int t;
cin>>t;
int *a=new int[100000];
while(t--){
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];

    cout<<kadanes(a,n)<<endl;

}

return 0;}
