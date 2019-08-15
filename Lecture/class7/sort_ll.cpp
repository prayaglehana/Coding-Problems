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
            cout<<head->data<<"->";
            head=head->next;
        }
        cout<<endl;
}

Node* mergeLL(Node *head1,Node *head2){
Node *newHead;
Node * tail;
if(head1->data<head2->data) {newHead=head1;tail=head1;}
else {newHead=head2;tail=head2;}
while(head1!=NULL &&  head2!=NULL){

    if(head1->data<head2->data){
        tail->next=head2;
        tail=head2;
        head1=head1->next;
    }
    else {
        tail->next=head1;
         tail=head1;
         head2=head2->next;
    }

}

return newHead;

}

int main(){
    insertNewNode(head1,1);
    insertNewNode(head1,4);
    insertNewNode(head1,7);
    insertNewNode(head1,8);

    insertNewNode(head2,0);
    insertNewNode(head2,2);
    insertNewNode(head2,10);
    insertNewNode(head2,12);

    printLL(head1);
    printLL(head2);

    head=mergeLL(head1,head2);



    printLL(head);
return 0;
}


