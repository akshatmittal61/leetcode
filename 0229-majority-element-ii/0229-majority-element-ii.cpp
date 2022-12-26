class Solution
{
    public:
        vector<int> majorityElement(vector<int> &nums)
        {
            int n = nums.size();
            int k = floor(n / 3);
            vector<int> ans;
            sort(nums.begin(), nums.end());
            for (int i = 0; i < n; ++i)
            {
                int c = 0;
                while (i < n - 1 && nums[i] == nums[i + 1]) ++c, ++i;
                if (c >= k) ans.push_back(nums[i]);
            }
            return ans;
        }
};