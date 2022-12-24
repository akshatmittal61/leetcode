class Solution
{
    public:
        vector<int> twoSum(vector<int> &nums, int target)
        {
            int n = nums.size();
            vector<int> ans(2);
            map<int, int> m;
            for (int i = 0; i < n; ++i)
            {
                int k = target - nums[i];
                if (m.find(k) != m.end())
                {
                    ans[0] = m[k];
                    ans[1] = i;
                    return ans;
                }
                m[nums[i]] = i;
            }
            return ans;
        }
};