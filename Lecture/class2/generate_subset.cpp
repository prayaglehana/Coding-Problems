#include<iostream>
#include<bitset>
#include<cstring>
using namespace std;

void getSubsetMask(char* str,int number){
//cout<<"str"<<str;
for(int i=strlen(str)-1;i>=0;--i){
    if(((number)&(1<<i))){
        cout<<str[strlen(str)-i-1];
    }
}
cout<<" ";

}


int main(){

char str[1000]="";
cin>>str;
for(int i=0;i<=((1<<strlen(str))-1);++i){

        getSubsetMask(str,i);
}
cout<<(1<<strlen(str));
return 0;
}
