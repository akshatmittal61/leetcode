class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, vector<int>> m;
        for (int i = 0; i < n; ++i) {
            if (m[nums[i]].size() > 0) {
                for(auto x: m[nums[i]]) {
                    if ( abs(x - i) <= k )
                        return true;
                }
            }
            m[nums[i]].push_back(i);
        }
        return false;
    }
};