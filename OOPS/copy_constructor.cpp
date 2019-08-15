#include<bits/stdc++.h>
using namespace std;

class Car{
public:
    string name;
    int x;
    Car(string n,int x_){
        name=n;
        x=x_;
    }
    Car(Car &a){
        name=a.name;
        x=a.x;
    }
};
int main(){
    Car A("hello",10);


    Car B(A);
    B.name[0]='k';
    cout<<A.name<<endl;
    cout<<B.name<<endl;
return 0;}
