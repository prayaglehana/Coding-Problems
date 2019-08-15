#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){
string s1,s2;
cin>>s1>>s2;

string **dp=new string*[1000];
for(int i=0;i<1000;++i){
    dp[i]=new string[1000];
}

bool flag=false;

for(int j=0;j<s1.length();++j){
  if(!flag){
            if(s1[j]==s2[0]) {
                dp[0][j]=(s2[0]);
                flag=true;
            }
            else{
                dp[0][j]="";
            }
    }
  else
    dp[0][j]=s2[0];
}

flag=false;
for(int i=0;i<s2.length();++i){
  if(!flag){
            if(s1[0]==s2[i]) {
                dp[i][0]=(s1[0]);
                flag=true;
            }
            else{
                dp[i][0]="";
            }
    }
  else
    dp[i][0]=s1[0];
}





for(int i=1;i<s2.length();++i){
    for(int j=1;j<s1.length();++j){
        string a=dp[i][j-1];
        string b=dp[i-1][j];

        string ans;

        if(a.length()>b.length()) ans=a;
        else ans=b;
        //if(i==1 && j==1) cout<<"x"<<ans<<endl;

        if(s2[i]==s1[j]){
            string new_str=dp[i-1][j-1]+s1[j];

            if(new_str.length()>ans.length()){
                ans=new_str;
            }
        }
        dp[i][j]=ans;
    }
}

for(int i=0;i<s2.length();++i){
    for(int j=0;j<s1.length();++j){
       // if(i==0 || j==0 ){
   if(dp[i][j].length()!=0)
            cout<<dp[i][j]<<" ";
            else
                cout<<-1;
  //      }
    }
    cout<<endl;
}


cout<<dp[s2.length()-1][s1.length()-1];


return 0;}
