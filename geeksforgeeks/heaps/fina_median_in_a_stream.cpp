#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void printMinHeap(priority_queue<int,vector<int>,greater<int>> h){
    cout<<" right wala ";
    while(!h.empty()){
        cout<<h.top()<<" ";
        h.pop();
    }
    cout<<endl;
}
void printMaxHeap(priority_queue<int>  h){
      cout<<" left wala ";
    while(!h.empty()){
        cout<<h.top()<<" ";
        h.pop();
    }
    cout<<endl;
}
int main(){
        int N;
        priority_queue<int> Lmaxheap;
        priority_queue<int,vector<int>,greater<int>> Rminheap;
        int median=-1;
        cin>>N;

        while(N--){
            int x;
            cin>>x;
            int median;

            if(x>median){
                Rminheap.push(x);
                if((Rminheap.size()-Lmaxheap.size())>1){
                        int y=Rminheap.top();
                        Rminheap.pop();
                        Lmaxheap.push(y);
                }

            }
            else{
                 Lmaxheap.push(x);

                 if((Lmaxheap.size()-Rminheap.size())>0){
                        int y=Lmaxheap.top();
                        Lmaxheap.pop();
                        Rminheap.push(y);
                 }


            }

            if(Rminheap.size()==(Lmaxheap.size()+1))
                        median=Rminheap.top();
            else
                        median=(Lmaxheap.top()+Rminheap.top())/2;
           //printMaxHeap(Lmaxheap);
           //printMinHeap(Rminheap);
           cout<<median<<endl;

        }
return 0;
}
