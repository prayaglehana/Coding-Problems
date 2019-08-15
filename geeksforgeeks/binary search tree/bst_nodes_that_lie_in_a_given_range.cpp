#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node* left;
    node * right;
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

node* insert_node_in_bst(node *r,int d){

    if(r==NULL){
        node * n=new node(d);
        return n;
    }
    if(r->data>d) r->left=insert_node_in_bst(r->left,d);
    else r->right=insert_node_in_bst(r->right,d);

    return r;
}
void getNodes(node* r,int L,int R,set <int> &s){
    if(r==NULL) return ;

    if(L<=r->data && r->data<=R)
        s.insert(r->data);


    getNodes(r->left,L,R,s);
    getNodes(r->right,L,R,s);
}
int main(){
        int T;
        cin>>T;
        while(T--){
            int N;
            cin>>N;
            node *root=NULL;
            while(N--){
                int x;
                cin>>x;
                root=insert_node_in_bst(root,x);
            }


            int L,R;
            set<int>s;
            cin>>L>>R;
             cout<<"# Preorder : ";
            preorder(root);
            cout<<endl;


            cout<<"# Nodes within range are : ";
            getNodes(root,L,R,s);
            for(int e:s){
                cout<<e<<" ";
            }
           cout<<endl;

        }


return 0;
}

