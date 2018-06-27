#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
 
   const int N = 4;
   int i, j;
void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout<< board[i][j]<<"  ";
        cout<<endl;
    }
}
 
bool IS(int board[N][N], int row, int col)
{
   
    for (i = 0; i < col; i++)
    {
        if (board[row][i])
            return false;
    }
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return false;
    }
 
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
    {
        if (board[i][j])
            return false;
    }
 
    return true;
}
 
bool solveNQUtil(int board[N][N], int col)
{
    if (col >= N)
        return true;
    for (int i = 0; i < N; i++)
    {
        if ( IS(board, i, col) )
        {
            board[i][col] = 1;
            if (solveNQUtil(board, col + 1) == true)
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}
 
bool solveNQ()
{
    int board[N][N] = {0};
    if (solveNQUtil(board, 0) == false)
    {
        cout<<"Solution does not exist"<<endl;
        return false;
    }
    printSolution(board);
    return true;
}
 

int main()
{
    solveNQ();
    return 0;
}
