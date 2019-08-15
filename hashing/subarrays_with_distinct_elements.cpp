#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int MOD = 1000000007;
int main(){
    int N;
    unordered_map <int,int> m;
    cin>>N;
    int sum_=0;
    long long int cur_len=0;
    for(int i=0;i<N;++i){
        int x;
        cin>>x;
        if(m.find(x)==m.end()) {
                m[x]=i;
                ++cur_len;

        }
        else{
            int prev_indx=m.find(x)->second;
            cur_len=(i-prev_indx);
            m.find(x)->second=i;

        }
        long long int cur_sum=((cur_len)*(cur_len+1)/2)%MOD;
        sum_=(sum_+cur_sum)%MOD;


    }
    cout<<sum_<<endl;
}
