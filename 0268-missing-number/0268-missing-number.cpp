class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        for(int i = 0; i < n; ++i) {
            x = x ^ nums[i];
        }
        for(int i = 0; i <= n; ++i) {
            x = x ^ i;
        }
        return x;
    }
};