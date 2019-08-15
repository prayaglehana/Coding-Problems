#include<iostream>
#define N 4
#include<stdio.h>

using namespace std;
void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

bool isSafe(int board[N][N], int row, int col)
{
    int i, j;

    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;

    for (i=row-1, j=col-1; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;


    for (i=row-1, j=col+1; i>=0&&j<N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}


bool solveNQ(int board[N][N], int row)
{
    if(row>=N)
        return true;


            for(int j=0;j<N;++j){
                if(isSafe(board,row,j)){
                    board[row][j]=1;

                    if(solveNQ(board,row+1))
                        return true;
                    else
                       {  board[row][j]=0;
                           continue;

                       }
                }

            }
            return false;

}

bool solveNQ()
{
    int board[N][N] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    if ( solveNQ(board, 0) == false )
    {
      printf("Solution does not exist");
     // return false;
    }

    printSolution(board);
    return true;
}

// driver program to test above function
int main()
{
    solveNQ();
    return 0;
}
