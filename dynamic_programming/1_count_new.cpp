#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int getMaxLen(int l,int r,int k,int *a,int n){

    int max_l=-1,max_r=-1;
    int max_len=0;
    int total_zeroes=0;

    while(l<=r && r<n){


             while(total_zeroes<=k && r<n){

                    if(a[r]==0) ++total_zeroes;
                    ++r;
                    cout<<" r: "<<r<<" tz "<<total_zeroes<<" k "<<k<<endl;
                }
            if(total_zeroes>k )--r;


            if((r-l)>max_len){
                max_l=l;
                max_r=r-1;
                max_len=r-l;
                cout<<" l "<<max_l<<" r "<<max_r<<"total_zeroes"<<total_zeroes<<"n"<<n<<endl;

            }

            while(total_zeroes>k && l<=r)  {
                    if(a[l]==0) --total_zeroes;
                    ++l;

            }


    }

    for(int i=max_l;i<=max_r;++i){
        a[i]=1;
    }
    return max_len;

}
int main(){
    int n,k;
    cin>>n>>k;
    int *a=new int[n+1];


    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    cout<<getMaxLen(0,0,k,a,n)<<endl;

    for(int i=0;i<n;++i){
        cout<<a[i]<<" ";
    }




return 0;}
