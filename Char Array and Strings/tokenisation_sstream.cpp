#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    getline(cin, s);

    stringstream ss(s); // this is the function that separates all the strings by itself
    vector<string> tokens;
    // to temp store the strings read by stringstream

    string token;
    while (ss >> token) //
    {
        tokens.push_back(token);
    }
    for (auto t : tokens)
    {
        cout << t << ",";
    }
    return 0;
}