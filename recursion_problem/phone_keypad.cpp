#include <iostream>
#include <cstring>
using namespace std;

string keypad[] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void phone_keypad(string in, string out, int i)
{
    // base case
    if (in[i] == '\0')
    {
        cout << out << endl;
        return;
    }

    // rec case

    int cd = in[i] - '0'; // cd - current digit

    if (cd == 0 or cd == 1)
    {
        phone_keypad(in, out, i + 1);
    }

    for (int k = 0; k < keypad[cd].size(); k++)
    {
        phone_keypad(in, out + keypad[cd][k], i + 1);
    }
    return;
}

int main()
{
    string input;
    cin >> input;

    string output;

    phone_keypad(input, output, 0);

    return 0;
}