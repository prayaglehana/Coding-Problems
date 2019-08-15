#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main(){
int T;
  cin>>T;
while(T--){
    int E;
    cin>>E;
    map<int, int> sum;
    map<int, int>::iterator itr;
    map<int,int> parent;

    for(int i=0;i<E;++i){
        int root;
        int x;
        char ch;
        cin>>root;
        cin>>x>>ch;
        if(ch=='L'||ch=='R') {

                        parent.insert(pair<int,int>(x,root));

                        sum.insert(pair<int,int>(root,root));
                        sum.insert(pair<int,int>(x,x));
                        map<int, int>::iterator parent_itr;
                        int p=x;
                        parent_itr=parent.find(x);
                        while(parent_itr!=parent.end()){
                                  itr=sum.find(parent_itr->second);
                                  itr->second=itr->second+x;
                                  p=parent_itr->second;
                                  parent_itr=parent.find(p);
                                }
                }


        }
    int K;
    cin>>K;
     int count_subtrees_sum_K=0;
     for(itr=sum.begin();itr!=sum.end();++itr){
               // cout<<"key: "<<itr->first<<" value "<<itr->second<<endl;
                if(itr->second==K) ++count_subtrees_sum_K;
               }
    cout<<count_subtrees_sum_K<<endl;


    }







return 0;}
