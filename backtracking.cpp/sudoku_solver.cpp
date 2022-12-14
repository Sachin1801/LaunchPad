#include <iostream>
using namespace std;

bool isSafe(int mat[][9], int i, int j, int no)
{
    // check in the row and column
    for (int k = 0; k < 9; k++)
    {
        if (mat[k][j] == no || mat[i][k] == no)
        {
            return false;
        }
    }
    // check for subgrid
    int sx = (i / 3) * 3;
    int sy = (j / 3) * 3;

    // loop for checking in subgrid
    for (int x = sx; x < sx + 3; x++)
    {
        for (int y = sy; y < sy + 3; y++)
        {
            if (mat[x][y] == no)
            {
                return false;
            }
        }
    }
    return true;
}

void print(int mat[][9], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

bool solveSudoku(int mat[][9], int i, int j, int n)
{
    // base case
    if (i == n)
    {
        // print the matrix
        print(mat, n);
        return true;
    }

    // rec case
    if (j == n)
    {
        return solveSudoku(mat, i + 1, 0, n);
    }

    // check if pre-filled then skip
    if (mat[i][j] != 0)
    {
        return solveSudoku(mat, i, j + 1, n);
    }

    // if not pre-filled try to put in a number
    for (int no = 1; no <= n; i++)
    {
        // whether it is safe to place the number or not
        if (isSafe(mat, i, j, no))
        {
            mat[i][j] = no;
            bool solvesubproblem = solveSudoku(mat, i, j + 1, n);
            if (solvesubproblem)
            {
                return true;
            }
        }
    }
    // backtracking
    mat[i][j] = 0;
    return false;
}

int main()
{
    int n = 9;
    int mat[9][9] =
        {{5, 3, 0, 0, 7, 0, 0, 0, 0},
         {6, 0, 0, 1, 9, 5, 0, 0, 0},
         {0, 9, 8, 0, 0, 0, 0, 6, 0},
         {8, 0, 0, 0, 6, 0, 0, 0, 3},
         {4, 0, 0, 8, 0, 3, 0, 0, 1},
         {7, 0, 0, 0, 2, 0, 0, 0, 6},
         {0, 6, 0, 0, 0, 0, 2, 8, 0},
         {0, 0, 0, 4, 1, 9, 0, 0, 5},
         {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    if (!solveSudoku(mat, 0, 0, n))
    {
        cout << "No solution exists!";
    }
    else
    {
        cout << "Solution exist";
    }

    return 0;
}