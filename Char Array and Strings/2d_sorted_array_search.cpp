#include <iostream>
using namespace std;

pair<int, int> staircaseSearch(int arr[][4], int n, int m, int key)
{
    pair<int, int> ans;
    int row = 1, col = m - 1;
    while (arr[row][col] != key)
    {
        // corner case
        if (row > 0 or col < 0)
        {
            ans.first = -1;
            ans.second = -1;
            return ans;
            break;
        }
        if (arr[row][col] > key)
        {
            col--;
        }
        else if (arr[row][col] < key)
        {
            row++;
        }
    }
    ans.first = row;
    ans.second = col;
    return ans;
}

int main()
{
    int arr[][4] = {{10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50}};

    int n = 4, m = 4;

    pair<int, int> coords = staircaseSearch(arr, n, m, 31);
    cout << coords.first << " " << coords.second << endl;
    return 0;
}