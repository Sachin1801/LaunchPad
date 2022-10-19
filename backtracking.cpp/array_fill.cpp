#include <iostream>
using namespace std;

void print(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void array_fill(int *a, int i, int n, int val)
{
    // base case
    if (i == n)
    {
        // print array
        for (int j = 0; j < n; j++)
        {
            cout << a[j] << " ";
        }
        cout << endl;
        return;
    }

    // rec case
    a[i] = val;
    array_fill(a, i + 1, n, val + 1);
    // backtracking step
    a[i] = -1 * a[i];
    return;
}

int main()
{
    int n;
    cin >> n;
    int a[100];
    array_fill(a, 0, n, 1);
    print(a, n);

    return 0;
}