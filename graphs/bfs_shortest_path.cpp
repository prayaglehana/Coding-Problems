#include<iostream>
#include<bits/stdc++.h>
using namespace std;



class Graph
{

public:
    int V;
    int E;

    list <int> *adjList;
    Graph(int v,int e)
    {
        V=v;
        E=e;
        adjList=new list<int> [V+1];
      //  dist=new int[V+1];
    }



    void addEdge(int u,int v,bool undirected=true)
    {
        adjList[u].push_back(v);
        if(undirected)
            adjList[v].push_back(u);
    }
    void showGraph()
    {
        for(int u=0; u<V; ++u)
        {
            cout<<u<<" : ";

            for(int v: adjList[u])
            {
                cout<<v<<",";
            }
            cout<<endl;

        }
    }

    int bfs(int src,bool *visited,int *dist){

            queue <int> Q;

            Q.push(src);
            visited[src] =true;
            dist[src]=0;


            while(!Q.empty()){
                int cur=Q.front();
                Q.pop();

                for(int v:adjList[cur]){
                    if(!visited[v]){
                        Q.push(v);
                        visited[v]=true;
                        dist[v]=dist[cur]+6;
                    }
                }
            }
    }


    void bfsInitiate(int src){
        bool *visited=new bool[V+1];

        for(int i=1;i<=V;++i)visited[i]=false;

        int *dist=new int[V+1];


        for(int i=1;i<=V;++i)dist[i]=INT_MAX;

        bfs(src,visited,dist);

        for(int i=1;i<=V;++i){
            if(i!=src && dist[i]!=INT_MAX)
                cout<<dist[i]<<" ";
            else if(dist[i]==INT_MAX)
                cout<<"-1 ";
        }

    }



};
int main()
{

    int Q;
    cin>>Q;

    while(Q--){

        int v,e;
        cin>>v>>e;

        Graph g(v,e);
        for(int i=1; i<=e; ++i)
        {
            int u,v;
            cin>>u>>v;
             g.addEdge(u,v);
        }
        //g.showGraph();
        int src;
        cin>>src;
        g.bfsInitiate(src);
        cout<<endl;
    }





    return 0;
}

