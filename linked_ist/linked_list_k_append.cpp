#include<iostream>
using namespace  std;
class Node{
public:
    int data;
    Node *next;

    Node(int data){
            this->data=data;
            next=NULL;
    }

}*head;

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


Node * getKthNode(Node * h,int K){
    Node * s=h;
    Node * f=h;
    f=f->next;
    while(K--){
        f=f->next;
    }
    while(f!=NULL){
            s=s->next;
            f=f->next;
    }
    return s;
}


int main(){
int N,n;

cin>>N;
n=N;
    while(n--){
        int x;
        cin>>x;
        insertNewNode(head,x);
    }

//printLL(head);
int K;

cin>>K;
K=K%N;
//cout<<" K "<<K<<" N "<<N;

if(K>0 ){
    Node *t=getKthNode(head,K);

    Node * last= t->next;
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=head;
    head=t->next;
    t->next=NULL;

}

printLL(head);
return 0;
}
