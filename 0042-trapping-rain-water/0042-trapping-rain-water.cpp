class Solution {
public:
    int trap(vector<int>& v) {
        int n = v.size(), ans = 0;
        int l = 0, r = n - 1;
        int lm = v[0], rm = v[n - 1];
        while(l < r) {
            if(v[l] < v[r]) {
                if(v[l] < lm) {
                    ans += min(lm, v[r]) - v[l];
                } else {
                    lm = v[l];
                }
                ++l;
            } else {
                if(v[r] < rm) {
                    ans += min(rm, v[l]) - v[r];
                } else {
                    rm = v[r];
                }
                --r;
            }
        }
        return ans;
    }
};