#include <iostream>
#include <unordered_set>
using namespace std;

pair<int, int> find_pair(int arr[], int n, int key)
{
    pair<int, int> p;
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        if (s.find(key - (arr[i])) == s.end())
        {
            s.insert(arr[i]);
        }
        else if (s.find(key - (arr[i])) != s.end())
        {
            p.first = key - arr[i];
            p.second = arr[i];
            return p;
        }
    }
    p.first = -1;
    p.second = -1;
    return p;
}

int main()
{
    int target;
    cin >> target;
    int arr[] = {10, 5, 2, 3, -6, 9, 11};
    int n = sizeof(arr) / sizeof(int);
    pair<int, int> ans = find_pair(arr, n, target);
    cout << "(" << ans.first << "," << ans.second << ")";
    return 0;
}