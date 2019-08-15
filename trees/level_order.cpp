#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node *right;
    node *left;
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }

};
node* buildTree(){
   int d;
   cin>>d;
   node *r=new node(d);
   string left,right;
   cin>>left;
   if(left=="true")r->left=buildTree();
   cin>>right;
   if(right=="true") r->right=buildTree();

   return r;
}
void preorder(node*r){
    if(r==NULL) return ;

    cout<<r->data<<" ";

    preorder(r->left);
    preorder(r->right);

}
void printLevelZigZag(node *r){
    queue<node *> q;
    stack <int> s;
    q.push(r);
    q.push(NULL);

    bool zigzag=false;

    while(!q.empty()){
        node *r=q.front();

        if(r==NULL){

            q.pop();

            while(!s.empty()) {
                    if(zigzag)cout<<s.top()<<" ";
            s.pop();}
            //cout<<endl;

            zigzag=!zigzag;
            if(q.front()==NULL) break;
            q.push(NULL);
            continue;
        }

        if(!zigzag)
            cout<<r->data<<" ";
        s.push(r->data);
        if(r->left!=NULL) {q.push(r->left);}
        if(r->right!=NULL) {q.push(r->right);}

        q.pop();

    }
}

int main(){
node * root=buildTree();
//preorder(root);
printLevelZigZag(root);
return 0;
}
