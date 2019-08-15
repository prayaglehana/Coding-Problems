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

class Pair{
public:
    int min_;
    int max_;
    int LBST;
    bool isWhole;
    Pair(){
        min_=0;
        max_=0;
        LBST=0;
        isWhole=false;
    }
};

Pair largestBST(node *r){
    Pair p;

    if(r->left==NULL && r->right==NULL){
        p.max_=r->data;
        p.min_=r->data;
        p.LBST=1;
        p.isWhole=true;
        return p;
    }
    if(r->left==NULL && r->right!=NULL){
        Pair pright=largestBST(r->right);
        if(r->data<=pright.min_) {
                    p.LBST=1+pright.LBST;
                    p.isWhole=true;}
        else  { p.LBST=pright.LBST;
                p.isWhole=false;}

        p.max_=max(pright.max_,r->data);
        p.min_=min(r->data,pright.min_);

        return p;


    }
    if(r->left!=NULL && r->right==NULL){

        Pair pleft=largestBST(r->left);
        if(r->data>=pleft.max_) {
                    p.LBST=1+pleft.LBST;
                    p.isWhole=true;}
        else  { p.LBST=pleft.LBST;
                p.isWhole=false;}

        p.max_=max(pleft.max_,r->data);
        p.min_=min(r->data,pleft.min_);

        return p;



    }
    Pair pleft=largestBST(r->left);
    Pair pright=largestBST(r->right);


   // cout<<" r->data"<<r->data<<" pleft "<<pleft.max_<<" "<<pright.min_<<" done ";

    if(pleft.isWhole && pright.isWhole && r->data>=pleft.max_ && r->data<=pright.min_){

            p.max_=pright.max_;
            p.min_=pleft.min_;
            p.LBST=1+pleft.LBST+pright.LBST;
            p.isWhole=true;
            return p;
    }
    else{

        p.min_=min(pleft.min_,pright.min_);
        p.max_=max(pleft.max_,pright.max_);
        p.LBST=max(pleft.LBST,pright.LBST);
        p.isWhole=false;
        return p;

    }


}
int search_element(int *in,int key,int s,int e){

 for(int i=s;i<=e;++i) {
    if(key==in[i]) return i;
 }
 return -1;

}
void preorder(node*r){
    if(r==NULL) return ;

    cout<<r->data<<" ";

    preorder(r->left);
    preorder(r->right);

}


node* buildTree(int *pre,int *in,int s,int e){
    static int i=0;

    if(s>e) return NULL;


    int j=search_element(in,pre[i],s,e);

    node *r=new node(pre[i]);
    ++i;

    r->left=buildTree(pre,in,s,j-1);
    r->right=buildTree(pre,in,j+1,e);

    return r;




}

int main(){
int pre[10000],in[10000];
int N;
cin>>N;
for(int i=0;i<N;++i) cin>>pre[i];
for(int i=0;i<N;++i) cin>>in[i];
node * root=buildTree(pre,in,0,N-1);

//preorder(root);
Pair p=largestBST(root);
//cout<<" ans "<<p.min_<<" "<<p.max_<<" "<<p.LBST<<" "<<p.isWhole;
cout<<p.LBST;

return 0;}


