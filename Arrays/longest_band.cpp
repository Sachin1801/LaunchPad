#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int longestchain(vector<int> arr)
{
    int lc = 1;
    unordered_set<int> s;
    for (int x : arr)
    {
        s.insert(x);
    }
    for (auto element : s)
    {
        int parent = element - 1;
        if (s.find(parent) == s.end())
        {
            // find entire band
            int cnt = 1;
            int next_no = element + 1;
            while (s.find(next_no) != s.end())
            {
                next_no++;
                cnt++;
            }
            lc = max(lc, cnt);
        }
    }
    return lc;
}

int main()
{
    vector<int> arr{1, 9, 0, 15, 5, 2, 4, 3, 10, 7, 12, 6};
    cout << longestchain(arr);

    return 0;
}