class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int leaps = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                ++leaps;
            }
        }
        if (leaps == 0) return true;
        if (leaps == 1) {
            if (nums[0] >= nums[n - 1]) return true;
            else return false;
        }
        return false;
    }
};