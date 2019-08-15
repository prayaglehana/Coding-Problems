#include <bits/stdc++.h>
using namespace std;

// class Graph{
//     int V,E;
//     list<pair<int,int>> *adjList;
//     public:

//         Graph(int V,int E){
//             this->V=V;
//             this->E=E;
//             adjList=new list<pair<int,int>> [V+1];
//         }

//         void insertEdge(int x,int y,int d){
//             adjList[x].push_back(make_pair(y,d));
//         }

//         void showGraph(){
//             for(int i=1;i<=V;++i){
//                 cout<<i<<" : "<<endl;
//                 for(pair<int,int> p : adjList[i] ){
//                     cout<<"("<<p.first<<","<<p.second<<")"<<endl;
//                 }
//                 cout<<endl;
//             }
//         }

// };

class node{
    public:
        int x,y,d;
        node(int x,int y,int d){
            this->x=x;
            this->y=y;
            this->d=d;
        }
};

bool mycompare(node a,node b){
    return a.x<b.x;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,p;
	    cin>>n>>p;

	    unordered_map<int,pair<int,int>> child;
	    unordered_map<int,int> parent;

	    bool *taken =new bool[n+1];


	    for(int i=1;i<=p;++i){
	        int x,y,d;
	        cin>>x>>y>>d;
	        child[x]=make_pair(y,d);
	        parent[y]=x;
	    }
	    vector <node> v;

	   // for(auto it=child.begin();it!=child.end();++it){
	   //     pair<int,int> p=it->second;
	   //     cout<<it->first<<" "<<p.first<<","<<p.second<<endl;
	   // }
	    for(int i=1;i<=n;++i){
	        if(!taken[i]){
	            int cur=i;

	            while(parent[cur])cur=parent[cur];
	            int par=cur;
	            int min_d=INT_MAX;
	            taken[par]=true;

	          //  cout<<"top"<<cur<<endl;
	            while(child.find(cur)!=child.end() && !taken[child[cur].first] ){
	                pair<int,int> p=child[cur];
	                taken[p.first]=true;
	                min_d=min(min_d,p.second);
	                cur=p.first;
	            }
	            if(min_d!=INT_MAX){
                    node n(par,cur,min_d);
                    v.push_back(n);
	            }
	        }
	    }
	    sort(v.begin(),v.end(),mycompare);
	    cout<<v.size()<<endl;

	    for(node n:v){
	        cout<<n.x<<" "<<n.y<<" "<<n.d<<endl;
	    }

	}
	return 0;
}
