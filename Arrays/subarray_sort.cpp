#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool outoforder(vector<int> arr, int i)
{
    int x = arr[i];
    if (i == 0)
    {
        return x > arr[1];
    }
    if (i == arr.size() - 1)
    {
        return x < arr[i - 1];
    }
    return x > arr[i + 1] or x < arr[i - 1];
}

pair<int, int> subarray_sort(vector<int> v)
{
    int lar = INT_MIN;
    int smal = INT_MAX;
    for (int i = 0; i < v.size(); i++)
    {
        int x = v[i];
        if (outoforder(v, i))
        {
            smal = min(smal, x);
            lar = max(lar, x);
        }
    }

    if (smal == INT_MAX)
    {
        return {-1, -1};
    }

    int left = 0;
    while (smal >= v[left])
    {
        left++;
    }

    int right = v.size() - 1;
    while (lar <= v[right])
    {
        right--;
    }
    return {left, right};
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};

    pair<int, int> ans = subarray_sort(v);

    cout << "{" << ans.first << "," << ans.second << "}" << endl;

    return 0;
}