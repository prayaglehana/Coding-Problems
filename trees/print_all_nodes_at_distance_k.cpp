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

void formMap(node* r,map<node*,node*> &parent){
    if(r==NULL) return;
    if(r->left!=NULL) parent.insert(make_pair(r->left,r));
    if(r->right!=NULL) parent.insert(make_pair(r->right,r));

    formMap(r->left,parent);
    formMap(r->right,parent);

}
node * searchTree(node *r,int key){
    if(r==NULL) return NULL;
    if(r->data==key) return r;

    node *left=searchTree(r->left,key);
    if(left!=NULL) return left;
    node *right=searchTree(r->right,key);
    if(right!=NULL) return right;

    return NULL;
}

int main(){
int pre[1000],in[1000];
int N;
cin>>N;
for(int i=0;i<N;++i) cin>>pre[i];
for(int i=0;i<N;++i) cin>>in[i];
node * root=buildTree(pre,in,0,N-1);

map<node *,node* > parent;

formMap(root,parent);



int T;
cin>>T;

while(T--){
    int a,key_dist;
    cin>>a>>key_dist;

    node *f=searchTree(root,a);

    queue <node*> q;
    map <node*,bool> taken;
    q.push(f);
    taken.insert(make_pair(f,true));
    q.push(NULL);
    int cur_dist=0;
    bool exist=true;
    while(!q.empty()){

        if(q.front()==NULL){
            ++cur_dist;
            q.pop();


            if(q.front()==NULL) exist=false;

             if(cur_dist==key_dist)
                        break;

            q.push(NULL);
            continue;
        }
        node *r=q.front();
        q.pop();

        if(parent.find(r)!=parent.end() && taken.find(parent.find(r)->second)==taken.end())
            {q.push(parent.find(r)->second);
             taken.insert(make_pair(parent.find(r)->second,true));
            }
        if(r->left!=NULL && taken.find(r->left)==taken.end() ){
            q.push(r->left);
             taken.insert(make_pair(r->left,true));
        }


        if(r->right!=NULL && taken.find(r->right)==taken.end()){
            q.push(r->right);
            taken.insert(make_pair(r->right,true));
        }


    }

    set<int> s;
    while(!q.empty()){
        s.insert(q.front()->data);
       // cout<<q.front()->data<<" ";
        q.pop();

    }
    if(s.size()==0) cout<<0;
    else
        for(int e:s){
            cout<<e <<" ";
        }
    cout<<endl;

}


return 0;}

