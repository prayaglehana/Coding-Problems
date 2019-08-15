#include<iostream>
#include<cstring>
using namespace std;
void putDot(char* s,int i){
    for(int j=strlen(s);j>=(i);--j)  s[j+1]=s[j];
    s[i+1]='*';
    return;
    }
void func(char* s,int indx){
if(indx>=(strlen(s)-1)) return ;
if(s[indx]==s[indx+1]) {putDot(s,indx);func(s,indx+2);}
else func(s,indx+1);

}
int main(){
char s[1000];
cin>>s;

func(s,0);
cout<<s;
return 0;
}
