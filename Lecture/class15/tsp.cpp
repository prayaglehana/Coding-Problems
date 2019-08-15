#include<iostream>
#include<bits/stdc++.h>
using namespace std;
template <typename T>
class HashGraph{
    int V;
    list <int> *l;
public:

    void addEdge(T u,T v,int wt){
    l[u].push_back(make_pair(v,wt));
    l[v].push_back(make_pair(u,wt));
    }
    void printAdjList(){
        for(auto cityPair : l){
            cout<<cityPair.first<<"->";
            for(auto p:cityPair.second){
                cout<<"("<<p.first<<","<<p.second<<")";
            }
            cout<<endl;
        }
    }

};

class Graph{
    int V;
    list <int> *l;
public:
    Graph(int v){
        V=v;
        l=new list<int> [V];
    }
    void addEdge(int u ,int v,bool bidir=true){
        l[u].push_back(v);
        if(bidir)
        l[v].push_back(u);
    }
    void traverseDFS(int s,bool *visited){
        cout<<s<<" ";
        visited[s]=true;
        for(int nbr:l[s]){
           if(!visited[nbr])
            traverseDFS(nbr,visited);
        }
    }
    void DFS(int s){ // dfs
        bool *visited=new bool[V]{0};
        traverseDFS(s,visited);
    }





    void BFS(int s){
        queue<int> q;
        bool *visited=new bool[V]{0};

        q.push(s);
        visited[s]=true;

        cout<<" BFS ";
        while(!q.empty()){
                int t=q.front();
                cout<<t<<" ";
                q.pop();

                for(int nbr:l[t]){
                    if(!visited[nbr]){
                        q.push(nbr);
                        visited[nbr]=true;
                    }
                }
            }
    }

    void SSSH(int s,int d){ //  sinle source shortest path in unweighted graph (1 unit edge distance ) s=source , d=destination
        queue<int> q;
        bool *visited=new bool[V]{0};
        int *dist=new int[V];
        int *parent=new int[V];

        for(int i=0;i<V;++i){
            dist[i]=INT_MAX;
            parent[i]=-1;
        }

        q.push(s);
        visited[s]=true;
        dist[s]=0;

        cout<<" BFS ";
        while(!q.empty()){
                int t=q.front();
                cout<<t<<" ";
                q.pop();

                for(int nbr:l[t]){
                    if(!visited[nbr]){
                        q.push(nbr);
                        parent[nbr]=t;
                        dist[nbr]=dist[t]+1;
                        visited[nbr]=true;
                    }
                }
            }

            cout<<" shortest distance "<<dist[d]<<endl;

            cout<<" Path ";
            int temp=d;
            while(temp!=-1){
                cout<<temp<<"<-";
                temp=parent[temp];
            }
    }

    void tsp(int dist[][10],int n,int i,int visited){
          if(visited==((1<<n)-1)) return dist[i][0];

          int ans=INT_MAX;
          for(int j=0;j<n;++j){
            if((visited & (1<<j))==0){
                int cost=dist[i][j]+tsp(dist,n,j,(visited|(1<<j)));
                ans=min(ans,cost);
            }
          }
          return ans;
    }

    void printAdjList(){
        for(int i=0;i<V;++i){
            cout<<i<<"-->";
            for(int n:l[i]){
                cout<<n<<",";
            }
            cout<<endl;
        }
    }

};


int main(){

    Graph g(6);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(3,4);

    g.printAdjList();
    g.DFS(0);

    g.BFS(0);

    g.SSSH(0,4);

    g.tsp(dist);

    HashGraph <string>h;
    h.addEdge("delhi","lucknow",2);
    h.addEdge("delhi","lucknow",2);
    h.addEdge("mumbai","lucknow",6);

    h.printAdjList();




return 0;}



