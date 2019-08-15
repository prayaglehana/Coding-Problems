#include<iostream>
using namespace std;
void printBracketSequence(char* output,int i,int open,int close,int N){

        if(i==2*N){
                output[i]='\0';
                cout<<"output: "<<output<<endl;
                return ;
        }


if(open<N){
     output[i]='(';
    printBracketSequence(output,i+1,open+1,close,N);}
if(close<open){
             output[i]=')';
             printBracketSequence(output,i+1,open,close+1,N);}


}

int main()
{
char output[200];
int N;
cin>>N;
printBracketSequence(output,0,0,0,N);

    return 0;
}
