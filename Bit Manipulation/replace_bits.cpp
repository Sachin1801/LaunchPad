#include <iostream>
using namespace std;

void clearbitsInRange(int &n, int i, int j)
{
    int a = (~0) << (j + 1);
    int b = (1 << i) - 1;
    int mask = a | b;
    n = n & mask;
}

void replace_bits(int &a, int b, int i, int j)
{
    clearbitsInRange(a, i, j);
    int mask = (b << i);
    a = a | mask;
}

int main()
{
    int a = 15;
    int b = 2;
    int i, j;
    cin >> i >> j;

    replace_bits(a, b, i, j);
    cout << a << endl;
    return 0;
}