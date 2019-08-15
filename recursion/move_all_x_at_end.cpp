#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void moveAtEnd(char *a,int N){
    if(a[0]=='\0') return;
    if(a[0]=='x') {
            int x=0;
            while(a[++x]!='\0')swap(a[x],a[x-1]);}
    moveAtEnd(a+1,N-1);

}
int main(){
    char a[1000]="";
      cin>>a;
    int N=strlen(a);

    moveAtEnd(a,N);
    cout<<a;



return 0;}
