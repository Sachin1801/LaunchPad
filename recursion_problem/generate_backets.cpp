#include <iostream>
using namespace std;

void generate_outputs(string out, int n, int open, int close, int i)
{
    // base case
    if (i == 2 * n)
    {
        cout << out << endl;
        return;
    }

    // rec case
    if (open < n) // adding an opening bracket
    {
        generate_outputs(out + '(', n, open + 1, close, i + 1);
    }

    if (close < open) // adding a closing bracket
    {
        generate_outputs(out + ')', n, open, close + 1, i + 1);
    }
}

int main()
{
    string output;
    int n;
    cin >> n;

    generate_outputs(output, n, 0, 0, 0);

    return 0;
}