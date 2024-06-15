class Solution {
public:
    bool check(vector<int>& nums) {
        int turns = 0;
        int n = nums.size();
        for(int i = 1; i < n; ++i) {
            if(nums[i] < nums[i - 1]) {
                ++turns;
            }
        }
        if(turns == 0) return true;
        if(turns == 1) {
            return nums[n - 1] <= nums[0];
        }
        return false;
    }
};