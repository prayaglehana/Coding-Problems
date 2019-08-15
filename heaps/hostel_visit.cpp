#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long int get_dist(long long int x,long long int y){
        return x*x+y*y;
    }
//class compare{
//public:
//    compare(){}
//    operator () (long long int a,long long int b){
//    return a<b;
//    }
//};

void printHeap( priority_queue<long long int> p){
    while(!p.empty()){
        cout<<p.top()<<" ";
        p.pop();
    }
    cout<<endl;
}

int main(){
        long long int N,K;
        cin>>N;
        cin>>K;
        priority_queue<long long int> p;

        while(N--){
            long long int q;
            cin>>q;

            if(q==1){
                long long int x,y;
                cin>>x>>y;
                long long int cur_dist=get_dist(x,y);
                if(p.size()<K){
                   p.push(cur_dist);
                }

                else if(p.top()>cur_dist){
                    p.pop();
                    p.push(cur_dist);
                }
            }
            else{
              //  prlong long intHeap(p);
              cout<<p.top()<<endl;
            }
            //prlong long intHeap(p);

        }

}
