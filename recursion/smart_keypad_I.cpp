#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string table[]= { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

void printSmartKeys(char * input,char* output,int i,int j,int N){

        if(i>=N) {output[j]='\0';cout<<output<<endl;return;}

            int indx=int(input[i]-'0');
           // cout<<"indx "<<indx<<endl;





            int x=0;
            while(table[indx][x]!='\0'){
                output[j]=char(table[indx][x++]);
                 printSmartKeys(input,output,i+1,j+1,N);
            }



            return;





}
int main(){

//cout<<table[1][0];
char ip[10]="";
char op[10]="";
cin>>ip;

printSmartKeys(ip,op,0,0,strlen(ip));

return 0;}
