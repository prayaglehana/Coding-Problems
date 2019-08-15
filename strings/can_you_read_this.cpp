#include<bits/stdc++.h>
using namespace std;
int main(){

string s;
cin>>s;

for(int i=0;i<s.length();++i){
    cout<<s[i];
    if(i!=(s.length()-1)&&s[i+1]>='A'&&s[i+1]<='Z') cout<<endl;
}

return 0;}
