
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* right;
    Node* left;

    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
void preorderTraversal(Node* root)
{
	if (!root)return;
	cout << root->data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}
Node* constructBst(int arr[], int n);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        Node *root = constructBst(arr, n);
        preorderTraversal(root);
        cout<<endl;
    }
	return 0;
}

/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++


Node *insertNode(Node* r,int x){
    if(r==NULL){
        Node *n=new Node(x);
        return n;
    }
    if(x<=r->data) r->left=insertNode(r->left,x);
    else r->right=insertNode(r->right,x);

    return r;
}

Node* constructBst(int arr[], int n)
{
    Node* root=NULL;
    for(int i=0;i<n;++i){

        root=insertNode(root,arr[i]);
    }

    return root;

    // Code here

}
