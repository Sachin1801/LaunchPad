#include <iostream>
using namespace std;

void find_subset(char *input, char *output, int i, int j)
{
    // base case
    if (input[i] == '\0')
    {
        output[j] = '\0';
        if (output[0] == '\0')
            cout << "NULL" << endl;
        cout << output << endl;
        return;
    }
    // recursive case
    // include the ith letter
    output[j] = input[i];
    find_subset(input, output, i + 1, j + 1);
    // exclude current letter
    find_subset(input, output, i + 1, j);
}

int main()
{
    char input[100];
    char output[100];

    cin >> input;
    find_subset(input, output, 0, 0);
    return 0;
}