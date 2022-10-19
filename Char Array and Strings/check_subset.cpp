#include <iostream>
#include <cstring>
using namespace std;

int main()
{

    string s1;
    string s2;
    getline(cin, s1);
    getline(cin, s2);

    int i = s1.length() - 1, j = s2.length() - 1;
    while (i >= 0 and j >= 0)
    {
        if (s1[i] == s2[j])
        {
            i--;
            j--;
        }
        else
        {
            i--;
        }
    }
    if (j == -1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}