#include<iostream>
#include<math.h>
#include<bitset>
using namespace std;
int main(){
int MASK=(1<<8)-1;
int M=21,N=32;
cout<< "M = " << bitset<8>(M) <<endl;
cout<< "N = " << bitset<8>(N) <<endl;
int i=2,j=6;

int R=MASK>>j;
MASK=(MASK<<(j+1))|R;
M=M&MASK;
M=M|N;
cout<< "MASK = " << bitset<8>(MASK) <<endl;
cout<< "NEW M = " << bitset<8>(M) <<endl;
cout<<"ans"<<M;
return 0;}



