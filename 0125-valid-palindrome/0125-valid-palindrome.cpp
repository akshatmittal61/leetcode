class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for (char c: s) {
            if ( c >= 'a' && c <= 'z' ) {
                str += c;
            } else if ( c >= 'A' && c <= 'Z' ) {
                str += (c - 'A' + 'a');
            } else if ( c >= '0' && c <= '9' ) {
                str += c;
            }
        }
        int n = str.length();
        for (int i = 0, j = n - 1; i < j; ++i, --j) {
            if ( str[i] != str[j] ) {
                return false;
            }
        }
        return true;
    }
};