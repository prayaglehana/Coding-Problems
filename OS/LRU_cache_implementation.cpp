#include <bits/stdc++.h>
using namespace std;

void showMap(unordered_map <int,list<int> :: iterator  > mp){
    cout<<" map "<<endl;
    for(auto it=mp.begin();it!=mp.end();++it){
        cout<<it->first<<" : "<<*(it->second)<<endl;
    }
    return;
}
void showQ(list<int> q){
    cout<<" que ";
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop_front();
    }
    cout<<endl;
}
int main() {
    int t;
    cin>>t;
    int p[1001];
    while(t--){
        int n,cap;
        cin>>n;
        int page_fault=0;

        for(int i=0;i<n;++i)cin>>p[i];

        cin>>cap;

        list <int> q;
        unordered_map <int,list<int> :: iterator  > mp;

        for(int i=0;i<n;++i){



            if(mp.find(p[i])!=mp.end()){ //page hit

                q.erase(mp[p[i]]);
                mp.erase(p[i]);

                q.push_front(p[i]);
                mp.insert(make_pair(p[i],q.begin()));

              //  cout<<"page request : "<<p[i]<<" pagehit "<<page_fault<<endl;

            }
            else{
                      //page fault;
                    ++page_fault;
                    if(q.size()<cap){

                        q.push_front(p[i]);
                        mp.insert(make_pair(p[i],q.begin()));
                    }
                    else{
                        mp.erase(q.back());
                        q.pop_back();
                        q.push_front(p[i]);
                        mp.insert(make_pair(p[i],q.begin()));
                    }
                    //cout<<"page request : "<<p[i]<<" pagefault "<<page_fault<<endl;
            }


           // showMap(mp);
           // showQ(q);


        }

        cout<<page_fault<<endl;
    }
	return 0;
}
