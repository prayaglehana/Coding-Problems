#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string table[]= { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
string searchIn [] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };
bool isSubstring(char* op,string c){
            int opi=0,i=0;
            while(c[i]!='\0'){
                        while(op[opi]!='\0' && op[opi]==c[i] ){ ++opi; ++i; }
                                if(op[opi]=='\0') return true;

                                opi=0;
                                ++i;
                        }
            return false;
}
void printSmartKeys(char * input,char* output,int i,int j,int N){

        if(i>=N) {
                output[j]='\0';
                //cout<<"op : "<<output<<endl;
                for(int q=0;q<11;++q)
                    {if(isSubstring(output,searchIn[q]))
                        cout<<searchIn[q]<<endl;}
                     return;
                }
                //cout<<endl;


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

char opp[10]="tee";
//cout<<"ans; "<<isSubstring(opp,searchIn[0]);

printSmartKeys(ip,op,0,0,strlen(ip));

return 0;}
