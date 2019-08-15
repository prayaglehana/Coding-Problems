#include<iostream>
using namespace std;

void mappedStrings(char* input,char* output,int i,int j){

    if(input[i]=='\0'){
        output[j]='\0';
        cout<<output<<endl;
        return;}

    int thisDigit=input[i]-'0';
    char thisChar='A'+thisDigit-1;
    output[j]=thisChar;
    mappedStrings(input,output,i+1,j+1);

    if(input[i+1]!='\0'){
        int secondDigit=input[i+1]-'0';
        secondDigit=thisDigit*10+secondDigit;
        if(secondDigit<=26)
                {
                thisChar=secondDigit+'A'-1;
                output[j]=thisChar;
                mappedStrings(input,output,i+2,j+1);
                }

    }
    return;

}


int main(){
char input[100];
char output[100]="";
cin>>input;

mappedStrings(input,output,0,0);
return 0;}
