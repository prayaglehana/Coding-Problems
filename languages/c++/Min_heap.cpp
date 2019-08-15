#include<iostream>
using namespace std;

class H{
    public:
int ele[100];
int N;
H(){
N=0;}

void insert_(int data){
    int i=N+1;


    while(ele[i/2]>data&&i!=1){

                        ele[i]=ele[i/2];
                        i=i/2;
                }
        ele[i]=data;
        ++N;
    }
void delete_min(){
    cout<<"deleting "<<ele[1]<<"\n";

            int last_ele=ele[N];
            int i=1;
            while(i<=N){
                if(ele[2*i]<ele[2*i+1])
                    {   ele[i]=ele[2*i];
                        i=2*i;}
                else{ele[i]=ele[2*i+1];
                    i=2*i+1;
                }

            }
            ele[i/2]=last_ele;
        --N;
}
void display(){
cout<<"heap status \n";
for(int i=1;i<=N;++i)
    cout<<ele[i]<<" ";
}

}heap;

int main(){


    heap.insert_(13);
     heap.insert_(14);
    heap.insert_(16);
    heap.insert_(19);
    heap.insert_(21);
    heap.insert_(19);
    heap.insert_(68);
    heap.insert_(65);
    heap.insert_(26);
    heap.insert_(32);
 heap.insert_(31);

    heap.display();

    heap.delete_min();

      heap.display();





}
