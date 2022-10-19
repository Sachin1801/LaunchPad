#include <iostream>
#include <cstring>
using namespace std;

int len;

void permutations(char *in, int l, int r)
{
    // corner case
    if (l == r)
    {
        cout << in << endl;
        return;
    }
    // recursiv case
    for (int i = l; i <= r; i++)
    {
        swap(in[l], in[i]);
        permutations(in, l + 1, r);
        swap(in[l], in[i]);
    }
}

int main()
{
    char input[1000];
    cin >> input;
    len = strlen(input);
    cout << len << endl;
    permutations(input, 0, len - 1);

    return 0;
}