#include <iostream>
using namespace std;
// we need to count the number of alphabets , digist and spaces in a given sentence
int main()
{
    // read char one by one
    char ch;
    ch = cin.get();
    int alpha = 0, digits = 0, spaces = 0;
    while (ch != '\n')
    {
        if (ch >= '0' and ch <= '9')
        {
            digits++;
        }
        else if ((ch >= 'a' and ch <= 'z') or ch >= 'A' and ch <= 'Z')
        {
            alpha++;
        }
        else if (ch == ' ' or ch == '\t')
        {
            spaces++;
        }
        ch = cin.get();
    }
    cout << alpha << " " << digits << " " << spaces << endl;
    return 0;
}