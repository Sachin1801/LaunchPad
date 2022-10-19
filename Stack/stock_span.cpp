#include <iostream>
#include <stack>
using namespace std;

void spancal(int prices[], int n, int span[])
{
    stack<int> s;
    s.push(0);
    span[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (prices[s.top()] > prices[i])
        {
            span[i] = i - s.top();
            s.push(i);
        }
        else
        {
            while (prices[s.top()] < prices[i])
            {
                s.pop();
            }
            span[i] = i - s.top();
            s.push(i);
        }
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