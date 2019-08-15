#include<iostream>
using namespace std;

void towerofhanoi(int N,char from,char to,char aux){
if(N==1) {cout<<"Moving ring 1 from "<<from<<" to "<<to<<endl;return;}

    towerofhanoi(N-1,from,aux,to);
    cout<<"Moving ring "<<N<< " from "<<from<< " to "<<to<<endl;
    towerofhanoi(N-1,aux,to,from);

}
int main(){
int N;
cin>>N;
towerofhanoi(N,'A','B','C');
return 0;
}
