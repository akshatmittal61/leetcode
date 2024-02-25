class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int beg = 0, end = 0, sum = 0, ans = n + 1;
        while( end < n ) {
            sum += nums[end];
            while ( beg <= end && sum >= target ) {
                int k = end - beg + 1;
                if ( k < ans )
                    ans = k;
                sum -= nums[beg];
                ++beg;
            }
            ++end;
        }
        if ( ans == n + 1 )
            return 0;
        else
            return ans;
    }
};