{
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child and a pointer to
right child */
struct Node
{
	int data;	int take;
	int leave;
	struct Node *left, *right;
};
// A utility function to create a node
struct Node* newNode(int data)
{
	struct Node* temp = (struct Node *) malloc( sizeof(struct Node) );
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
// you are required to complete this function
// function should return the size of the
// Largest Independent set in the tree
int LISS(struct Node *root);
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout<<LISS(root)<<endl;
  }
  return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
// you are required to complete this function
// function should return the size of the
// Largest Independent set in the tree
int LISS(struct Node *root)
{
    if(root->left==NULL && root->right==NULL)
        {root->leave=0;
        root->take=1;
        return  1;}

    LISS(root->left);
    LISS(root->right);

    root->take=0;
    root->leave=0;

    if(root->left!=NULL ) root->take=root->take+root->left->leave;
    if(root->right!=NULL ) root->take=root->take+root->right->leave;

    if(root->left!=NULL ) root->leave=root->leave+max(root->left->leave,root->left->take);
    if(root->right!=NULL ) root->leave=root->leave+max(root->right->leave,root->right->take);


    return max(root->take,root->leave);


}
