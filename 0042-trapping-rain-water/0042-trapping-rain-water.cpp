class Solution {
public:
    int trap(vector<int>& v) {
        int n = v.size(), ans = 0;
        vector<int> lm(n, 0), rm(n, 0);
        lm[0] = v[0], rm[n - 1] = v[n - 1];
        for(int i = 1, j = n - 2; i < n && j >= 0; ++i, --j) {
            lm[i] = max(lm[i - 1], v[i]);
            rm[j] = max(rm[j + 1], v[j]);
        }
        for(int i = 0; i < n; ++i) {
            int lr = min(lm[i], rm[i]);
            // add to ans, if any amount of water can be added
            ans += max(0, lr - v[i]);
        }
        return ans;
    }
};