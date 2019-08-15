#include<iostream.h>
using namespace std;
class Node{
    int data;
    Node *left;
    Node *right;

};

Node *root=NULL;
int main(){
            int a ;
            char ch='y';


            while(ch=='y'){
                        cout<<"enter number ";
                        cin>>num;




            }

}

void creat_new_node(int a){

        Node *new_node;
        new_node->data=a;
        new_node->left=NULL;
        new_ndoe->right=NULL;


            if(root==NULL){
                    root=new_node;
            }
            else{Node *last=NULL;
                        while(true){
                                            if(new_node->a<=last->data){
                                                            if(last->left!=NULL)last=last->left;
                                                            else {
                                                                    last->left=new_node;
                                                                    }
                                                    }
                                            else{
                                                    if(last->right!=NULL)
                                                        last=last->right;
                                                    else {
                                                            last->right=new_node;
                                                            }

                                            }
                        }

            }

}
