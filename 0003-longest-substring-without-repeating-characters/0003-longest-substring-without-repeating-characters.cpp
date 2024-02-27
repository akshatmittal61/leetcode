class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), ans = 1;
        if ( n <= 1 )
            return n;
        if ( n == 2 )
            return s[0] == s[1] ? 1 : 2;
        int i = 0, j = 1;
        int v[255] = {0};
        v[ int(s[0])]++;
        v[ int(s[1])]++;
        while ( j < n - 1 ) {
            bool check = true;
            for ( int k = i; k <= j; ++k ) {
                if ( s[j + 1] == s[k] || v[int(s[k])] > 1 ) {
                    check = false;
                    break;
                }
            }
            cout<<i<<':'<<j<<'-'<<check<<';';
            if ( check ) {
                ++j;
                v[int(s[j])]++;
            } else {
                if ( i < j ) {
                    ++i;
                    v[int(s[i - 1])]--;
                } else {
                    ++i, ++j;
                    v[int(s[j])]++;
                    v[int(s[i - 1])]--;
                }
            }
            ans = max(ans, j - i + 1);
            cout<<i<<':'<<j<<';'<<ans<<endl;
        }
        return ans;
    }
};