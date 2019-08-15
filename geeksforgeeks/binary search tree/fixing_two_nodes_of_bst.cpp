
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;

    Node(int x){
        int data = x;
        left = right = NULL;
    }
};
void swap( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}
struct Node* NewNode(int data)
{
    struct Node* Node = (struct Node *)malloc(sizeof(struct Node));
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return(Node);
}
struct Node *correctBST( struct Node* root );
void Inorder(struct Node *root){
	if(root==NULL){
		return;
	}
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}
int flag=1;
int c=0;
void inorder(struct Node *temp,struct Node *root){
	if(flag==0){
		return;
	}
	if(temp==NULL&&root==NULL)
		return;
	if(root==NULL){
		flag=0;
		return;
	}
	if(temp==NULL){
		flag=0;
		return;
	}
	if(temp->data==root->data){
	    c++;
	}
	inorder(temp->left,root->left);
	inorder(temp->right,root->right);
}
void insert(struct Node *root,int a1,int a2,char lr){
	if(root==NULL)
		return;
	if(root->data==a1){
		switch(lr){
				case 'L':root->left=NewNode(a2);
				break;
				case 'R':root->right=NewNode(a2);
				break;
			}
	}
	insert(root->left,a1,a2,lr);
	insert(root->right,a1,a2,lr);
}
void preorder(Node *root){
    if(root==NULL) return ;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
	int t;
	cin>>t;
	while(t--){
	struct Node *root=NULL;
	struct Node *temp=NULL;
	int n;
	cin>>n;
	int m=n;
	while(n--){
		int a1,a2;
		char lr;
		cin>>a1>>a2>>lr;
		if(root==NULL){
			temp=NewNode(a1);
			root=NewNode(a1);
			switch(lr){
				case 'L':root->left=NewNode(a2);
				        temp->left=NewNode(a2);
				break;
				case 'R':root->right=NewNode(a2);
				        temp->right=NewNode(a2);
				break;
			}
		}
		else{
			insert(root,a1,a2,lr);
			insert(temp,a1,a2,lr);
		}
	}
	flag=1;
	c=0;

	root=correctBST(root);
	preorder(root);
	inorder(temp,root);
	if(c+1==m){
	    cout<<flag<<endl;
	}
	else{
	    cout<<"0";
	}
	}
    return 0;
}

/*This is a function problem.You only need to complete the function given below*/

/*Complete the function
Node is as follows:
struct Node
{
    int data;
    struct Node *left, *right;

    Node(int x){
        int data = x;
        left = right = NULL;
    }
};
*/

Node* findMin(struct Node* root){

    if(root==NULL) return NULL;

    Node *left=findMin(root->left);
    Node *right=findMin(root->right);


    if(left==NULL && right==NULL) return root;

    if(left==NULL && right!=NULL) {
        if((right->data)>(root->data)) return root;
        else return right;
    }
    if(left!=NULL && right==NULL) {
        if(left->data>root->data) return root;
        else return left;
    }



    if(root->data<left->data && root->data<right->data)
        return root;

    if(left->data<root->data && left->data<right->data)
        return left;

    if(right->data<root->data && right->data<left->data)
        return right;

}
Node* findMax(struct Node* root){

    if(root==NULL) return NULL;

    Node *left=findMax(root->left);
    Node *right=findMax(root->right);


    if(left==NULL && right==NULL) return root;

    if(left==NULL && right!=NULL) {
        if((right->data)<(root->data)) return root;
        else return right;
    }
    if(left!=NULL && right==NULL) {
        if(left->data<root->data) return root;
        else return left;
    }



    if(root->data>left->data && root->data>right->data)
        return root;

    if(left->data>root->data && left->data>right->data)
        return left;

    if(right->data>root->data && right->data>left->data)
        return right;

}
void swapdata(Node *a,Node *b){
     int temp=a->data;
     a->data=b->data;
     b->data=temp;
     return;

}
Node *correctBST( struct Node* root )
{

    if(root==NULL)  return NULL;



    Node * maxleft=findMax(root->left);
    Node * minright=findMin(root->right);

    if(maxleft==NULL && minright==NULL) return root;



    if(maxleft==NULL){
                if(minright->data<root->data){
                    swapdata(root,minright);
                    return root;
                }
            root->right=correctBST(root->right);
            return root;
    }
    if(minright==NULL){
        if(maxleft->data>root->data){
                   swapdata(root,maxleft);
                   return root;
        }
            root->left=correctBST(root->left);
            return root;

    }

  // root and leftsubtree swapped

    if(minright->data>root->data && root->data<maxleft->data){
        swapdata(maxleft,root);
        return root;
    }
// root and rightsubtree swapped
    if(maxleft->data<root->data && root->data >minright->data){
        swapdata(minright,root);
        return root;
    }

    //leftsubtree and rightsubtree nodes swapped
    if(minright->data<maxleft->data ){
            swapdata(maxleft,minright);
            return root;
    }
    root->left=correctBST(root->left);
    root->right=correctBST(root->right);

    return root;
}

