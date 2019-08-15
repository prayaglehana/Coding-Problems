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
void recursiveReverse(Node*& head_ref)
{
    struct Node* first;
    struct Node* rest;

    /* empty list */
    if (head_ref == NULL)
       return;

    /* suppose first = {1, 2, 3}, rest = {2, 3} */
    first = head_ref;
    rest  = first->next;

    /* List has only one node */
    if (rest == NULL)
       return;

    /* reverse the rest list and put the first element at the end */
    recursiveReverse(rest);
    first->next->next  = first;

    /* tricky step -- see the diagram */
    first->next  = NULL;

    /* fix the head pointer */
    head_ref = rest;
}

bool checkPalandrome(Node *a,Node *b){
    while(a!=NULL){
            if(a->data!=b->data) return false;
            a=a->next;
            b=b->next;
    }
    return true;
}
int main(){
int N;
cin>>N;
Node *head1=NULL;
for(int i=0;i<N;++i) {
    int x;
    cin>>x;
    insertNewNode(head,x);
    insertNewNode(head1,x);
    }


recursiveReverse(head1);
//printLL(head);
//printLL(head1);
if(checkPalandrome(head,head1))cout<<"True";
else cout<<"False";
return 0;
}
