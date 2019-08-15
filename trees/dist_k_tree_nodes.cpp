
#include<bits/stdc++.h>
using namespace std;
// A binary Tree node
struct node
{
    int data;
    struct node *left, *right;
};
int counter=0;
int target=0;
struct node *ptr=NULL;
void printkdistanceNodeDown(node *root, int k);
int printkdistanceNode(node* root, node* target , int k);
// A utility function to create a new binary tree node
node *newnode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 void insert(struct node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->data==n1)
     {
         switch(lr)
         {
          case 'L': root->left=newnode(n2);
                    break;
          case 'R': root->right=newnode(n2);
                    break;
         }
     }
     else
     {
         insert(root->left,n1,n2,lr);
         insert(root->right,n1,n2,lr);
     }
 }
 void Inorder(struct node* root)
{
    if(counter==0)
    {
        cin>>target;
        counter++;
    }
    if(root==NULL)
        return ;
    Inorder(root->left);
    if(root->data==target)
         ptr=root;
    Inorder(root->right);
}
// Driver program to test above functions
int main()
{
    /* Let us construct the tree shown in above diagram */
    int t,k;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    struct node *root=NULL;
    while(n--)
    {
        char lr;
        int n1,n2;
        cin>>n1>>n2;
        cin>>lr;
        if(root==NULL)
        {
            root=newnode(n1);
            switch(lr){
                    case 'L': root->left=newnode(n2);
                    break;
                    case 'R': root->right=newnode(n2);
                    break;
                    }
        }
        else
        {
            insert(root,n1,n2,lr);
        }
    }
    Inorder(root);
    node * target =ptr;
    cin>>k;
    printkdistanceNode(root, target, k);
    cout<<endl;
    counter=0;
    }
    return 0;
}


/*This is a function problem.You only need to complete the function given below*/
/* A binary Tree node
struct node
{
    int data;
    struct node *left, *right;
}; */
void printkdistanceNodeDown(node *root, int k)
{   if(root==NULL or k<0) return ;
    if(k==0) cout<<root->data<<" ";
    printkdistanceNodeDown(root->left,k-1);
    printkdistanceNodeDown(root->right,k-1);

}

void getDown(node* root, node* target , int k){
    if(root==NULL) return ;
    if(root==target)return printkdistanceNodeDown(root,k);
    getDown(root->left,target,k);
    getDown(root->right,target,k);
}
int detD(node *root,node *target, int d){
 if(root==NULL ) return -1;

  if(root==target){
      return d;
  }
  int left=detD(root->left,target,d+1);
  if(left!=-1) return left;
  return detD(root->right,target,d+1);
}
int getUp(node* root, node* target , int k){


  int dleft,dright;

  dleft=detD(root->left,target,0);

  if(dleft!=-1){
      ++dleft;
      if(k==dleft)cout<<root->data<<endl;
      else
       printkdistanceNodeDown(root->right,k-dleft-1);
      return getUp(root->left,target,k);

  }
  dright=detD(root->right,target,0);

  if(dright!=-1){
      ++dright;
      if(k==(dright)) cout<<root->data<<" ";
      else
         printkdistanceNodeDown(root->left,k-dright-1);
      return getUp(root->right,target,k);
  }
  //cout<<"root "<<root->data<<" : "<<dleft-1<<" "<<dright<<endl;


  return -1;


}
int printkdistanceNode(node* root, node* target , int k)
{
    getDown(root,target,k);
    getUp(root,target,k);
    //cout<<detD(root->left,target,0)<<endl;
}
