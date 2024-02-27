class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), ans = 0;
        if ( n <= 1 )
            return n;
        if ( n == 2 )
            return s[0] == s[1] ? 1 : 2;
        int i = 0, j = 1;
        int v[26] = {0};
        v[s[0]-'a']++;
        v[s[1]-'a']++;
        while ( j < n - 1 ) {
            bool check = true;
            for ( int k = i; k <= j; ++k ) {
                if ( v[s[k] - 'a'] > 1 ) {
                    check = false;
                    break;
                }
            }
            cout<<s<<' '<<i<<':'<<j<<';';
            if ( check ) {
                ans = max(ans, j - i + 1);
                ++j;
                v[s[j] - 'a']++;
            } else {
                if ( i < j ) {
                    ++i;
                    v[s[i - 1] - 'a']--;
                } else {
                    ++j;
                    v[s[j] - 'a']++;
                }
            }
            cout<<i<<':'<<j<<endl;
        }
        return ans;
    }
};