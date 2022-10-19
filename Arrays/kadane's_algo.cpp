#include <iostream>
using namespace std;

int maximum_sum_subarray(int arr[], int n)
{
    int cs = 0;
    int ms = 0;
    for (int i = 0; i < n; i++)
    {
        cs += arr[i];
        if (cs < 0)
        {
            cs = 0;
        }
        ms = max(ms, cs);
    }
    return ms;
}

int main()
{
    int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3, 5};
    int n = sizeof(arr) / sizeof(int);
    cout << maximum_sum_subarray(arr, n) << endl;
    return 0;
}