#include<iostream>
using namespace std;

class Node{
    public:
int data;
Node *right;
Node *left;
}*root;

void bst_insert(int element){
    Node *new_node=new Node;
    new_node->data=element;
    new_node->right=nullptr;
    new_node->left=nullptr;

    Node *temp=new Node();
    temp=root;
    while(true){

        if(element>temp->data){
            if(temp->right!=nullptr)
                temp=temp->right;

            else{

                temp->right=new_node;
                break;
            }
        }
        else{
             if(temp->left!=nullptr)
                temp=temp->left;
            else{
                temp->left=new_node;
                break;
            }
        }
    }

}

void bst_inorder(Node *Root)
{
    if (Root != nullptr)
    {
        bst_inorder(Root->left);
       cout<<Root->data<<" ";
        bst_inorder(Root->right);
    }
}
Node* bst_findMin(Node *current)
{
    if (current->left != nullptr)
    {
            bst_findMin(current->left);
    }
    else
        {return current;}
}


Node* bst_find_this(int element){
    Node*current=new Node();
    current=root;

        while(current!=nullptr&&current->data!=element){
            if(element<=current->data){
            current=current->left;
            }
            else{
                current=current->right;
            }
        }
        return current;


}

void bst_delete(int element){
            Node *d=bst_find_this(element);
            if(d->right==NULL&&d->left==NULL){
                delete(d);
            }
            Node *b=bst_findMin(d->right);

}




int main(){
    root=new Node();
    root->data=5;
    root->right=nullptr;
    root->left=nullptr;

    bst_insert(2);
    bst_insert(-4);
    bst_insert(3);
    bst_insert(18);
    bst_insert(21);
    bst_insert(19);
    bst_insert(25);

         bst_inorder(root);
//
//         Node *t=bst_findMin(root);
//         if(t!=NULL)cout<<t->data;
//
   bst_delete(3);
//
//            t=bst_find_this(19);
//                if(t!=NULL)cout<<"found";
//bst_inorder(root);
         return 0;

}


