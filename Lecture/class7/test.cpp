#include<iostream>
using namespace std;

class Node{
public:
const int data;
Node* next;

Node(int d):data(d),next(NULL){}


};

void insertatstart(Node* &head,int d)
{
    if(head==NULL){ head=new Node(d);
    head->next=NULL;
    return; }
    Node* n=new Node(d);
    n->next=head;
    head=n;
    return;
}

void printll(Node* head){

if(head==NULL){return;}

Node* temp=head;
while(temp!=NULL){

    cout<<temp->data<<" ";
    temp=temp->next;

}
cout<<endl;
}


Node* merge2ll(Node* head1,Node* head2)
{

    if(head1==NULL){return head2;}
    if(head2==NULL){return head1;}
    Node* newhead;
    if(head1->data<=head2->data)
    {
        newhead=head1;
        newhead->next=merge2ll(head1->next,head2);
    }

    if(head2->data<head1->data)
    {
        newhead=head2;
        newhead->next=merge2ll(head1,head2->next);
    }
    return newhead;

}

Node* iterativemerge2ll(Node* head1,Node* head2)
{
Node*    t1=head1;
 Node*   t2=head2;
    Node* newnode=NULL;Node* temp;
    while(t1!=NULL&&t2!=NULL){
        //             cout<<"gg";

        if(newnode==NULL){
        if(t1->data<=t2->data){
         newnode=t1;
          t1=t1->next;
       }
        else{newnode=t2;t2=t2->next;}
        newnode->next=NULL;
        temp=newnode;
                }
    if(t1->data<=t2->data){temp->next=t1;t1=t1->next;}
    else if(t2->data<t1->data){ temp->next=t2; t2=t2->next;}
    temp=temp->next;
    }

    if(t1==NULL){ temp->next=t2; }
    if(t2==NULL){temp->next=t1;}
    return newnode;

}

Node* mid(Node* head)
{

    Node* slow=head;
    Node*fast=head;

    while(fast->next!=NULL&&fast->next->next!=NULL)
    {

        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;

}


Node* mergesort( Node* head)
{

    if(head==NULL||head->next==NULL)
    {
        return head;
    }


    Node* m=mid(head);
  //  cout<<m->data<<endl;
    Node* r=m->next;
    m->next=NULL;
    m=mergesort(head);
    r=mergesort(r);

    return merge2ll(m,r);
}

Node* recurreverse(Node* head )
{
        if( head==NULL||head->next==NULL)
        {
            return head;
        }

        Node* chotahead=recurreverse(head->next);
        Node* tale=head->next;
        tale->next=head;
        head->next=NULL;
        return chotahead;
    }

    Node* mix(Node* head1,Node* head2)
    {
      Node* t1=head1;
      Node* t2=head2;
        Node*newhead=NULL;
        Node* temp;
        int i=1;
        while(t1!=NULL&&t2!=NULL)
        {
            if(newhead==NULL)
            {//cout<<"NULL"<<endl;
                newhead=t1;
                temp=newhead;
                t1=t1->next;

            }

            if(i%2==1){//cout<<i<<" i "<<endl;
                    temp->next=t2;t2=t2->next; }
            else{
               // cout<<i<<" i0 "<<endl;
                temp->next=t1;t1=t1->next;}

        i++;temp=temp->next;
        }

        if(t1!=NULL){temp->next=t1;}
        if(t2!=NULL){temp->next=t2;}
        return newhead;
}



Node* kreverse(Node* head,int k)
{

Node* temp=head;
cout<<head->data<<" head"<<endl;
int c=3;Node* temp2;

while(temp!=NULL)

{    cout<<temp->data<<" afds"<<endl;
     temp2=temp;
     cout<<temp->data<<" temphaha"<<endl;
    for(int i=1;i<k;i++){temp=temp->next;}
    cout<<" 3rd last "<<temp->data<<endl;
    Node* temp1=temp->next;
     temp->next=NULL;
     Node* temp=recurreverse(temp2);
     temp2->next=temp1;
     if(temp2==head){head=temp;}
     temp2=temp2->next;
     temp=temp1;
          cout<<temp->data<<" temp"<<endl;
          if(c==0) break;
          --c;
}
return head;
}



int main()
{
    Node* head=NULL;
    insertatstart(head,23);
    insertatstart(head,18);
    insertatstart(head,9);
    insertatstart(head,4);
    insertatstart(head,2);

  //  printll(head);
Node* head1=NULL;

   insertatstart(head1,33);
    insertatstart(head1,17);
    insertatstart(head1,12);
    insertatstart(head1,5);
    insertatstart(head1,1);
//printll(head1);

//Node* newhead=iterativemerge2ll(head,head1);
    //printll(newhead);

//cout<<mid(newhead)->data<<endl;
Node* head2=NULL;
   insertatstart(head2,12);
   insertatstart(head2,11);
   insertatstart(head2,10);
   insertatstart(head2,9);
   insertatstart(head2,8);
   insertatstart(head2,7);
   insertatstart(head2,6);
   insertatstart(head2,5);
  // insertatstart(head2,4);
   insertatstart(head2,4);
   insertatstart(head2,3);
   insertatstart(head2,2);
   insertatstart(head2,1);
printll(head2);
//head2=mergesort(head2);
//printll(head2);
//Node* m=mid(head2);
//Node* r=m->next;
//m->next=NULL;

//Node* newhead2=recurreverse(r);
//printll(head2);
//printll(newhead2);
//Node* newhead3=mix(head2,newhead2);
//cout<<"mixed"<<endl;
Node* newnode4=kreverse(head2,3);
cout<<"kreverse"<<endl;
printll(newnode4);

}
