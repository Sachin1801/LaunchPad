#include <iostream>
#include <vector>
using namespace std;

// Top Down
int mincoinexchange1(vector<int> denom, int n, vector<int> &dp)
{

    if (n == 0)
    {
        return dp[n] = 0;
    }

    if (dp[n] != 0)
    {
    }
}

// bottom up
int mincoinexchange2(vector<int> denom, int n)
{
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        dp[i] = INT_MAX;

        for (auto c : denom)
        {
            if (i - c >= 0 and dp[i - c] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }
    return dp[n] == INT_MAX ? -1 : dp[n];
}

int main()
{
    vector<int> denom = {1, 3, 7, 10};
    vector<int> dp(1000, 0);
    cout << mincoinexchange1(denom, 15, dp) << endl;
    cout << mincoinexchange2(denom, 19) << endl;

    return 0;
}