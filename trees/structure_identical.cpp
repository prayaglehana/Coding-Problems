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

bool checkIfIdentical(node *root1,node *root2){
    if(root1==NULL && root2!=NULL)  return false;
    if(root1!=NULL && root2==NULL)  return false;
    if(root1==NULL && root2==NULL)  return true;


    if(!checkIfIdentical(root1->left,root2->left)) return false;
    if(!checkIfIdentical(root1->right,root2->right)) return false;
    return true;
}

int main(){

node *root1=buildTree();
node *root2=buildTree();
//preorder(root1);
//cout<<endl;
//preorder(root2);

if(checkIfIdentical(root1,root2)) cout<<"true";
else cout<<"false";


return 0;}
