#include <iostream>
using namespace std;

int fiboTopDown(int n, int dp[])
{
    // base case
    if (n == 0 or n == 1)
    {
        return dp[n] = n;
    }

    // rec case
    if (dp[n] != 0)
    {
        return dp[n];
    }

    return dp[n] = fiboTopDown(n - 1, dp) + fiboTopDown(n - 2, dp);
}

// Bottom_Up Approach
int fiboBottomUp(int n, int *dp)
{
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    int dp[10001] = {0};
    cout << fiboTopDown(n, dp) << endl;
    int dp2[10001] = {0};
    cout << fiboBottomUp(n, dp2) << endl;

    return 0;
}