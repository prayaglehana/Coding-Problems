
#include<bits/stdc++.h>
using namespace std;
/* Link list node */
struct node *reverse (struct node *head, int k);
struct node
{
    int data;
    struct node* next;
}*head;
/* UTILITY FUNCTIONS */
/* Function to push a node */
  void insert()
{
    int n,value;
    cin>>n;
    struct node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            head=(struct node *) malloc( sizeof(struct node) );
            head->data=value;
            head->next=NULL;
            temp=head;
            continue;
        }
        else
        {
            temp->next= (struct node *) malloc( sizeof(struct node) );
            temp=temp->next;
            temp->data=value;
            temp->next=NULL;
        }
    }
}
/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
 printf("\n");
}
/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */
    int t,k,value,n;
     cin>>t;
     while(t--)
     {
     insert();
     cin>>k;
     head = reverse(head, k);
     printList(head);
     }
     return(0);
}


/*This is a function problem.You only need to complete the function given below*/
/*
  Reverse a linked list
  The input list will have at least one element
  Return the node which points to the head of the new LinkedList
  Node is defined as
  struct node
  {
     int data;
     struct Node *next;
  }
*/

class PAIR{
    public:
       node *head;
       node *tail;
       node *next;

       PAIR(node *h,node *t,node *n){
           head=h;
           tail=t;
           next=n;
       }
};
PAIR reverseLL(node *h,int k){
    node *tail=h;

    node *prev=NULL;
    node *cur=h;


    for(int i=1;i<=k && cur!=NULL;++i){

        node *next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;

    }

    PAIR p(prev,tail,cur);//head,tail,next

    return p;
}

struct node *reverse (struct node *head, int k)
{

  if(head==NULL) return NULL;

  PAIR p=reverseLL(head,k);

   node *h=reverse(p.next,k);

   (p.tail)->next=h;



//  for(int i=1;i<=k;++i){
//      cout<<(p.head)->data<<" ";
//      p.head=p.head->next;
//  }
//  cout<<endl;


  return p.head ;
}
