#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> stockSpan(vector<int> v)
{
    // Write your code here. Do not modify the function or parameters.
    vector<int> ans;
    stack<int> s;
    s.push(0);
    ans.push_back(1);

    for (int i = 1; i < v.size(); i++)
    {
        while (!s.empty() and v[s.top()] < v[i])
        {
            s.pop();
        }
        if (s.empty())
            ans.push_back(i + 1);
        else
            ans.push_back(i - s.top());

        s.push(i);
    }
    return ans;
}

int main()
{
    vector<int> p = {100, 180, 60, 270, 60, 75, 85};
    vector<int> ans = stockSpan(p);

    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}