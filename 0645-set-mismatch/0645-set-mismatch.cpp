class Solution
{
    public:
        vector<int> findErrorNums(vector<int> &nums)
        {
            int n = nums.size();
            vector<int> ans(2);
            sort(nums.begin(), nums.end());
            for (int i = 0; i < n - 1; ++i)
            {
                if (nums[i] == nums[i + 1])
                {
                    ans[0] = nums[i];
                    break;
                }
            }
            int x = 0;
            for (int i = 0; i < n; ++i)
                x ^= nums[i];
            for (int i = 1; i <= n; ++i)
                x ^= i;
            x ^= ans[0];
            ans[1] = x;
            return ans;
        }
};