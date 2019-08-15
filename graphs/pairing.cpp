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

    int dfs(int u,bool *visited,int &nodes){
            visited[u]=true;
            ++nodes;
            for(int v:adjList[u]){
                if(!visited[v])
                    dfs(v,visited,nodes);
            }

    }


    long long int countComponents(){
        bool *visited=new bool[V+1];

        for(int i=0;i<V;++i)visited[i]=false;

        long long int total=V*(V-1)/2;

        for(int i=0;i<V;++i){

            if(!visited[i]){
                int nodes=0;
                dfs(i,visited,nodes);
                total-=nodes*(nodes-1)/2;
            }

        }
        return total;
    }





};
int main()
{


        int v,e;
        cin>>v>>e;

        Graph g(v,e);
        for(int i=1; i<=e; ++i)
        {
            int u,v;
            cin>>u>>v;
             g.addEdge(u,v,1);
        }
        //g.showGraph();
        cout<<g.countComponents()<<endl;




    return 0;
}

