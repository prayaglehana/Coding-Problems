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

Node* insertNewNode(Node*&head,int x){
        if(head==NULL){
            head = new Node(x);
            return head;
        }
        else {
            Node *last=head;
            while(last->next!=NULL){
                last=last->next;

            }
            Node *n=new Node(x);
            last->next=n;
            return last->next;

        }

}


void printLL(Node *head){
        while(head!=NULL){
            cout<<head->data<<" ";
            head=head->next;
        }
        cout<<endl;
}


int main(){

int N;
int n=N;
cin>>n;
while(n--){
    int x;
    cin>>x;
    insertNewNode(head,x);
}

Node * odd=NULL;
Node * even=NULL;
Node * odd_last=NULL;
Node * t=head;
while(t!=NULL){

        if((t->data)&1){
               odd_last= insertNewNode(odd,t->data);
                 //cout<<" t "<<t->data<<endl;
        }
        else{
           insertNewNode(even,t->data);
        }
        t=t->next;

}

odd_last->next=even;
printLL(odd);
return 0;}
