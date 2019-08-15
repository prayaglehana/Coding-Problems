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

}*head1,*head2;

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
int getIntersection(Node *head1,Node *head2,int N,int M){
    if(N>M){
        int steps=N-M;
        while(steps--){
            head1=head1->next;
        }
    }
    else if(N<M){

        int steps=M-N;
        while(steps--){
            head2=head2->next;
        }
    }

    while(head1!=NULL && head2!=NULL){
        if(head1->data==head2->data) return head1->data;
        head1=head1->next;
        head2=head2->next;
    }
    return -1;
}


int main(){
int N,M;
int x;
    cin>>N;
    int n=N;

    while(n--) {cin>>x; insertNewNode(head1,x);}
    cin>>M;
    int m=M;

    while(m--) {cin>>x;insertNewNode(head2,x);}

//printLL(head1);
//printLL(head2);

cout<<getIntersection(head1,head2,N,M);

return 0;
}
