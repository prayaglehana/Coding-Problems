#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool isPrefix(string a,string b){
    // is prefix of b
    if(a.length()>b.length()) return false;
    for(int i=0;i<a.length();++i){
        if(a[i]!=b[i])
            return false;
    }

    return true;
}
bool compare(string a,string b){
    if(isPrefix(a,b)) {return false;}
    if(isPrefix(b,a)) {return true;}

    return a<b;

}
int main(){
vector <string> s;
int N;
cin>>N;
 string str;
while(N--){

    cin>>str;
    s.push_back(str);
}
sort(s.begin(),s.end(),compare);

for(string x:s){
    cout<<x<<endl;
}
return 0;}
