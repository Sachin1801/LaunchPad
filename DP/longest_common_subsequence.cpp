#include <iostream>
#include <vector>
using namespace std;

// Bottom-Up Solution
int lis(vector<int> arr)
{
    int n = arr.size();
    vector<int> dp(n, 1);

    int lis = 1; // to store the max subsequence length
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = max(dp[i], 1 + dp[j]);
                lis = max(lis, dp[i]);
            }
        }
    }
    return lis;
}

int main()
{
    vector<int> arr = {50, 4, 10, 8, 30, 100};

    cout << lis(arr);

    return 0;
}