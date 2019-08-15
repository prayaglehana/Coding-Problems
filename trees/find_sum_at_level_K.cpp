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

    int x,y;
    cin>>x>>y;
    node * r=new node(x);

    if(y>0) r->left=buildTree();
    --y;
    if(y>0)  r->right=buildTree();
    return r;

}
void preorder(node*r){
    if(r==NULL) return ;

    cout<<r->data<<" ";

    preorder(r->left);
    preorder(r->right);

}

int sum_at_k_lvl(node *r,int h,int k){

    if(r==NULL) return 0;
    if(h==k) return r->data;

    return sum_at_k_lvl(r->left,h+1,k)+sum_at_k_lvl(r->right,h+1,k);
}

int main(){
node * root=NULL;

root=buildTree();

//preorder(root);

int k;
cin>>k;
cout<<sum_at_k_lvl(root,0,k);
return 0;



}


