
#include <iostream>
using namespace std;
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
void append(Node** head_ref, Node **tail_ref, int new_data)
{
    Node* newnode = new Node(new_data);

    if(*head_ref == NULL)
        *head_ref = newnode;
    else
        (*tail_ref)->next = newnode;
    *tail_ref = newnode;
}
Node *swapkthnode(Node* head, int num, int K);
void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp){
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}
bool check(Node ** before, Node **after, int num, int K)
{
    if(K > num)
        return 1;
    return (before[K-1] == after[num - K]) && (before[num-K] == after[K-1]);
}
int main()
{
    int T;
    cin>>T;
    while(T--){
        int num, K;
        cin>>num>>K;
        int temp;
        Node* head = NULL;
        Node* tail = NULL;
        for(int i = 0; i<num; i++){
            cin>>temp;
            append(&head, &tail, temp);
        }

        Node *before[num];
        addressstore(before, head);

        head = swapkthnode(head, num, K);

        Node *after[num];
        addressstore(after, head);

        if(check(before, after, num, K))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}


/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/
// Should swap Kth node from beginning and Kth
// node from end in list and return new head.

void printLL(Node *h){
    cout<<" linkedList ";
   while(h!=NULL){
        cout<<h->data<<" ";
        h=h->next;
   }
    cout<<endl;
}
Node *swapkthnode(Node* head, int num, int K)
{


   Node *h=head;
   Node *xh,*yh;

   for(int i=1;i<(K);++i){
       h=h->next;
    }
    xh=h;
    h=head;
    for(int i=1;i<=(num-K);++i){
       h=h->next;
   }
   yh=h;
   cout<<"x "<<xh->data<<" "<<yh->data<<endl;
   int x=xh->data;
   xh->data=yh->data;
   yh->data=x;
   printLL(head);

   return head;
}
