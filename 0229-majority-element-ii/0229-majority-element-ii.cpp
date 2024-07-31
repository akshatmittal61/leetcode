class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int> m;
        vector<int> ans;
        int n = nums.size();
        for(auto x: nums) {
            m[x]++;
        }
        for(auto it: m) {
            if(it.second > ceil(n / 3 )) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};