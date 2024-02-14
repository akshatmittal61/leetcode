class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int pos = 0, neg = 0;
        while( pos < n && neg < n ) {
            if(nums[pos] > 0 && nums[neg] < 0) {
                ans.push_back(nums[pos]);
                ans.push_back(nums[neg]);
                ++pos, ++neg;
            } else {
                while(nums[pos] < 0) ++pos;
                while(nums[neg] > 0) ++neg;
            }
        }
        return ans;
    }
};