class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> m;
        int k = INT_MIN;
        for ( auto x: nums ) {
            m[x]++;
            if ( m[x] > k ) {
                k = m[x];
            }
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