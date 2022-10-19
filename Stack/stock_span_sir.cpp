#include <iostream>
#include <stack>
using namespace std;

void spancal(int prices[], int n, int span[])
{
    stack<int> s;
    s.push(0);
    span[0] = 1;

    // loop for the rest of the days
    for (int i = 1; i < n; i++)
    {
        int currentprice = prices[i];

        while (!s.empty() and prices[s.top()] <= currentprice)
        {
            s.pop();
        }

        if (!s.empty())
        {
            int prevhighest = s.top();
            span[i] = i - prevhighest;
        }
        else
        {
            span[i] = i + 1;
        }

        s.push(i);
    }
}

int main()
{
    int prices[] = {100, 80, 60, 70, 60, 75, 185};
    int n = sizeof(prices) / sizeof(int);
    int span[100000] = {0};

    spancal(prices, n, span);

    for (int i = 0; i < n; i++)
    {
        cout << span[i] << " ";
    }

    return 0;
}