
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
void printLevelK(Node * root,int k){
    if(root==NULL){
        return ;
    }
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    printLevelK(root->left,k-1);
    printLevelK(root->right,k-1);
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
int height(Node * root){
//return root==NULL ?0: 1+max(height(root->left) ,height(root->rigth);
if(root==NULL) return 0;

int h1=height(root->left);
int h2=height(root->right);
return max(h1,h2)+1;
}


int sum_of_nodes(Node *r){
        if(r==NULL) return 0;

        return r->data+sum_of_nodes(r->left)+sum_of_nodes(r->right);
}
int replaceNode(Node *r){
    if(r==NULL) return 0;
    if(r->left==NULL && r->right==NULL) return r->data;

    int temp=r->data;
    r->data=replaceNode(r->left)+replaceNode(r->right)+0;
    return r->data+temp;
}
void printTree(Node * r){
    if(r==NULL) return;
    cout<<r->data<<" ";
    printTree(r->left);
    printTree(r->right);
}
int countNodes(Node *r){
  if(r==NULL ) return 0;

  return 1+countNodes(r->left)+countNodes(r->right);
}

printAllLevels(Node *root){
    queue <Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node * f= q.front();

        if(q.front()==NULL) {
            q.pop();
            cout<<endl;
            if(!q.empty())  q.push(NULL);
        }

        else{
             q.pop();
             cout<<f->data<<" ";
            if(f->left!=NULL) q.push(f->left);
            if(f->right!=NULL) q.push(f->right);

        }



    }
}
int get_diameter(Node* r){
    if(r==NULL) return 0;
    int h1=height(r->left)-1;
    int h2=height(r->right);
    return max(h1+h2,get_diameter(r->left),get_diameter(r->right));
}
class mypair{
public:
    int height;
    bool balanced;
    mypair(){
        height=0;
        balanced=true;
    }
};

mypair isHeightBalanced(Node * r){
    mypair p ;
    p.first=0;
    p.second=true;
    if(r==NULL) { return p;}

    mypair left=isHeightBalanced(r->left);
    mypair right =isHeightBalanced(r->right);




    p.first=max(left.first,right.first)+1;
    p.second =false;
    if(left.second && right.second);
       // p.second=bool(abs(left.first-right.first)<=1);

    return p;


}

//Node* buildTreeFromArray(int *a){
//    queue<Node*> q;
//
//    int N=sizeof(a)/sizeof(int);
//    Node *ROOT= new Node(a[0]);
//    q.push(ROOT);
//    for(int i=1;i<N;){
//
//        Node * root=q.front();
//        q.pop();
//
//        int left_data=a[i];
//        if(left_data!=-1){
//            Node * left =new Node(left_data);
//            root->left=left;
//            q.push(left);
//        }
//
//
//
//        int right_data=a[i+1];
//
//        if(right_data!=-1){
//            Node * right =new Node(right_data);
//            root->right=right;
//            q.push(right);
//        }
//
//
//
//
//        i=i+2;
//
//    }
//    return ROOT;
//}

int main(){
    Node * root=buildTree();
    printTree(root);

    //int a[]={1,2,3,4,-1,5,6};

    //Node *root1=buildTreeFromArray(a);
//    cout<<" prnt tree from array ";
//    printTree(root1);
//
//    cout<<"\n print At Level K:  ";
//    printLevelK(root,3);
//    cout<<endl;
//    printAllLevels(root);
//    cout<<endl<<"Height "<<height(root)<<endl;
//    cout<<"Sum  "<<sum_of_nodes(root)<<endl;
//    cout<<"Total Nodes "<<countNodes(root)<<endl;
//    cout<<"Replaced Nodes "<<replaceNode(root)<<endl;
//
//
//    printTree(root);


    return 0;
}
