#include<iostream>
using namespace std;
int main(){

int *p;
int x=9;
p=&x;
cout<<" p "<<*p<<endl;
delete p;
cout<<" x "<<*p<<endl;



return 0;}
