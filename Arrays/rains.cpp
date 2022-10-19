#include <iostream>
#include <vector>
using namespace std;

int trapped_water(vector<int> arr)
{
    int n = arr.size();
    if (n <= 2)
    {
        return 0;
    }
    vector<int> left(n, 0), right(n, 0);
    left[0] = arr[0];
    right[n - 1] = arr[n - 1];
    int ws = 0;
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], arr[i]);
        right[n - i - 1] = max(right[n - i], arr[n - i - 1]);
    }
    for (int i = 0; i <= n; i++)
    {
        ws += min(left[i], right[i]) - arr[i];
    }
    return ws;
}

int main()
{
    vector<int> water = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trapped_water(water);
    return 0;
}