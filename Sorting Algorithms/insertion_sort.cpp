#include <iostream>
using namespace std;

void insertionsort(int arr[], int n)
{
    for (int i = 1; i <= n - 1; i++)
    {
        int current = arr[i];
        int prev = i - 1;
        // loop to find the right index for the currene element
        while (prev >= 0 and arr[prev] > current)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = current;
    }
}

int main()
{
    int arr[] = {-2, 3, 5, 12, -1, 2, 0, 14, 3};
    int n = sizeof(arr) / sizeof(int);
    insertionsort(arr, n);
    for (auto x : arr)
    {
        cout << x << " ";
    }
    return 0;
}