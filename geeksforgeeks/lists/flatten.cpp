
#include <bits/stdc++.h>
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom ;
};
using namespace std;
void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}
Node* flatten (Node* root);
int main(void) {
	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			temp = (struct Node*)malloc(sizeof(struct Node));
			scanf("%d",&temp->data);
			temp->next=NULL;
			temp->bottom=NULL;
			if(flag){
				head=temp;
				pre=temp;
				flag=0;
				flag1=1;
			}
			else{
				pre->next=temp;
				pre=temp;
				flag1=1;
			}
			for(int j=0;j<m;j++){
				tempB = (struct Node*)malloc(sizeof(struct Node));
				scanf("%d",&tempB->data);
				tempB->next=tempB->bottom=NULL;
				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;
		   /*
		while(fun!=NULL)
            {
                cout<<fun->data<<" ";
                fun2 = fun->bottom;
                fun=fun->next;
                while(fun2){
                cout<<fun2->data<<" ";
                fun2=fun2->bottom;
                }
                cout<<endl;
            }*/
            Node* root = flatten(head);
            printList(root);
            cout<<endl;
	}
	return 0;
}


/*This is a function problem.You only need to complete the function given below*/
/* Node structure  used in the program
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom ;
}; */
/*  Function which returns the  root of
    the flattened linked list. */
Node *flatten(Node *root)
{
  Node *head=root;
  Node *cur=head;
  cout<<endl;
  while(cur!=NULL){
    cout<<cur->data<<" ";
    cur=cur->bottom;
  }

  while(cur!=NULL){
      Node *t=cur;
      cout<<t->data;
      while(cur->bottom!=NULL){
          cur->next=cur->bottom;
          cur=cur->bottom;
      }
      t->bottom=NULL;
      cur->next=t->next;
      cur=t->next;
  }
  return head;
}
