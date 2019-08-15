#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct comparator{
bool operator()(int i,int j){return i>j;}

};
class comapare{
public:
    bool operator()(int a,int b){
    return a<b;}
};
class comapare1{
public:
    bool operator()(student s1,student s2){
    return s1.a<s2.b;}
};

int main(){
    //vector<int> v={20,30,40,25,15};

   //  priotrity_queue<int> h; //maxheap
    //priotrity_queue<int,vector<int>,gretater<int>> h; //minheap
    priotrity_queue<int,vector<int>,compare> h;
    //priotrity_queue<student,vector<student>,compare> h;

    h.push(arr[i]);

    while(!h.em)

    make_heap(v.begin(),v.end(),comparator);
    for(int e:v) cout<<e<<" ";
    return 0;

}
