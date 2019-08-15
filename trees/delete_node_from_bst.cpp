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

void preorder(node*r){
    if(r==NULL) return ;

    cout<<r->data<<" ";

    preorder(r->left);
    preorder(r->right);

}

node* insertNode(node *r,int d){
    if(r==NULL){
        node *n=new node(d);
        return n;
    }
    if(d<=r->data) r->left= insertNode(r->left,d);
    else r->right= insertNode(r->right,d);
    return r;
}

node *delete_a_node(node* r,int x){
    if(r==NULL) return NULL;

    if(x==r->data){
        if(r->left==NULL && r->right==NULL) {
            delete r;
            return NULL;
        }
        if(r->left==NULL && r->right!=NULL){

            node *t=r->right;
            delete r;
            return t;
        }
        if(r->left!=NULL && r->right==NULL){
            node *t=r->left;
            delete r;
            return t;
        }
        if(r->left!=NULL && r->right!=NULL){

                node *t=r->left;
                while(t->right!=NULL){
                    t=t->right;
                }
                r->data=t->data;

                r->left= delete_a_node(r->left,t->data);
                return r;

        }

    }

    if(x<=r->data) r->left=delete_a_node(r->left,x);
    else r->right= delete_a_node(r->right,x);
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        node *root=NULL;
        for(int i=0;i<N;++i) {
            int d;
            cin>>d;
            root=insertNode(root,d);
        }

        int M;
        cin>>M;
        for(int i=0;i<M;++i) {
            int x;
            cin>>x;
            root=delete_a_node(root,x);
//              preorder(root);
//        cout<<endl;

        }
        preorder(root);
        cout<<endl;
    }



return 0;}
