// C program to print all permutations with duplicates allowed



#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 14

using namespace std;


int graph[14][14];

int dist[1000000]={0};
int N;
    int min_index=0;
  int i_=0;
  int combinations[1000000][20];

int findCeil(char str[], char first, int l, int h);
int compare(const void *a, const void * b);
void sortedPermutations(char str[]);
void find_optimal_ride();
void print_optimal_path();
void swap(char *a, char b);


string city_at[]={"thapar","no phatak","leela bhawan","dukh nivaran","tripuri",
"rajendra hospital","fountain chowk","choti baradari",
"anardana chowk","sherevala gate","bus stand","Aarya samaj chowk","urban estate","punjabi university"};


class node{
     int parent[V];
     int dist[V];




     public:
          node(){taken=false;}

         int location;
         bool taken;


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

                                           // printf("%d ", j);
                                            cout<<city_at[j]<<"->";
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


void dijkstra( )
                                {
                                int src=location;

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





}s,p[10],d[10];










int main(){


    cout<<"Enter The Graph-adjency-matrix\n";
    for(int i=0;i<V;++i){
        for(int j=0;j<V;++j){
            scanf("%d",&(graph[i][j]));
        }
    }
    cout<<graph[2][0];




    cout<<"\nEnter The Location Of cab ";
    cin>>s.location;
  s.dijkstra();

  cout<<"Enter total no. of passengers ";
  cin>>N;


     cout<<"\nEnter resp. locations of passengers\n";
     for(int i=0;i<N;++i){
            cin>>p[i].location;}

cout<<"\nEnter resp. destinations of passengers \n";
  for(int i=0;i<N;++i){
                cin>>d[i].location;

                     }


   find_optimal_ride();
  print_optimal_path();






    return 0;
}

void find_optimal_ride(){
          for(int i=0;i<N;++i)
                  p[i].dijkstra();

        for(int i=0;i<N;++i)
                    d[i].dijkstra();


char str[6];
for(int i=0;i<2*N;++i)
    {str[i]=(char)(48+i%N);}



sortedPermutations(str);



//    for(int i=0;i<i_;++i){
//       for(int j=0;j<2*N;++j) {cout<<combinations[i][j]<<" ";}
//       cout<<endl;
//    }


    for(int i=0;i<i_;++i){
            char prev;

            dist[i]=s.distance_to(p[combinations[i][0]].location);
            p[combinations[i][0]].taken=true;
            prev='p';

               for(int j=1;j<2*N;++j) {

                                   if(p[combinations[i][j]].taken)
                                             {if(prev=='p')
                                                dist[i]+=p[combinations[i][j-1]].distance_to(d[combinations[i][j]].location);
                                                else
                                                    dist[i]+=d[combinations[i][j-1]].distance_to(d[combinations[i][j]].location);

                                                          prev='d';
                                                }



                                    else{
                                                    if(prev=='p')
                                                            dist[i]+=p[combinations[i][j-1]].distance_to(p[combinations[i][j]].location);
                                                            else
                                                                dist[i]+=d[combinations[i][j-1]].distance_to(p[combinations[i][j]].location);

                                                                     p[combinations[i][j]].taken=true;
                                                                      prev='p';
                                                }
                                    }
                    if(dist[min_index]>dist[i])
                            min_index=i;

               }

                cout<<"\n miniumum distance travelled : "<<dist[min_index]<<endl<<"with min index "<<min_index<<endl;


    }


void print_optimal_path(){
char prev;
cout<<city_at[s.location]<<"->";

    for(int i=0;i<N;++i)
        p[i].taken=false;

     s.printPath(p[combinations[min_index][0]].location);

        p[combinations[min_index][0]].taken=true;
            prev='p';


               for(int j=1;j<2*N;++j) {

                                   if(p[combinations[min_index][j]].taken)
                                             {if(prev=='p')
                                                    {
                                                        p[combinations[min_index][j-1]].printPath(d[combinations[min_index][j]].location);}
                                                else
                                                    d[combinations[min_index][j-1]].printPath(d[combinations[min_index][j]].location);

                                                          prev='d';
                                                }



                                    else{
                                                    if(prev=='p')
                                                            p[combinations[min_index][j-1]].printPath(p[combinations[min_index][j]].location);
                                                            else
                                                                d[combinations[min_index][j-1]].printPath(p[combinations[min_index][j]].location);

                                                                     p[combinations[min_index][j]].taken=true;
                                                                      prev='p';
                                                }

                                    }
}









int compare(const void *a, const void * b)
{
    return ( *(char *)a - *(char *)b );
}

// A utility function two swap two characters a and b
void swap(char* a, char* b)
{
    char t = *a;
    *a = *b;
    *b = t;
}

// This function finds the index of the smallest character
// which is greater than 'first' and is present in str[l..h]
int findCeil(char str[], char first, int l, int h)
{
    // initialize index of ceiling element
    int ceilIndex = l;

    // Now iterate through rest of the elements and find
    // the smallest character greater than 'first'
    for (int i = l+1; i <= h; i++)
        if (str[i] > first && str[i] < str[ceilIndex])
            ceilIndex = i;

    return ceilIndex;
}


void sortedPermutations(char str[])
{
    // Get size of string
    int size = 2*N;

    // Sort the string in increasing order
    qsort(str, size, sizeof( str[0] ), compare);

    // Print permutations one by one
    bool isFinished = false;
    while (!isFinished)
    {

        static int x = 1;

        for(int k=0;k<2*N;++k)
            combinations[i_][k]=(int)str[k]-48;

        ++i_;

        int i;
        for (i = size - 2; i >= 0; --i)
            if (str[i] < str[i+1])
                break;

        if (i == -1)
            isFinished = true;
        else{

            int ceilIndex = findCeil(str, str[i], i + 1, size - 1);

            swap(&str[i], &str[ceilIndex]);


            qsort(str + i + 1, size - i - 1, sizeof(str[0]), compare);
        }
    }
}
