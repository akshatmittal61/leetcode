#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> nums)
{
    int z = 0;
    int mul = 1;
    int n = nums.size();
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
            z++;
        else
            mul *= nums[i];
    }
    vector<int> res(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        if (z > 1)
            res[i] = 0;
        else if (z == 1)
        {
            if (nums[i] == 0)
                res[i] = mul;
            else
                res[i] = 0;
        }
        else
            res[i] = mul / nums[i];
    }
    return res;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> res = productExceptSelf(nums);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}