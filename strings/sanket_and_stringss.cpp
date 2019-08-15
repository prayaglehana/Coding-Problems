#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int ai;
    int akused;
    int aki;
    int bi;
    int bkused;
    int bki;
};
int main(){
int k;
node dp[100];
cin>>k;

string s;
cin>>s;


if(s[0]=='a'){
    dp[0].ai=0;
    dp[0].akused=0;
    dp[0].aki=0;

    if(k>0){
        dp[0].bi=0;
        dp[0].bkused=1;
        dp[0].bki=0;
    }
    else{
        dp[0].bi=-1;
        dp[0].bkused=0;
        dp[0].bki=-1;
    }

}
if(s[0]=='b'){
    dp[0].bi=0;
    dp[0].bkused=0;

    if(k>0){
        dp[0].ai=0;
        dp[0].akused=1;
    }
    else{
        dp[0].ai=-1;
        dp[0].akused=0;
    }
}

for(int i=1;i<s.length();++i){
        if(s[i]=='a'){
                if(dp[i-1].ai!=-1) dp[i].ai=dp[i-1].ai;
                else dp[i].ai=i;

                int kused=dp[i-1].bkused;
                if(dp[i-1].bi!=-1 && kused<k){
                    dp[i].bi=dp[i-1].bi;
                    dp[i].bkused=kused+1;
                }
                else{
                    if(k>0){
                        dp[i].bi=-1;
                        dp[i].bkused=0;
                    }

                }
        }
        else{

            if(dp[i-1].bi!=-1) dp[i].bi=dp[i-1].bi;
                else dp[i].bi=i;

                int kused=dp[i-1].akused;
                if(dp[i-1].ai!=-1 && kused<k){
                    dp[i].ai=dp[i-1].ai;
                    dp[i].akused=kused+1;
                }
                else{
                    if(k>0){
                        dp[i].ai=-1;
                        dp[i].akused=0;}
                }
        }
}

for(int i=0;i<s.length();++i){
    cout<<" i "<<i<<" ai "<<dp[i].ai<<" akused "<<dp[i].akused <<" bi "<<dp[i].bi<<" bkused "<<dp[i].bkused<<endl;
}

return 0;}
