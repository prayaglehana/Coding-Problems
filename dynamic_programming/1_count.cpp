#include<iostream>
#include<bits/stdc++.h>
using namespace std;

map <pair<int,int>,string> dp;
int getMaxOne(string s,int j,int n){
    int max_one=0;
    int cur_one=0;
    for(int i=j;i<n;++i){
        if(s[i]=='1')
            ++cur_one;
        else
            cur_one=0;
        if(max_one<cur_one)
            max_one=cur_one;
    }

    return max_one;

}

string formSubArray(int *a,int i,int k,int n){


    if(dp.find(make_pair(i,k))!=dp.end()) return dp.at(make_pair(i,k));

        int op1=0,op2=0;

        if(i==n){
            dp.insert(make_pair(make_pair(i,k),""));
            return dp.at(make_pair(i,k));
        }

        string s1="",s2="";

        if(k>0 && a[i]==0){

                s1=to_string(1)+formSubArray(a,i+1,k-1,n);
                //cout<<" s "<<s1<<"i"<<i<<"k"<<k<<endl;
                op1=getMaxOne(s1,0,n);
        }

       s2=to_string(a[i])+formSubArray(a,i+1,k,n);
       op2=getMaxOne(s2,0,n);

       //cout<<"i "<<i<<" k "<<k<<" s1 "<<s1<<" op1 "<<op1<<" s2 "<<s2<<" op2 "<<op2<<endl;


        if(op2>=op1)
            dp.insert(make_pair(make_pair(i,k),s2));
        else
            dp.insert(make_pair(make_pair(i,k),s1));


        return dp.at(make_pair(i,k));

}

int main(){

    int n,k;
    cin>>n>>k;
    int *a=new int[n+1];


    for(int i=0;i<n;++i){
        cin>>a[i];

    }



//    reverse(a,a+n);
//    cout<<"life ";
//    for(int i=0;i<n;++i)cout<<a[i]<<" ";
//    cout<<endl;
    string ans=formSubArray(a,0,k,n);



//        for(int i=0;i<n;++i){
//            for(int k=0;k<n;++k)
//                cout<<dp[i][k]<<" ";
//            cout<<endl;
//    }
cout<<getMaxOne(ans,0,n)<<endl;
for(int i=0;i<n;++i)
cout<<ans[i]<<" ";


    return 0;
}
