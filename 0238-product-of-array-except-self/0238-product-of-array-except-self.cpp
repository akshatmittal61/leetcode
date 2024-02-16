class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long prod = 1;
        int zeroes = false, n = nums.size();
        for(int x: nums) {
            if( x == 0 ) ++zeroes;
            else prod *= x;
        }
        vector<int> ans;
        for(auto x: nums) {
            if(zeroes == n) {
                ans.push_back(0);
            } else {
                if(zeroes > 0) {
                    if(x == 0 && zeroes == 1)
                        ans.push_back(prod);
                    else
                        ans.push_back(0);
                } else {
                    ans.push_back(prod / x);
                }
            }
        }
        return ans;
    }
};