class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int n = strs.size(), k = 0;
        if ( n == 1 )
            return strs[0];
        int min_length = INT_MAX;
        do {
            for(int i = 0; i < n; ++i) {
                int l = strs[i].length();
                if ( k == 0 && l < min_length )
                    min_length = l;
                if ( l == 0 || l < k )
                    return ans;
                else if ( strs[i][k] != strs[0][k] )
                    return ans;
            }
            ans += strs[0][k];
            ++k;
        } while( k < min_length );
        return ans;
    }
};