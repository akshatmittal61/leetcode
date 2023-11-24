#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;
    int j = 0;
    ans.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++)
    {
        if (ans[j][1] >= intervals[i][0])
        {
            ans[j][1] = max(ans[j][1], intervals[i][1]);
        }
        else
        {
            ans.push_back(intervals[i]);
            j++;
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> ans = merge(intervals);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    return 0;
}