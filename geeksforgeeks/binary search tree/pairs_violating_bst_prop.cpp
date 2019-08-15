
//Author- Sajal Agrawal
//sajal.agrawal1997@gmail.com
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int indx,ans;
struct Node{
    int data;
    Node *left,*right;
    Node(int d){
        data=d;
        left=right=NULL;
    }
};
int pairsViolatingBST(Node *root,int n);
void insert(Node *root,int a,int b,char ch);
int main() {
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
		indx=0;
		ans=0;
        Node *root=NULL;
        for(int j=0;j<n;j++){
            int a,b;
            char ch;
            cin>>a>>b>>ch;
            if(root==NULL){
                root=new Node(a);
                switch(ch){
                    case 'L':root->left=new Node(b);
                            break;
                    case 'R':root->right=new Node(b);
                            break;
                }
            }else{
                insert(root,a,b,ch);
            }
        }
		cout<<pairsViolatingBST(root,n)<<" ";
    }
	return 0;
}
void insert(Node *root,int a,int b,char ch){
    if(root==NULL)return;
    if(root->data==a){
        switch(ch){
            case 'L':root->left=new Node(b);
                    break;
            case 'R':root->right=new Node(b);
                    break;
        }
    }else{
        insert(root->left,a,b,ch);
        insert(root->right,a,b,ch);
    }
}


/*This is a function problem.You only need to complete the function given below*/
/* The structure of Node
struct Node{
    int data;
    Node *left,*right;
    Node(int d){
        data=d;
        left=right=NULL;
    }
}; */
/*You are required to complete below method */


void preorder(Node* r){
    if(r==NULL) return ;

    cout<<r->data<<" ";
   preorder(r->left);
   preorder(r->right);
}

int insertElement(int *a,int N,int x){
    int i;

    for (i=N-1; ( i >= 0  && a[i] >x); i--)
       a[i+1] = a[i];

    a[i+1] = x;
    return (N-(i+1));

}

int searchElement(int *in,int s,int e,int key){
    for(int i=s;i<=e;++i){
        if(key==in[i]) return i;
    }
    return -1;
}
int func(Node * root,int *in,int s,int e){


    Pair p;
    if(s>e) return 0;

    int rootIndx=searchElement(root->data,in,s,e);

    int LN=(rootIndx-s);
    int RN=(e-rootIndx);

    vleft=func(root->left,in,s,rootIndx-1);

    vright=func(root->right,in,rootIndx+1,e);

    int vroot=vleft+vright;

    if(LN==0 && RN==0){

        return 0;
    }
    if(LN==0 && RN>0){

        vroot=vroot+insertElement(in,RN,root->data);
        return vroot;

    }
    if(LN>0 && RN==0){

        vroot=vroot+insertElement(in,LN,root->data);
        return vroot;
    }



    int i=0;
    int j=0;
    int k=0;
    int *a=new int[LN+RN+1];


    while(i<pleft.N && j<pright.N){

        if(pleft.in[i]>in[j]){
            vp=vp+(pleft.N-i);
            a[k]=in[j];
            ++j;
        }
        else{
            a[k]=pleft.a[i];
            ++i;
        }
        ++k;
    }

    while(i<pleft.N){
            p.a[k]=pleft.a[i];
            ++i;++k;
    }
    while(j<pright.N){
        p.a[k]=pright.a[j];
        ++j;++k;
    }

    p.violatingPairs=p.violatingPairs+vp+insertElement(p.a,pleft.N+pright.N,root->data);


    return p;
}

int pairsViolatingBST(Node *root,int n){
          /*Your code here */
        preorder(root);
        Pair p=func(root);

        return p.violatingPairs;
}
