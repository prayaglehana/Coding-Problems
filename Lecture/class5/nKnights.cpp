#include<iostream>
using namespace std;

bool canPlace(char soln[8][8],int x,int y,int N){

   for(int i=-2;i<=2;++i){
        if(abs(i)>=1){
            int j=3-i;
            if((x+i)>=0 && (x+i)<N && (x+j)>=0 && (x+j)<N ){
                    if(soln[x+i][x+j]=='K') return false;
                }
        }
  }
   return true;
}
void printSolution(char soln[8][8],char board[8][8],int x,int y,int N){
        if(x==(N-1) && y==(N-1)){
            for(int q=0;q<N;++q){
                for(int w=0;w<N;++w){
                    cout<<soln[q][w]<<" ";
                }
                cout<<endl;
            }
            return;
        }
        for(int i=x;i<N;++i){
            for(int j=y;j<N;++j){
                if(soln[i][j]!='K' && canPlace(soln,i,j,N) )
                    {printSolution(soln,board,i,j,N);
                    return;}
            }
        }

}
int main(){
char board[][8]={
    "0000",
    "0000",
    "0000",
    "0000",

};
char soln[][8]={
  "0000",
    "0000",
    "0000",
    "0000"

};
printSolution(soln,board,0,0,4);

return 0;}
