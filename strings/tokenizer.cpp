#include<bits/stdc++.h>
using namespace std;
int main(){

char str[]="ptrayag is my name";
char *ptr=strtok(str," ");
while(ptr!=NULL){
    cout<<ptr<<endl;
    ptr=strtok(NULL," ");
}
return 0;}
