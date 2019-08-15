#include<iostream>
#include<cstring>
using namespace std;
char* deleteDup(char* s,int i){
    for(int j=i+1;j<strlen(s);++j)  s[j]=s[j+1];
    return s;
    }


void func(char* s,int indx){
if(indx>=(strlen(s)-1)) return ;
while(s[indx]==s[indx+1]) deleteDup(s,indx);
 func(s,indx+1);

}
int main(){
char s[1000];
cin>>s;

func(s,0);
cout<<s;
return 0;
}
