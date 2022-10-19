#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> ans;

void solve(vector<int> v, int k)
{
    deque<int> q(k);
    // 1.Only process the first k elements
    int i;
    for (i = 0; i < k; i++)
    {
        while (!q.empty() and v[i] > v[q.back()])
        {
            q.pop_back();
        }
        q.push_back(i);
    }

    // 2. Process the remaining elements in the array
    for (; i < v.size(); i++)
    {
        cout << v[q.front()] << " ";
        while (!q.empty() && q.front() <= i - k)
        {
            q.pop_front();
        }
        while (!q.empty() and v[i] >= v[q.back()])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
}

int main()
{
    vector<int> v = {1, 2, 3, 1, 4, 5, 2, 3, 5};
    int k = 3;

    solve(v, k);

    return 0;
}