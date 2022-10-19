#include <iostream>
using namespace std;

int binarysearch(int arr[], int n, int key)
{
    int s = 0, e = n - 1;
    int mid = 0;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            e = mid - 1;
        }
        else if (key > arr[mid])
        {
            s = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {2, 44, 3, 12, 17, 98, 56, 32, 65, 1, 11};
    int n = sizeof(arr) / sizeof(int);
    sort(arr, arr + n);
    int s = 0, e = n - 1;
    int key;
    cin >> key;
    int ans = binarysearch(arr, n, key);
    if (ans != -1)
    {
        cout << "The key is found at " << ans << "th index" << endl;
    }
    else
    {
        cout << "Key not found " << endl;
    }

    return 0;
}