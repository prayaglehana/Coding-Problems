#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isSubstr(string s,string dict){
    int i=0,j=0;
    while(true){

        if(dict[j]==s[i]){
            ++i;++j;
            if((dict[j]==' '||dict[j]=='\0')&&s[i]=='\0'){
                return true;
            }
        }
        else{
            while(dict[j]!=' '){
                ++j;
                if(dict[j]=='\0') return false;
            }
            ++j;
            i=0;
        }
    }
    return false;
}
string mySubStr(string s,int i,int j){
        string t="";
        for(int k=i;k<=j;++k){
            t+=s[k];
        }
        return t;
}
void wordBreak(string s,int i ,int N,string output,string dict){
   // cout<<"op "<<output<<"i"<<i<<endl;
   //cout<<" i "<<i<<endl;
    if(i>=(N)) {
        output+=")";
       cout<<output;
        return;


    }

    for(int j=i;j<N;++j){
        if(isSubstr(mySubStr(s,i,j),dict)){
           //cout<<" at i "<<i<<" j "<<j<<mySubStr(s,i,j)<<endl;

              if(output.length()!=0)   {wordBreak(s,j+1,N,output+" "+mySubStr(s,i,j),dict);}
              else  wordBreak(s,j+1,N,output+"("+mySubStr(s,i,j),dict);

        }

    }
    //for(long long int k =0;k<pow(2,26);++k);
}
bool existence(string s,int i ,int N,string dict){
        for(int j=i;j<N;++j){
        if(isSubstr(mySubStr(s,i,j),dict)) return true;
        }

        return false;
}

int main(){

int T;
cin>>T;
while(T--){
    string dict="";
    string s="";
    int ND;
    cin>>ND;
    for(int i=1;i<=ND;++i){
        string d;
        cin>>d;
        if(dict.length()!=0)
            dict=dict+" "+d;
        else
            dict=d;



    }

    cin>>s;
    string output="";


    //cout<<mySubStr(dict,0,1);
    if(existence(s,0,s.length(),dict))
        wordBreak(s,0,s.length(),output,dict);
    else
        cout<<"Empty";
    cout<<endl;

}

return 0;

}
