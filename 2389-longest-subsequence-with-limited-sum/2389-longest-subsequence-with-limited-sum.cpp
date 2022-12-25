class Solution
{
    public:
        int Size(vector<int> nums, int k)
        {
            int i = 0, n = nums.size();
            long long s = 0;
            for (i = 0; i < n; ++i)
            {
                if (nums[i] + s > k) return i;
                s += nums[i];
            }
            return i;
        }
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for (auto i: queries) ans.push_back(Size(nums, i));
        return ans;
    }
};