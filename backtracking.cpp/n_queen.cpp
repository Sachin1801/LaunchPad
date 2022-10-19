#include <iostream>
using namespace std;

void print(int n, int board[][20])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool checkifcanplace(int board[][20], int n, int x, int y)
{
    // check for upper column
    for (int i = x; i >= 0; i--)
    {
        if (board[i][y] == 1)
        {
            return false;
        }
    }

    int i = x;
    int j = y;
    // check in left up diagonal
    while (i >= 0 and j >= 0)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i--;
        j--;
    }
    i = x;
    j = y;
    // check in right top diagonal direction
    while (i >= 0 and j < n)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i--;
        j++;
    }

    return true;
}

int cnt = 0;
bool solveNqueen(int n, int board[][20], int i) // i - for the current row , n- total size
{
    // base case
    if (i == n)
    {
        // print the board
        // print(n, board);
        cnt++;
        return false; // if we want to print all the configurations then we need to "RETURN FALSE" here
    }

    // rec case
    // placing the queen in every column
    for (int j = 0; j < n; j++)
    {
        // place the queen in the first position and then check if we can place or not
        if (checkifcanplace(board, n, i, j))
        {
            board[i][j] = 1;
            bool success = solveNqueen(n, board, i + 1);
            if (success)
                return true;
            // backtracking
            board[i][j] = 0;
        }
    }
    return false;
}

int main()
{

    int board[20][20] = {0};
    int n;
    cin >> n;

    solveNqueen(n, board, 0);
    cout << cnt << endl;

    return 0;
}
