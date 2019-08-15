#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int data){
            this->data=data;
            next=NULL;
    }

}*head=NULL;


void insertNewNode(int x){
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
            cout<<head->data<<"->";
            head=head->next;
        }
}

void deletAt(int P){
    if(P==0){
        Node *t=head;
        head=t->next;
        t->next=NULL;
        delete t;
    }
    else {
        int p=0;
        Node *h=head;
        while(p<P){
            if(h==NULL) return ;
            h=h->next;
            ++p;

        }
        Node *t=h;

    }
}
void reverseLL(Node *h){

   Node * t= h->next;
   if(t==NULL) {head=h;return;}
   reverseLL(t);
   t->next=h;
   h->next=NULL;

}

int countNode(Node *h){
    int count_=0;
    while(h!=NULL){
        ++count_;
        h=h->next;
    }
    return count_;
}

Node * recReverse(Node *h){

    if(h==NULL || h->next ==NULL){

       return h;
    }

Node*  chotahead=recReverse(h->next);
   h->next->next=h;
   h->next=NULL;
   return chotahead;
}
void reverLLIT(Node *h){
    int nodes=countNode(h);
    Node * t=h;
    for(int p=2;p<nodes;++p){
            t->next=t;
            t=t->next;
    }
    head=t;
    h->nex.t=NULL;

}

int main(){
//int *a={1,23,4};
insertNewNode(3);
insertNewNode(4);
insertNewNode(1);
insertNewNode(9);
insertNewNode(2);
printLL(head);
reverseLL(head);
cout<<endl;
printLL(head);
cout<<endl;
cout<<countNode(head)<<" a ";
head=recReverse(head);
cout<<endl;
printLL(head);
cout<<endl;


return 0;}
