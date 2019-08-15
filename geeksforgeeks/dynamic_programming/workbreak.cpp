#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool check(vector<string> &v,string b){
    for(string s:v){
        if(s==b) return true;
    }
    return false;
}
string getsubstr(string x,int i,int j){
    string temp="";
    for(int q=i;q<=j;++q){
        temp+=x[q];
    }
    return temp;
}
int main(){

int test_cases;
cin>>test_cases;
while(test_cases--){
        vector <string> v;
        int N;
        bool T[1000][1000];
        cin>>N;

        for(int i=0;i<N;++i){
            string s;
            cin>>s;
            v.push_back(s);
        }



        string test;
        cin>>test;
for(int i=0;i<test.length();++i){
    for(int j=0;j<test.length();++j){
        T[i][j]=0;
    }
}

for(int len=test.length();len>0;--len){

        for(int m=0;m<len;++m){
                int x=m;
                int y=m+(test.length()-(len));

                if(x==y){
                    string t="";
                    t=t+(test[x]);
                    if(check(v,t)) T[x][x]=true;
                    else T[x][x]=false;
                }
                else{
                        T[x][y]=false;
                        for(int i=0;i<(y-x);++i){
                            if(T[x][x+i] && T[x+i+1][y])
                                T[x][y]=true;

                        }
                        string t=getsubstr(test,x,y);

                      //  cout<<m<<" "<<len<<" substr "<<x<<" "<<y<<" "<<getsubstr(test,x,y)<<endl;
                       if(check(v,t)) T[x][y]=true;

                }


        }
    }

//    for(int i=0;i<test.length();++i){
//        for(int j=0;j<test.length();++j){
//         cout<<T[i][j]<<" ";
//        }
//        cout<<endl;
//    }
cout<<T[0][test.length()-1]<<endl;
}


return 0;}
