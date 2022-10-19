#include <iostream>
using namespace std;

void print_substring(char in[], int i, char out[], int j)
{
    // base case
    if (in[i] == '\0')
    {
        out[j] = '\0';
        if (out[0] == '\0')
        {
            cout << "NULL" << endl;
            return;
        }

        cout << out << endl;
        return;
    }

    // rec case
    // include the current char
    out[j] = in[i];
    print_substring(in, i + 1, out, j + 1);
    // exclude the current char
    print_substring(in, i + 1, out, j);
}

int main()
{
    char arr[100];
    cin >> arr;
    char output[100];
    print_substring(arr, 0, output, 0);

    return 0;
}