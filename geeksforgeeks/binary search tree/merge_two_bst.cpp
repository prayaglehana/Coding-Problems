
#include<bits/stdc++.h>
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
void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        *tree = new Node(val);
        return;
    }
    if(val < (*tree)->data)
    { insert(&(*tree)->left, val);}
    else if(val > (*tree)->data)
    { insert(&(*tree)->right, val);}
}
void merge(Node *root1,Node *root2);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root1;Node *root2;
        Node *tmp;
        root1 = NULL;
        root2=NULL;
        int N;
        cin>>N;
        int M;
        cin>>M;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root1, k);}
        for(int i=0;i<M;i++)
        {
            int k;
            cin>>k;
            insert(&root2, k);}
       merge(root1,root2);
        cout<<endl;
    }
}

/*This is a function problem.You only need to complete the function given below*/

/* The structure of Node is
struct Node {
    int data;
    Node* right;
    Node* left;

    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};*/
/*You are required to complete below method */
void myinorder(Node *root,int *a,int &i){
    if(root==NULL) return;
     myinorder(root->left,a,i);
     a[i++]=root->data;
     myinorder(root->right,a,i);

}
void merge(Node *root1, Node *root2)
{

        int in1[100],in2[100],m[100];
        int n1=0,n2=0;


         myinorder(root1,in1,n1);
         myinorder(root2,in2,n2);

        int i=0,j=0,k=0;

        while(i<n1&& j<n2){
            if(in1[i]<in2[j]) m[k++]=in1[i++];
            else m[k++]=in2[j++];

        }

        while(i<n1) m[k++]=in1[i++];
        while(j<n2) m[k++]=in2[j++];

        for(int q=0;q<k;++q){
            cout<<m[q]<<" ";
        }

   //Your code here
}
