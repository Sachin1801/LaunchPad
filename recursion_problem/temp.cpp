vector<long> ans(red.size(), 0);
int prev = 0;

for (int i = 0; i < red.size(); i++)
{
    if (prev == 0)
    {
        if (red[i] < blue[i] + bc)
        {
            prev = 0;
            ans[i + 1] = red[i];
        }
        else if (red[i] == blue[i] + bc)
        {
            prev = 2;
            ans[i + 1] = blue[i] + bc;
        }
        else
        {
            prev = 1;
            ans[i + 1] = blue[i] + bc;
        }
    }
    else if (prev == 1)
    {
        if (red[i] < blue[i])
        {
            prev = 0;
            ans[i + 1] = red[i];
        }
        else if (red[i] == blue[i])
        {
            prev = 2;
            ans[i + 1] = blue[i];
        }
        else
        {
            prev = 1;
            ans[i + 1] = blue[i];
        }
    }
    else
    {
        if (red[i] < blue[i])
        {
            prev = 0;
            ans[i + 1] = red[i];
        }
        else if (red[i] == blue[i])
        {
            prev = 2;
            ans[i + 1] = blue[i];
        }
        else
        {
            prev = 1;
            ans[i + 1] = blue[i];
        }
    }
    if (i != 0)
    {
        ans[i + 1] += ans[i];
    }
}
return ans;
