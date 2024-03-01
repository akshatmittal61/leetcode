class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        int no = 0;
        for ( int i = 0; i < n; ++i ) {
            if ( s[i] == '1' )
                ++no;
        }
        string ans;
        for ( int i = 0; i < no - 1; ++i )
            ans += '1';
        for ( int i = 0; i < n - no; ++i )
            ans += '0';
        ans += '1';
        return ans;
    }
};