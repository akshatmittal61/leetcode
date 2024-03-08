class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> m;
        for ( auto x: nums ) {
            m[x]++;
        }
        int k = INT_MIN;
        for ( auto it: m ) {
            k = max(k, it.second);
        }
        int ans = 0;
        for ( auto it: m ) {
            if (it.second == k) {
                ans += k;
            }
        }
        return ans;
    }
};