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
node* buildTree(int *a,int s,int e){
    if(s>e) return NULL;


    int mid=(s+e)/2;
    node * r=new node(a[mid]);
    r->left=buildTree(a,s,mid-1);
    r->right=buildTree(a,mid+1,e);
    return r;


}
//class Pair{
//public:
//    lsum;
//    rsum;
//    Pair(){
//    lsum=0;
//    rsum=0;
//    }
//};
int getSum(node *r,int csum){
    if(r==NULL) return 0;

    if(r->left==NULL && r->right==NULL){
        int temp=r->data;
        r->data=r->data+csum;
        return temp;
    }

    int rsum=getSum(r->right,csum);
    int lsum=getSum(r->left,csum+rsum+r->data);
    int d=r->data;
    r->data=csum+r->data+rsum;

    return lsum+rsum+d;

}

int main(){
int N;
int a[1001];
cin>>N;
for(int i=0;i<N;++i) cin>>a[i];

node *root=buildTree(a,0,N-1);
//preorder(root);
//cout<<endl;
getSum(root,0);

preorder(root);

return 0;}
