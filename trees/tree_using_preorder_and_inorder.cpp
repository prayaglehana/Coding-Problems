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
int search_element(int *in,int key,int s,int e){

 for(int i=s;i<=e;++i) {
    if(key==in[i]) return i;
 }
 return -1;

}
void preorder(node*r){
    if(r==NULL) return ;

    cout<<r->data<<" ";

    preorder(r->left);
    preorder(r->right);

}
void display(node*r){
    if(r==NULL) return ;

    if(r->left==NULL) cout<<"END => ";
    else cout<<r->left->data<<" => ";
     cout<<r->data;
    if(r->right==NULL) cout<<" <= END"<<endl;
    else cout<<" <= "<<r->right->data<<endl;


    display(r->left);
    display(r->right);

}

node* buildTree(int *pre,int *in,int s,int e){
    static int i=0;

    if(s>e) return NULL;


    int j=search_element(in,pre[i],s,e);

    node *r=new node(pre[i]);
    ++i;

    r->left=buildTree(pre,in,s,j-1);
    r->right=buildTree(pre,in,j+1,e);

    return r;




}

int main(){
int pre[100],in[100];
int N,M;
cin>>N;
for(int i=0;i<N;++i) cin>>pre[i];
cin>>M;
for(int i=0;i<M;++i) cin>>in[i];
node * root=buildTree(pre,in,0,N-1);

display(root);


return 0;}

