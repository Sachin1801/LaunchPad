#include <iostream>
#include <vector>
using namespace std;

void countingsort(int arr[], int n, int me)
{
    vector<int> v(me + 1, 0);
    for (int i = 0; i < n; i++)
    {
        v[arr[i]]++;
    }
    int j = 0;
    for (int i = 0; i < v.size(); i++)
    {
        while (v[i] != 0)
        {
            arr[j] = i;
            v[i]--;
            j++;
        }
    }
}

int main()
{
    int arr[] = {1, 33, 2, 55, 64, 34, 85, 5, 12, 21, 55, 21};
    int me = INT_MIN;
    int n = sizeof(arr) / sizeof(int);
    for (int i = 0; i < n; i++)
    {
        me = max(me, arr[i]);
    }
    countingsort(arr, n, me);
    for (auto x : arr)
    {
        cout << x << " ";
    }
    return 0;
}