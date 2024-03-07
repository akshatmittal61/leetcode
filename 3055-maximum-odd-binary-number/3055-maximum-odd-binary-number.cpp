class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        int no = 0;
        for ( int i = 0; i < n; ++i ) {
            if ( s[i] == '1' )
                ++no;
        }
        for ( int i = 0; i < no - 1; ++i )
            s[i] = '1';
        for ( int i = no - 1; i < n - 1; ++i )
            s[i] = '0';
        s[n - 1] = '1';
        return s;
    }
};