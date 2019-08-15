#include<iostream>
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
class Pair{
public:
    int height;
    bool balanced;
};
Pair checkIfBalanced(node *r){
    Pair proot;

    if(r==NULL){
        proot.balanced=true;
        proot.height=0;
        return proot;
    }

    Pair pleft=checkIfBalanced(r->left);
    Pair pright=checkIfBalanced(r->right);

    proot.height=max(pleft.height,pright.height)+1;
    proot.balanced=false;
    if(pleft.balanced && pright.balanced) proot.balanced=true;

    if(abs(pleft.height-pright.height)>1) proot.balanced=false;
    return proot;



}
int main(){

node *root=buildTree();
//preorder(root);
Pair p=checkIfBalanced(root);
if(p.balanced) cout<<"true";
else cout<<"false";
return 0;
}
