class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), k = 0;
        if(n == 1)
            return true;
        for( int i = 0; i < n; ++i ) {
            k = max(k, i + nums[i]);
            if( nums[i] == 0 && k <= i && i != n - 1 ) {
                return false;
            }
        }
        return k >= n - 1;
    }
};