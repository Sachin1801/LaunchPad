#include <iostream>
using namespace std;

void selectionsort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_pos = i;
        for (int j = i + 1; j <= n - 1; j++)
        {
            if (arr[j] < arr[min_pos])
            {
                min_pos = j;
            }
        }
        swap(arr[i], arr[min_pos]);
    }
}

int main()
{
    int arr[] = {-2, 3, 5, 12, -1, 2, 0, 14, 3};
    int n = sizeof(arr) / sizeof(int);
    selectionsort(arr, n);
    for (auto x : arr)
    {
        cout << x << " ";
    }
    return 0;
}