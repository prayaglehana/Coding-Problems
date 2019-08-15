#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class node {
public:
    char data;
    map <char,node*> m;
    bool isTerminal;
    node(char d){
        data=d;
        isTerminal=false;
    }

};
class Trie{
public:
    node *root;
    Trie(){
        root=new node('\0');
    }

    void addNewWord(string s){
        node *temp=root;
        for(int i=0;s[i]!='\0';++i){
                char ch=s[i];
                if(temp->m.count(ch)==0){
                    node *child=new node(ch);
                    temp->m[ch]=child;
                    temp=child;
                }
                else{
                    temp=temp->m[ch];
                }
        }
        temp->isTerminal=true;
    }
void loopPrefix(node *r,string s,set<string> &v){
    s=s+r->data;
    if(r->isTerminal) {v.insert(s);}
    for(auto it=r->m.begin();it!=r->m.end();++it){

        loopPrefix(it->second,s,v);
    }
}
void printStringsWithPrefix(string s){
        node *temp=root;
        for(int i=0;s[i]!='\0';++i){
            char ch=s[i];

            if(temp->m.count(ch)){
                temp=temp->m[ch];
            }
            else{
                cout<<"No suggestions"<<endl;
                return ;
            }
        }
        set <string> v;
        s.erase(s.length()-1);


        loopPrefix(temp,s,v);
        if(v.size()!=0)
           {
                for(string str:v){
                cout<<str<<endl;
            }

           }
           else
            cout<<"No suggestions"<<endl;

}

    bool searchString(string word){
        node *temp=root;
        for(int i=0;word[i]!='\0';++i){
            char ch=word[i];

            if(temp->m.count(ch)){
                temp=temp->m[ch];
            }
            else{
                return false;
            }
        }


        return temp->isTerminal;
    }
};
int main(){
int N;
string s;
cin>>N;
Trie trie;
for(int i=0;i<N;++i){

    cin>>s;
    trie.addNewWord(s);
}

int Q;
cin>>Q;
vector<string> q;
for(int i=0;i<Q;++i ){
    cin>>s;
    q.push_back(s);
}
for(string s:q){
    trie.printStringsWithPrefix(s);
}



return 0;}
