#include <iostream>
#include <string>
using namespace std;

void replace_space(char *str)
{
    int space = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            space++;
        }
    }
    int k = strlen(str) + (2 * space);
    str[k] = '\0';
    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        if (str[i] == ' ')
        {
            str[k - 1] = '0';
            str[k - 2] = '2';
            str[k - 3] = '%';
            k = k - 3;
        }
        else
        {
            str[k - 1] = str[i];
            k--;
        }
    }
}

int main()
{
    char input[1000];
    cin.getline(input, 1000);
    replace_space(input);
    cout << input << endl;
    return 0;
}