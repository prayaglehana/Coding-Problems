#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int longestSubStr(string &str){
    int n=str.length();
    int max_len=1;
    int this_len=1;
    for(int i=1;i<n;++i){
            if(str[i]==str[i-1]) ++this_len;
            else this_len=1;
            max_len=max(max_len,this_len);
    }
    return max_len;
}

int main(){

int k;
cin>>k;

string str;
cin>>str;

int n=str.length();

if(k==0)
cout<<longestSubStr(str)<<endl;
else{

                int acnt=0;
                int bcnt=0;

                int i=0,j=0;
                int max_len=1;
                while(i<=j &&j<n){

                    if(str[j]=='a' ){
                                               if(min(acnt+1,bcnt)<=k){
                                                          ++acnt;
                                                    }
                                                else{  ++acnt;
                                                        while(i<=j && min(acnt,bcnt)>k){
                                                            if(str[i]=='a'){ ++i;--acnt;}
                                                            else { ++i;--bcnt;}
                                                        }


                                                }
                                       }

                    else if(str[j]=='b' ){

                                               if(min(acnt,bcnt+1)<=k) {
                                                                ++bcnt;

                                                    }
                                              else{ ++bcnt;
                                                    while(i<=j && min(acnt,bcnt)>k){
                                                            if(str[i]=='a'){ ++i;--acnt;}
                                                            else { ++i;--bcnt;}
                                                        }
                //                                    if(i<=j)
                //                                        max_len=max(max_len,j-i+1);
                //                                    ++j;
                //                                    continue;

                                                }
                    }

                 //cout<<"i "<<i<<" j "<<j<<" acnt "<<acnt<<" bcnt "<<bcnt<<endl;
                 if(i<=j)
                     max_len=max(max_len,j-i+1);
                 ++j;




                }
                cout<<max_len<<endl;


}


return 0;}
