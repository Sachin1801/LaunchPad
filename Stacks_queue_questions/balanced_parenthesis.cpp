#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool balanced(string st)
{
    stack<char> s;
    for (int i = 0; i < st.length(); i++)
    {
        char ch = st[i];
        if (ch == '{' or ch == '[' or ch == '(')
        {
            s.push(ch);
        }
        if (ch == '}' or ch == ')' or ch == ']')
        {
            if (s.top() == '(' and ch == ')')
                s.pop();
            else if (s.top() == '{' and ch == '}')
                s.pop();
            else if (s.top() == '[' and ch == ']')
                s.pop();
            else
                return false;
        }
    }
    if (s.empty())
        return true;

    return false;
}

int main()
{
    string s;
    cin >> s;

    if (balanced(s))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}