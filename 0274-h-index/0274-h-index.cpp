class Solution {
public:
    int hIndex(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            if( nums[0] >= 1 )
                return 1;
            return 0;
        }
        sort(nums.begin(), nums.end());
        for(int i = n - 1; i >= 0; --i) {
            if( nums[i] >= n - i )
                continue;
            else {
                if( i == n - 1 ) return 0;
                return min(nums[i + 1], n - i - 1);
            }
        }
        return min(nums[0], n);
    }
};