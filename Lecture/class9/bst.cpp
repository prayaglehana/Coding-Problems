#include<iostream>
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
};
void insertNewNode(Node*&head,int x){
        if(head==NULL){
            head = new Node(x);
        }
        else {
            Node *last=head;
            while(last->next!=NULL){
                last=last->next;

            }
            Node *n=new Node(x);
            last->next=n;

        }

}

void printLL(Node *head){
        while(head!=NULL){
            cout<<head->data<<" ";
            head=head->next;
        }
        cout<<endl;
}

class LLNode{
public :
    int data;
    LLnode *next;
};
Node* insertBST(Node *r,int d){
    if(r==NULL){
        Node *n=new Node(d);
        return n;
    }
    if(d<=r->data)
        r->left=insertBST(r->left,d);
    else
        r->right=insertBST(r->right,d);
    return r;

}
void printTree(Node * r){
    if(r==NULL) return;
    cout<<r->data<<" ";
    printTree(r->left);
    printTree(r->right);
}

bool searchNode(Node *r,int &key){
        if(r==NULL){
            return false;
        }
        if(r->data==key) return true;


        if(key<r->data) return searchNode(r->left,key);
        else return searchNode(r->right,key);
}
getTail(LLNode * h){
    if(h==NULL) return NULL;
    while(h->next!=NULL){
       h=h->next;
    }
    return h;
}

 LLNode* makeLL(Node *r){
      if(r==NULL) return h;
      if(r->left==NULL && r->right ==NULL){
            LLNode * n=new LLNode(r->data);
            tail->next=n;
            tail=n;
            return h;
      }

    LLNode *tail;

    LLNode * leftLL=makeLL(r->left,head,tail);
    tail=getTail(leftLL);
    if(tail==NULL);
        tail->next=
        tail->next=new Node(r->data);

    LLNode * rightLL=makeLL(r->right,head,tail);


}

Node * deleteNode(Node* r,int key){
    if(r==NULL) return NULL;

    if(r->data==key){
        //isko karna hai delet re
            if(r->left==NULL && r->right==NULL){
                delete r;
                return NULL:
            }
            else if(r->right!=NULL && r->left=NULL){
                Node *temp=r->right;
                delete r;
                return temp;
            }
            else if(r->left!=NULL && r->right==NULL){
                 Node *temp=r->left;
                 delete r;
                 return temp;
            }
            else if(r->right!=NULL && r->left!=NULL){
                Node *temp=r->right;
                while(temp->left!=NULL){
                    temp=temp->left;
                }
                r->data=temp->data;
                r->right=deleteNode(r->right,r->data);
                return r;
            }

    }
    if(r->data >key){
            r->left=deleteNode(r->left,key);
            return r;
    }
    else{
        r->right=deleteNode(r->right,key);
        return r;
    }

}

int main(){

int N;
cin>>N;
Node *root=NULL;
for(int i=0;i<N;++i){
    int x;
    cin>>x;
    root=insertBST(root,x);
}

printTree(root);

searchNode();




return 0;}


