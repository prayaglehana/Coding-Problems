#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void subarray(char* s,char* input,char* output,int i,int j){
    if(input[i]=='\0'){
        output[j]=='\0';cout<<output<<endl;
        return ;
    }


    int digit=input[i]-'0';
    output[j]=digit+'A'-1;
    subarray(s,input,output,i+1,j+1);
    if(input[i+1]!='\0'){
        int secondDigit=input[i+1]-'0';
        int no=10*digit+secondDigit;
        if(no<=26){
            output[j]=no+'A'-1;
            subarray(s,input,output,



                     +2,j+1);
        }
    }
    return;






}
int main(){
char s[]="1234";
char input[100];
char output[100];
subarray(s,input,output,0,0);

return 0;

}
