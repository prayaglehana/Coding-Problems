#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Car{
    public :
        char* name;
        char* color;
        int price;
    Car(){
        name="hello";
        price=90;

    }
    Car(Car &c){ // shallow copy any  changes may rerflect
        name=c.name;
        color=c.color;
        price=c.price;
    }

    void operator+ (){
            cout<<"hello";
    }

//   Car(Car &c){ // shallow copy any  changes may rerflect
//       int len_name=strlen(c.name);
//       int len_color=strlen(c.color);
//       name=new char[len_name];
//       color=new char[len_color];
//
//       strcpy(name,c.name);
//       strcpy(color,c.color);
//
//        price=c.price;
//    }

   void print(){
   cout<<"kya haal "<<name<<" ! ";
   }

};
//istream jitne b input ke function getline , cin
// ostream output wale saare functions

//cout <<<"abc"<<"def" if not ostream& then abc will be printed on;ly (no cascading possible
ostream & operator<< (ostream &a,Car c){
        c.print();
        return a;
}


int main(){
    Car c1;
    c1.name="marutri";
    c1.price=100;
    c1.color="red";

    Car c2(c1);

    //c1.name[2]='l';
    //cout<<"name :"<<c2.name;

    +c1;
    cout<<"c1 "<<c1<<"hn ";



return 0;}
