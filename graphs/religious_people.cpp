#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int *dist;
class mycompare
{
public:
    mycompare()
    {
    }
    bool operator()(int a,int b)
    {
        return dist[a]<dist[b];
    }
};


class Graph
{

public:
    int V;
    int E;

    list <pair<int,int> > *adjList;
    Graph(int v,int e)
    {
        V=v;
        E=e;
        adjList=new list<pair<int,int>> [V+1];
        dist=new int[V+1];
    }

    bool operator()(int a,int b)
    {
        return dist[a]<dist[b];
    }

    void addEdge(int u,int v,int d,bool undirected=true)
    {
        adjList[u].push_back(make_pair(v,d));
        if(undirected)
            adjList[v].push_back(make_pair(u,d));
    }
    void showGraph()
    {
        for(int u=1; u<=V; ++u)
        {
            cout<<u<<" : ";

            for(auto it=adjList[u].begin(); it!=adjList[u].end(); ++it)
            {
                cout<<"("<<it->first<<","<<it->second<<")";
            }
            cout<<endl;

        }
    }

    int primsAlgoMinSpanningTree(int src)
    {

        int *parent=new int[V+1];

        for(int i=1; i<=V; ++i)
            parent[i]=-1;
        set <int,mycompare> minHeap;

        bool *taken=new bool[V+1];
        for(int i=1; i<=V; ++i)
            taken[i]=false;

        for(int i=1; i<=V; ++i)
        {
            if(i==src)
            {
                minHeap.insert(src);
                dist[src]=0;
            }
            else
            {
                minHeap.insert(i);
                dist[i]=INT_MAX;
            }
        }



        while(!minHeap.empty())
        {
            int cur=*minHeap.begin();

            minHeap.erase(minHeap.begin());

            taken[cur]=true;

            for(auto it=adjList[cur].begin(); it!=adjList[cur].end(); ++it)
            {

                int v=it->first;
                int d=it->second;


                if(!taken[v] && dist[v]>dist[cur])
                {

                    if(minHeap.find(v)!=minHeap.end())
                        minHeap.erase(minHeap.find(v));

                    dist[v] = dist[cur];
                    parent[v]=cur;

                    minHeap.insert(v);
                }
            }

        }
        int totalEdges=0;
        for(int i=1; i<=V; ++i)
        {
            if(parent[i]!=-1)
                ++totalEdges;
            cout<<i<<parent[i]<<" ";
        }
        return totalEdges;

    }



};
int main()
{

    int t;
    cin>>t;
    while(t--)
    {

        int v,e,T,R;
        cin>>v>>e>>T>>R;

        Graph g(v,e);
        for(int i=1; i<=e; ++i)
        {
            int u,v;
            cin>>u>>v;
            // g.addEdge(u,v,R);
        }
        //g.showGraph();

        // int edges=g.primsAlgoMinSpanningTree(1);
        long long int ans=T*v;
        if((R-T)>=0)
        {
            cout<<ans<<endl;
        }
        else
        {
            ans+=(R-T)*(v-1);
            cout<<ans<<endl;
        }


    }


    return 0;
}

