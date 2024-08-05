class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0, curr = 0;
        if (n <= 1) return n;
        for (int i = 0; i < n - 1; ++i) {
            int k = nums[i + 1] - nums[i];
            if (k <= 1) {
                curr += k;
            } else {
                curr = 0;
            }
            ans = max(ans, curr);
        }
        return ans + 1;
    }
};