#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Fruit{
public:
    string name;
    int price;
//     bool operator()(Fruit f1,Fruit f2){
//    return f1.price<f2.price;}
    Fruit(){
    }

    Fruit(string n,int p){
        name=n;
        price=p;
    }

};
class compare{
public:
    bool operator()(Fruit f1,Fruit f2){
    return f1.price>f2.price;}

};

int main(){

    set<Fruit,compare> s;


    Fruit f1("apple",12);
    Fruit f2("mango",11);
    Fruit f3("pineapple",3);

    s.insert(f1);
    s.insert(f2);
    s.insert(f3);

    for(Fruit e:s){
        cout<<e.name<<" "<<e.price<<endl;
    }
    return 0;
}
