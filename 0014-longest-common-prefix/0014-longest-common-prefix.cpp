class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size(), m = INT_MAX;
        string ans;
        for(int i = 0; i < n; ++i) {
            if(strs[i].length() < m) {
                m = strs[i].length();
            }
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n - 1; ++j) {
                if(strs[j][i] != strs[j + 1][i]) {
                    return ans;
                }
            }
            ans += strs[0][i];
        }
        return ans;
    }
};