class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int n=strs.size();
        unsigned long m=strs[0].length();
        for(int i=0;i<n;++i) m = min(m, strs[i].length());
        int k=0;
        for(int j=0;j<m; ++j) {
            for(int i=0;i<n;++i) {
                if (strs[0][k] == strs[i][k])continue;
                else return ans;
            }
            ans += strs[0][k++];
        }
        return ans;
    }
};