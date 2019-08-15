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
Node* reverseGetHead(Node *&cur,int K){
    Node *prev=NULL;
    Node *temp=NULL;

    for(int i=0;i<K;++i){
                temp=cur->next;
                cur->next=prev;
                prev=cur;
                cur=temp;
        }
    return prev;
}

Node* LL_K_reverse(Node *h,Node *&cur,int K){

       if(cur==NULL) {return NULL;}
       h=cur;


       Node *this_head=reverseGetHead(cur,K);
      // cout<<"cur "<<cur->data<<" "
       h->next=LL_K_reverse(h,cur,K);


       return this_head;

}


int main(){
int N,K;
cin>>N>>K;


    for(int i=0;i<N;++i){
        int x;
        cin>>x;
        insertNewNode(head,x);
    }
    Node *cur=head;
    //printLL(head);
    head=LL_K_reverse(head,cur,K);
    printLL(head);
    return 0;
}
