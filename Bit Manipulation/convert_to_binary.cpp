#include <iostream>
using namespace std;

int converttobinary(int n)
{
    int temp = 1;
    int ans = 0;
    while (n > 0)
    {
        int last_bit = n & 1;
        ans = ans + (temp * last_bit);
        n = n >> 1;
        temp *= 10;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << converttobinary(n) << endl;
    return 0;
}