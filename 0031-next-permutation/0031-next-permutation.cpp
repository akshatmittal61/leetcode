class Solution
{
    public:
        void nextPermutation(vector<int> &nums)
        {
            int n = nums.size();
            if (n == 1) return;
            else if (n == 2)
            {
                swap(nums[0], nums[1]);
                return;
            }
            int i = n - 1;
            while (i > 0 && nums[i] <= nums[i - 1])
                --i;
            int flag = i - 1;
            if (i == 0)
            {
                sort(nums.begin(), nums.end());
                return;
            }
            sort(nums.begin() + flag + 1, nums.end());
            for (int j = flag; j < n; ++j)
            {
                if (nums[j] > nums[flag])
                {
                    swap(nums[j], nums[flag]);
                    return;
                }
            }
        }
};