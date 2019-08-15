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



    void addEdge(int u,int v,bool undirected=false)
    {
        adjList[u].push_back(v);
        if(undirected)
            adjList[v].push_back(u);
    }
    void showGraph()
    {
        for(int u=1; u<=V; ++u)
        {
            cout<<u<<" : ";

            for(int v: adjList[u])
            {
                cout<<v<<",";
            }
            cout<<endl;

        }
    }

    int bfs(int src,bool *visited,int *dist)
    {

        queue <int> Q;

        Q.push(src);
        visited[src] =true;
        dist[src]=0;


        while(!Q.empty())
        {
            int cur=Q.front();
            Q.pop();

            for(int v:adjList[cur])
            {
                if(!visited[v])
                {
                    Q.push(v);
                    visited[v]=true;
                    dist[v]=dist[cur]+1;
                }
            }
        }
    }


    void bfsInitiate(int src)
    {
        bool *visited=new bool[V+1];

        for(int i=1; i<=V; ++i)
            visited[i]=false;

        int *dist=new int[V+1];


        for(int i=1; i<=V; ++i)
            dist[i]=INT_MAX;

        bfs(src,visited,dist);

        cout<<dist[V]<<endl;

    }



};
int main()
{

    int t;
    cin>>t;
    while(t--){
        int n,l,s;
        cin>>n>>l>>s;

        map <int,int> ladder;
        map <int,int> snakes;

        for(int i=1;i<=l;++i){
            int x,y;
            cin>>x>>y;
            ladder.insert(make_pair(x,y));
        }

        for(int i=1;i<=s;++i){
            int x,y;
            cin>>x>>y;
            snakes.insert(make_pair(x,y));
        }

        Graph g(n,n*n);
        for(int u=1; u<=n;++u)
        {
            for(int v=u+1; v<=(u+6); ++v)
            {   int destination;
                if((ladder[v]+snakes[v])!=0)
                    destination=ladder[v]+snakes[v];
                else
                    destination=v;
                if(destination<=n){

                    g.addEdge(u,destination);
                }

            }

        }


        //g.showGraph();


        g.bfsInitiate(1);



    }




    return 0;
}

