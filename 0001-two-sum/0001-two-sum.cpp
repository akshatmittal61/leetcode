class Solution
{
    public:
        vector<int> twoSum(vector<int> &nums, int target)
        {
            int n = nums.size();
            vector<int> ans(2);
           	// sort(nums.begin(), nums.end());
           	// int beg = 0, end = n - 1;
           	// while (beg < end)
           	// {
           	//     if (nums[beg] + nums[end] == target)
           	//     {
           	//         ans[0] = beg, ans[1] = end;
           	//         return ans;
           	//     }
           	//     else if (nums[beg] + nums[end] > target) --end;
           	//     else ++beg;
           	// }
            for (int i = 0; i < n; ++i)
            {
                for (int j = i + 1; j < n; ++j)
                    if (nums[i] + nums[j] == target)
                    {
                        ans[0] = i, ans[1] = j;
                        return ans;
                    }
            }
            return ans;
        }
};