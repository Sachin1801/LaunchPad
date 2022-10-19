#include <iostream>
#include <vector>
using namespace std;

bool compare(string s1, string s2)
{
    if (s1.length() == s2.length())
    {
        return s1 < s2;
    }
    return s1.length() < s2.length();
}

void find_subset(char *input, char *output, int i, int j, vector<string> &v)
{
    // base case
    if (input[i] == '\0')
    {
        output[j] = '\0';
        v.push_back(output);
        cout << output << endl;
        return;
    }
    // recursive case
    // include the ith letter
    output[j] = input[i];
    find_subset(input, output, i + 1, j + 1, v);
    // exclude current letter
    find_subset(input, output, i + 1, j, v);
}

int main()
{
    char input[100];
    char output[100];
    vector<string> out;
    cin >> input;
    find_subset(input, output, 0, 0, out);

    sort(out.begin(), out.end(), compare);
    for (auto x : out)
    {
        cout << x << endl;
    }
    return 0;
}