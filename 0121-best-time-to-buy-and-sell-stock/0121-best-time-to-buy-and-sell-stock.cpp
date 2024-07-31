class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int mn = nums[0], pf = 0;
        for(int i = 0; i < n; ++i) {
            if( nums[i] < mn )
                mn = nums[i];
            if( nums[i] - mn > pf)
                pf = nums[i] - mn;
        }
        return pf;
    }
};