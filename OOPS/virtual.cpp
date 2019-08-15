
#include<bits/stdc++.h>
using namespace std;
class A{
public:
    virtual void disp(){
        cout<<"parent"<<endl;
    }
};
class B:public A{
public:
    virtual void disp(){
        cout<<"child"<<endl;
    }
};

class C:public A{
public:
    virtual void disp(){
        cout<<"child2"<<endl;
    }
};

int main(){
A *a=new C();
a->disp();

return 0;}
