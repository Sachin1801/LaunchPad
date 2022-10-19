#include <iostream>
#include <stack>
using namespace std;

void insert_at_bottom(stack<int> &s, int data)
{
    // base case
    if (s.empty())
    {
        s.push(data);
        return;
    }

    // rec case
    int t = s.top();
    s.pop();
    insert_at_bottom(s, data);
    s.push(t);
}

void print(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}

void reverse(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int t = s.top();
    s.pop();
    reverse(s);
    insert_at_bottom(s, t);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    reverse(s);

    print(s);

    return 0;
}