#include<iostream>
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
node* buildBlanacedBST(int *a,int s,int e){
    if(s>e) return NULL;
    int mid=(s+e)/2;
    node *n=new node(a[mid]);

    n->left=buildBlanacedBST(a,s,mid-1);
    n->right=buildBlanacedBST(a,mid+1,e);


    return n;
}
int main(){

    int T;
    cin>>T;
    while(T--){
        int N;
        int a[1001];
        cin>>N;
        for(int i=0;i<N;++i){
            cin>>a[i];
        }
        node *root=buildBlanacedBST(a,0,N-1);
        preorder(root);
        cout<<endl;


    }

return 0;}
