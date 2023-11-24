#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    map<int, int> m;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (m.find(target - nums[i]) != m.end())
        {
            ans.push_back(m[target - nums[i]]);
            ans.push_back(i);
            return ans;
        }
        m[nums[i]] = i;
    }
    return ans;
}

int main()
{
    vector<int> nums = {8, 7, 2, 5, 3, 1};
    int target = 9;
    vector<int> ans = twoSum(nums, target);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}