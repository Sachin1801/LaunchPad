#include <iostream>
using namespace std;

void reverse_array(int arr[], int n)
{
    int i = 0;
    while (i <= (n - i - 1))
    {
        swap(arr[i], arr[n - i - 1]);
        i++;
    }
}

int main()
{
    int arr[] = {2, 44, 3, 12, 17, 98, 56, 32, 65, 1, 11, 22};
    int n = sizeof(arr) / sizeof(int);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    reverse_array(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}