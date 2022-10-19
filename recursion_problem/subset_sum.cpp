#include <iostream>
#include <vector>
using namespace std;

int subset_sum(vector<int> arr, int n, int i, int key)
{
    // base case
    if (i == n)
    {
        if (key == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    // rec case
    int a = subset_sum(arr, n, i + 1, key - arr[i]);
    int b = subset_sum(arr, n, i + 1, key);
    return a + b;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    int key;
    cin >> key;

    cout << subset_sum(arr, n, 0, key);

    return 0;
}