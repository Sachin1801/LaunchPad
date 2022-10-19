#include <iostream>
#include <vector>

using namespace std;

int housing(int p[], int n, int k)
{
    int mine = INT_MAX;
    int tsum = 0;
    int i = 0, j = 0;
    while (j < n)
    {
        // expnad to right
        tsum += p[j];
        j++;

        // to close the window from the left
        while (tsum > k and i < j)
        {
            tsum = tsum - p[i];
            i++;
        }
        // if we get the required sum
        if (tsum == k)
        {
            if ((j - i - 1) < mine)
            {

                mine = min((j - i), mine);
            }
        }
    }
    return mine;
}

int main()
{
    int plots[] = {1, 3, 2, 1, 4, 1, 3, 2, 1, 1};
    int n = sizeof(plots) / sizeof(int);
    int k = 8;

    cout << housing(plots, n, k);
    return 0;
}