#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Fruit{
public:
    string name;
    int price;
//     bool operator()(Fruit f1,Fruit f2){
//    return f1.price<f2.price;}

    Fruit(string n,int p){
        name=n;
        price=p;
    }


};
class compare{
public:
    bool operator()(Fruit f1,Fruit f2){
    return f1.price<f2.price;}

};

int main(){
    //vector<int> v={20,30,40,25,15};

   //  priotrity_queue<int> h; //maxheap
    //priotrity_queue<int,vector<int>,gretater<int>> h; //minheap
    priority_queue<Fruit,vector<Fruit>,Fruit> h;
    //priotrity_queue<student,vector<student>,compare> h;

    Fruit f1("apple",12);
    Fruit f2("mango",11);
    Fruit f3("pineapple",3);

    //priotrity_queue<student,vector<student>, compare> h;

    h.push(f1);
    h.push(f2);
    h.push(f3);

    for(int i=0;i<3;++i){
        Fruit f=h.top();
        cout<<f.name<<" "<<f.price<<endl;
        h.pop();
    }






    return 0;

}

