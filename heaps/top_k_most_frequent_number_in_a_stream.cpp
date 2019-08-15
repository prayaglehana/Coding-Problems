#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Freq{
public:
    int freq;
    bool taken;
    Freq(int f,bool t){
        freq=f;
        t=t;
    }
};

map <int,Freq> m;

class mycompare{
public:

    bool operator()(int a,int b){
         if(m.at(a).freq==m.at(b).freq) return a<b;
         return m.at(a).freq>m.at(b).freq;
    }

};
bool sortCompare(int a,int b){
    if(m.at(a).freq==m.at(b).freq) return a<=b;
   return m.at(a).freq>m.at(b).freq;

}
void printHeap(priority_queue<int,vector<int>,mycompare> h){
        int n=h.size();
        vector<int> a;


         for(int i=0;i<n;++i){

            a.push_back(h.top());
            h.pop();
        }
        sort(a.begin(),a.end(),sortCompare);
        for(int i=0;i<n;++i){

            cout<<a[i]<<" ";
        }

}


int main(){
    int t;

    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        priority_queue<int,vector<int>,mycompare> h;
        m.clear();
        while(n--){
                int e;
                Freq f(1,false);
                cin>>e;



                if(m.find(e)==m.end())  m.insert(make_pair(e,f));
                else  {
                        int new_freq=(m.at(e)).freq+1;

                        (m.find(e)->second).freq=new_freq;

                }
                map <int,Freq>  :: iterator ele_it=m.find(e);

                map <int,Freq>  :: iterator top_it;
                if(!h.empty()) top_it=m.find(h.top());

                if((ele_it->second).taken!=true){
                                  if(h.size()<k)     {

                                        (ele_it->second).taken=true;
                                        h.push(e);}

                else if(!h.empty()){

                        if((top_it->second).freq<(ele_it->second).freq){


                            (top_it->second).taken=false;
                            (ele_it->second).taken=true;
                            h.pop();
                            h.push(e);
                        }
                        else if((top_it->second).freq==(ele_it->second).freq){
                            if(e<h.top()){

                               (top_it->second).taken=false;
                                (ele_it->second).taken=true;
                                h.pop();
                                h.push(e);
                            }

                        }

                    }
                    cout<<" map "<<endl;
                    for(auto it=m.begin();it!=m.end();++it){
                        cout<<it->first<<" : f "<<(it->second).freq<<" taken "<<(it->second).taken<<endl;
                    }


                }
                cout<<" heap ";
                printHeap(h);
                cout<<endl;





        }
        cout<<endl;
    }


    return 0;

}

