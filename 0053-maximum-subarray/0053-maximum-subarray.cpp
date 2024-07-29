class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int ans = INT_MIN, curr = 0;
        int n = v.size();
        for( int i = 0; i < n; ++i ) {
            curr += v[i];
            ans = max(ans, curr);
            curr = max(curr, 0);
        }
        return ans;
    }
};