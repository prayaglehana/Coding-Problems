#define mx 20005
#define INF 99999999
struct node
{
    int u,w;
    node(int a,int b){u=a; w=b;}
    bool operator < ( const node& p ) const {      return w > p.w;   }
};

int NODES=1000,EDGES;
vector<int>d;
vector<int>g[mx],cost[mx];
int dijkstra(int m,int n)
{
    d = vector<int>(NODES+1,INF);

    priority_queue<node>q;
    q.push(node(m,0));
    d[m]=0;
    while(!q.empty())
    {
        node top=q.top(); q.pop();
        int u=top.u;
        if(u==n) return d[n];
        for(int i=0;i<(int)g[u].size();i++)
        {
            int v=g[u][i];
            if(d[u]+cost[u][i]<d[v])
            {
                d[v]=d[u]+cost[u][i];
                //par[v]=u;
                q.push(node(v,d[v]));
            }
        }
    }
    return -1;
}
