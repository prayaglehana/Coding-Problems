#include<iostream>
using namespace std;

void printSoln(int,int);
int total_w=7;
int no_of_items=4;

int max_(int,int);

class Item{
    public:
int w;
int v;
}item[4];

int T[4][8];

int main(){

item[0].w=1;
item[0].v=1;

item[1].w=3;
item[1].v=4;

item[2].w=4;
item[2].v=5;

item[3].w=5;
item[3].v=7;






for(int i=0;i<no_of_items;++i){
    for(int j=1;j<=total_w;++j){
            if(i!=0)
                    {
                    if(item[i].w<=j)
                        T[i][j]=max_(item[i].v+T[i-1][j-item[i].w],T[i-1][j]);
                    else
                        T[i][j]=T[i-1][j];
                    }
                else
                {
                    if(item[i].w<=j)
                        T[i][j]=item[i].v;
                }

    }


}
for(int i=0;i<no_of_items;++i){
    for(int j=0;j<=total_w;++j){
        cout<<T[i][j]<<" ";
    }
    cout<<endl;}

printSoln(no_of_items-1,total_w);









}
void printSoln(int x,int y){

    if(T[x][y]==T[x-1][y])
            printSoln(x-1,y);
    else
    {

        cout<<x+1<<" ";
       if(T[x-1][y-item[x].w]!=0)
         printSoln(x-1,y-item[x].w);

    }

}
int max_(int a,int b){
if(a>=b)return a;
else
    return b;
}
