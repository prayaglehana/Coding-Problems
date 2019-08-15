#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 14

using namespace std;

int graph[14][14];
int new_graph[5][5];

int s_,p1_,d1_,p2_,d2_;

void find_optimal_ride();

class node{
     int parent[V];
     int dist[V];

     public:

        int distance_to(int d){
            return dist[d];
        }



    int minDistance(bool vSet[])
                    {

                        int min = INT_MAX, min_index;

                        for (int v = 0; v < V; v++)
                            if (vSet[v] == false &&dist[v] <= min)
                                min = dist[v], min_index = v;

                        return min_index;
                    }
    void printPath(int j)
                                        {


                                            if (parent[j] == - 1)
                                                return;

                                            printPath( parent[j]);

                                            printf("%d ", j);
                                        }

    int printSolution( int n,int src)
                            {

                                printf("Vertex\t Distance\tPath");
                                for (int i = 0; i < V; i++)
                                {
                                    printf("\n%d -> %d \t\t %d\t\t%d ",src, i, dist[i], src);

                                    printPath(i);
                                }
                            }


void dijkstra( int src)
                                {


                                    bool vSet[V];


                                    for (int i = 0; i < V; i++)
                                    {   //parent[0]=-1;
                                        parent[src] = -1;
                                        dist[i] = INT_MAX;
                                        vSet[i] = false;
                                    }


                                    dist[src] = 0;


                                    for (int count = 0; count < V - 1; count++)
                                    {

                                        int u = minDistance( vSet);


                                        vSet[u] = true;


                                        for (int v = 0; v < V; v++)

                                            if (!vSet[v] && graph[u][v] &&dist[u] + graph[u][v] < dist[v])
                                            {
                                                parent[v] = u;
                                                dist[v] = dist[u] + graph[u][v];
                                            }
                                    }



                                     //printSolution( V,src);


                                }





}s,p1,d1,p2,d2;;










int main(){


    cout<<"Enter The Graph-adjency-matrix\n";
    for(int i=0;i<V;++i){
        for(int j=0;j<V;++j){
            scanf("%d",&(graph[i][j]));
        }
    }
    cout<<graph[2][0];


        s.dijkstra(0);


    cout<<"\nEnter The Location Of cab ";
    cin>>s_;
  s.dijkstra(s_);


     cout<<"\nEnter resp. locations of passengers with destination (p1,d1) (p2,d2) \n";
    cin>>p1_>>d1_>>p2_>>d2_;



   find_optimal_ride();







    return 0;
}

void find_optimal_ride(){
            p1.dijkstra(p1_);
            d1.dijkstra(d1_);
            p2.dijkstra(p2_);
            d2.dijkstra(d2_);

    int dist[6];
        dist[0]=s.distance_to(p1_)+p1.distance_to(d1_)+d1.distance_to(p2_)+p2.distance_to(d2_);
        dist[1]=s.distance_to(p1_)+p1.distance_to(p2_)+p2.distance_to(d1_)+d1.distance_to(d2_);
        dist[2]=s.distance_to(p1_)+p1.distance_to(p2_)+p2.distance_to(d2_)+d2.distance_to(d1_);

        dist[3]=s.distance_to(p2_)+p2.distance_to(d2_)+d2.distance_to(p1_)+p1.distance_to(d1_);
        dist[4]=s.distance_to(p2_)+p2.distance_to(p1_)+p1.distance_to(d2_)+d2.distance_to(d1_);
        dist[5]=s.distance_to(p2_)+p2.distance_to(p1_)+p1.distance_to(d1_)+d1.distance_to(d2_);

     int   index_=0;

        for(int i=1;i<5;++i){
                                if(dist[index_]>dist[i])
                                index_=i;
                            }
        cout<<endl<<"The Optimal Ride is :\n";
        cout<<s_<<" ";
        if(index_==0)
           {s.printPath(p1_);
           p1.printPath(d1_);
           d1.printPath(p2_);
           p2.printPath(d2_);}
        else if(index_==1)
             {s.printPath(p1_);
             p1.printPath(p2_);
             p2.printPath(d1_);
             d1.printPath(d2_);}
        else if(index_==2)
                {s.printPath(p1_);
                p1.printPath(p2_);
                p2.printPath(d2_);
                d2.printPath(d1_);}

        else if(index_==3)
                {s.printPath(p2_);
                p2.printPath(d2_);
                d2.printPath(p1_);
                p1.printPath(d1_);}
        else if(index_==4)
                {s.printPath(p2_);
                p2.printPath(p1_);
                p1.printPath(d2_);
                d2.printPath(d1_);}
        else if(index_==5)
                {s.printPath(p2_);
                p2.printPath(p1_);
                p1.printPath(d1_);
                d1.printPath(d2_);}
}
