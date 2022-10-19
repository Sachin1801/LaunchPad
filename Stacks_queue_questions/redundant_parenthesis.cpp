#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool redundant_parenthesis(string s)
{
    stack<char> st;

    for (auto c : s)
    {
        char ch = c;
        if (ch != ')')
            st.push(ch);
        else
        {
            bool operator_found = false;
            while (!st.empty() and st.top() != '(')
            {
                char top = st.top();
                if (top == '+' or top == '-' or top == '*' or top == '/')
                    operator_found = true;

                st.pop();
            }
            st.pop();
            if (operator_found == false)
                return true;
        }
    }
    return false;
}

int main()
{
    string s;
    cin >> s;

    if (!redundant_parenthesis(s))
        cout << "Yes it is valid" << endl;
    else
        cout << "No it is not valid" << endl;

    return 0;
}