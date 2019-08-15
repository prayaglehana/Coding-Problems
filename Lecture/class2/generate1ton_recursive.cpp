#include<iostream>
using namespace std;
void getNext(int cur,int N){

    cout<<cur<<" ";
    if(cur==N) return ;
    getNext(cur+1,N);

}

int main(){
int N;
cin>>N;
getNext(1,N);
return 0;}
