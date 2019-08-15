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

}*head1,*head2,*head;

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

Node* mergeSortedLL(Node* head1,Node *head2){
    if(head1==NULL) return head2;
    else if(head2==NULL) return head1;

    if(head1->data<head2->data){
        head1->next=mergeSortedLL(head1->next,head2);
        return head1;
    }
    else{
        head2->next=mergeSortedLL(head1,head2->next);
        return head2;
    }
}

int main(){

int T;
cin>>T;
while(T--){
    head1=NULL;
    head2=NULL;
    head=NULL;
    int N;
    cin>>N;
    while(N--){
        int x;
        cin>>x;
        insertNewNode(head1,x);
    }
    cin>>N;
    while(N--){
        int x;
        cin>>x;
        insertNewNode(head2,x);
    }
    //printLL(head1);
    //printLL(head2);
  head=mergeSortedLL(head1,head2);
  printLL(head);

}

return 0;}


