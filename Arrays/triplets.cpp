#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> triplets(vector<int> arr, int target)
{
    int n = arr.size();
    vector<vector<int>> Ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i <= n - 3; i++)
    {
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int cs = arr[i];
            cs += arr[j];
            cs += arr[k];
            if (cs == target)
            {
                Ans.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;
                break;
            }
            else if (cs < target)
            {
                j++;
            }
            else if (cs > target)
            {
                k--;
            }
        }
    }
    return Ans;
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
    int key;
    cin >> key;
    vector<vector<int>> ans = triplets(arr, key);
    for (auto x : ans)
    {
        for (auto no : x)
        {
            cout << no << ",";
        }
        cout << endl;
    }
    return 0;
}