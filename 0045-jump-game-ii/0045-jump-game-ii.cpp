class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        for( int i = 1; i < n; ++i ) {
            nums[i] = max(i + nums[i], nums[i - 1]);
        }
        int k = 0, ans = 0;
        while( k < n - 1 ) {
            ++ans;
            k = nums[k];
        }
        return ans;
    }
};