#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void showStack(stack<int> stck){
    //cout<<"stack: ";
    while(!stck.empty()){cout<<stck.top()<<endl;stck.pop();}
    //cout<<endl;
}
void insertAtBottom(stack <int> &stck,int x){
    if(stck.empty()) {stck.push(x);return;}
    int top=stck.top();
    stck.pop();
    insertAtBottom(stck,x);
    stck.push(top);
}

void reverseStack(stack <int> &stck){
    if(stck.empty()) return;
   int top= stck.top();
   stck.pop();
   reverseStack(stck);
   insertAtBottom(stck,top);
}

int main(){

int n;
cin>>n;
stack<int> stck;
while(n--){
    int x;
    cin>>x;
    stck.push(x);
}
n=stck.size();
reverseStack(stck);
//insertAtBottom(stck,9);
showStack(stck);

return 0;}
