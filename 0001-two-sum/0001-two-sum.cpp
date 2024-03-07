class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            int k = target - nums[i];
            if( m.find(k) != m.end() ) {
                return {i, m[k]};
            } else {
                m[nums[i]] = i;
            }
        }
        return {};
    }
};