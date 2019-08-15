#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int x){
            data=x;
            left=NULL;
            right=NULL;
        }
}*root;
void printTree(Node * r){
    if(r==NULL) return;
    cout<<r->data<<" ";
    printTree(r->left);
    printTree(r->right);
}
Node * buildTree(){
    int x;
    cin>>x;
    if(x==-1) return NULL;
    Node *root=new Node(x);
    root->left=buildTree();
    root->right=buildTree();
    return root;

}
class Pair{
public:
    bool isPath;
    vector <stack<int> > v;

};
void findPath(vector <int>&v,Node *r ){
        if(r==NULL) return;
        if(r->left==NULL && r->right==NULL){
            for(int e:v)cout<<e<<"->";
            cout<<r->data;
            cout<<endl;
            return ;
        }
        v.push_back(r->data);
        findPath(v,r->left);
        findPath(v,r->right);
        v.pop_back();



}
vector<int> ::iterator it


int main(){

    Node * root=buildTree();
    printTree(root);
    vector<int> v1;
    findPath(v1,root);
    return 0;
    }
