#include <iostream>
using namespace std;

void bubblesort(int arr[], int n)
{
    for (int i = 1; i <= n - 1; i++)
    {
        // repeated swapping
        for (int j = 0; j <= n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    int arr[] = {-2, 3, 5, 12, -1, 2, 0, 14, 3};
    int n = sizeof(arr) / sizeof(int);
    bubblesort(arr, n);
    for (auto x : arr)
    {
        cout << x << " ";
    }
    return 0;
}