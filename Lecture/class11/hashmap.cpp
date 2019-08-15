#include<iostream>
#include<bits/stdc++.h>

using namespace std;
template<typename T>
//template<typename T,typename U>
class Node{
public:
    string key;
    T value;
    Node(string k,T v){
        key=k;
        value=v;
        next=NULL;
    }

};
template<typename T>
class Hashtable{
    Node<T> **table;
    int current_size;
    int table_size;
public:
    Hashtable(int ts=7){
        table=new Node<T> * [table_size];
        current_size=0;
        for(int i=0;i<table_size;++i){
            table[i]=NULL;
        }
    }
    int hashFn(string key){
        int idx=0;
        int p=1;
        for(int j=0;j<key.length();++j){     //(((a%m+b)%m)+c)%m;
                idx=(idx+(key[j]*p)%table_size)%table_size;
                p=(p*27)%table_size;
            }
        return idx;
    }
    T& insert_(string key,T value){
        int idx=hashFn(key);
        Node<T> * n= new Node<T> (key,value);
        n->next=table[idx];
        table[idx]=n;
        current_size++;
        float load_factor=(current_size)/1.0*table_size;
        if(load_factor){

        }
        return *f;

    }
    void print(){
        for(int i=0;i<table_size;++i){
          //  cout<<"bucket "<<i<<" : ";
            Node <T> *temp=table[i];
            while(temp!=NULL){
                cout<<temp->key<<"-->";
                temp=temp->next;
            }
        }

    }

};
int main(){
    //Node <int> *n= new Node<int> ;
    Hashtable <int> h;
    h.insert_("Apple",10);
    h.insert_("Mango",20);
    h.insert_("Banana",12);
    h.insert_("Apple",11);
    h.insert_("pineapple",30);

    h.print();

}
