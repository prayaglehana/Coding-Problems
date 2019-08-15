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

Node * getKthNode(Node * h,int K){
    Node * s=h;
    Node * f=h;
    //f=f->next;
    while(K--){
        f=f->next;
    }
    while(f!=NULL){
            s=s->next;
            f=f->next;
    }
    return s;
}
void printLL(Node *head){
        while(head!=NULL){
            cout<<head->data<<"->";
            head=head->next;
        }
        cout<<endl;
}

int main(){

int x;
cin>>x;
while(x!=-1){
    insertNewNode(head,x);
    cin>>x;
}
int K;
cin>>K;
Node *knode=getKthNode(head,K);
cout<<knode->data<<endl;

return 0;
}
