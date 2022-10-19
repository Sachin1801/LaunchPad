#include <iostream>
using namespace std;

// brute force O(n^3)
int brute_largest_sum(int arr[], int n)
{
    int largestsum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int subarraysum = 0;
            for (int k = i; k <= j; k++)
            {
                subarraysum += arr[k];
            }
            largestsum = max(largestsum, subarraysum);
        }
    }
    return largestsum;
}

// Prefix sums
int largest_sum2(int arr[], int n)
{
    int prefix[100] = {0};
    prefix[0] = arr[0];
    // top compute prefix sum array
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    int largestsum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int subarraysum = i > 0 ? prefix[j] - prefix[i - 1] : prefix[j];
            largestsum = max(largestsum, subarraysum);
        }
    }
    return largestsum;
}

int main()
{
    int arr[] = {-2, 4, 3, -1, 5, -12, -5, 6, 2};
    int n = sizeof(arr) / sizeof(int);

    cout << brute_largest_sum(arr, n) << endl;
    cout << largest_sum2(arr, n);
    return 0;
}