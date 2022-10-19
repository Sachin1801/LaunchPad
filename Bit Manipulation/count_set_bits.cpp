#include <iostream>
using namespace std;

void count_set_bits(int a)
{
    int cnt = 0;
    while (a != 0)
    {
        cnt += a & 1;
        a = a >> 1;
    }
    cout << cnt << endl;
    return;
}

int main()
{
    int a;
    cin >> a;
    count_set_bits(a);
    return 0;
}
