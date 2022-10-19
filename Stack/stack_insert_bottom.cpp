#include <iostream>
#include <stack>
using namespace std;

// Insert at stack bottom
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

int main()
{

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    insert_at_bottom(s, 5);

    print(s);

    return 0;
}