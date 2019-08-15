#include<iostream>
#include<cstring>
using namespace std;
char* replacePI(char* s,int i){
    for(int j=strlen(s);j>=(i+2);--j)  s[j+2]=s[j];
    s[i]='3';
    s[i+1]='.';
    s[i+2]='1';
    s[i+3]='4';
    return s;
    }

void func(char* s,int cur_indx){

    if(s[cur_indx]=='\0')return ;

     if(s[cur_indx]=='p'&&s[cur_indx+1]=='i')  {replacePI(s,cur_indx);func(s,cur_indx+3);}
     else func(s,cur_indx+1);
}



int main(){

int T;
cin>>T;
while(T--){
    char str[100]="";
    cin>>str;
    func(str,0);
    cout<<str<<endl;
}



return 0;}


