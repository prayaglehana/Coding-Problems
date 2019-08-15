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
class Pair{
public:
    int depth;
    int num;
};
void getorder(node* r,int id,int depth, map<int,Pair > &m){
        if(r==NULL) return ;
        Pair p;
        p.num=r->data;
        p.depth=depth;
        if(m.find(id)!=m.end()){
            if((m.find(id)->second).depth<=p.depth){
                    (m.find(id)->second)=p;
            }
        }
        else
          m.insert(make_pair(id,p));




        getorder(r->left,id-1,depth+1,m);
        getorder(r->right,id+1,depth+1,m);


}
int main(){

    node * root=insert_nodes();
    map<int,Pair > m;
    getorder(root,0,0,m);
   // cout<<endl;

    map<int,Pair> ::iterator it;
    for(it=m.begin();it!=m.end();++it){
       // cout<<it->first<<" : ";
        cout<<(it->second).num<<" ";
        //cout<<endl;
    }


   // preorder(root);

    return 0;
}
