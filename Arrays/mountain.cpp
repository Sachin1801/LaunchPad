#include <iostream>
#include <vector>
using namespace std;

int mountain(vector<int> arr)
{
    int maxpeak = 0;
    int n = arr.size();
    for (int i = 1; i < n - 1; i++)
    {
        int ans = 0;
        if (arr[i] > arr[i + 1] and arr[i] > arr[i - 1])
        {
            int k = i;
            // count backwards
            while (arr[k - 1] < arr[k] and k >= 1)
            {
                ans++;
                k--;
            }
            k = i;
            while (arr[k + 1] < arr[k] and k <= n - 2) // could be a istake the last part k<=n-2
            {
                ans++;
                k++;
            }
            ans++;
            i = k;
        }
        maxpeak = max(ans, maxpeak);
    }
    return maxpeak;
}

int main()
{
    vector<int> arr{5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};
    cout << mountain(arr) << endl;

    return 0;
}