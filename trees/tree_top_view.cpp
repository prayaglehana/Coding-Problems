
#include<iostream>
#include<bits/stdc++.h>
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
node * insert_nodes(){
    queue<node*> q;
    int d;
    cin>>d;
    if(d==-1) return NULL;
    node *ROOT= new node(d);
    q.push(ROOT);

    while(!q.empty()){
        node *root=q.front();


        int l,r;
        cin>>l>>r;

        if(l!=-1){
                root->left=new node(l);
                q.push(root->left);
        }
        if(r!=-1){
            root->right=new node(r);
            q.push(root->right);
        }

       q.pop();

    }
    return ROOT;


}

void getorder(node* r,int h,map<int,int > &m){
        if(r==NULL) return ;

        if(m.find(h)==m.end())
           m.insert(make_pair(h,r->data));



        getorder(r->left,h-1,m);
        getorder(r->right,h+1,m);


}
int main(){

    node * root=insert_nodes();
    map<int,int > m;
    getorder(root,0,m);
   // cout<<endl;
    //preorder(root);
    map<int,int> ::iterator it;

    for(it=m.begin();it!=m.end();++it){
        //cout<<it->first<<" : ";
        cout<<it->second<<" ";
        //cout<<endl;
    }


   // preorder(root);

    return 0;
}
