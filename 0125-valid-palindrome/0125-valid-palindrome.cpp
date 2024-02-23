class Solution {
    char getChar(char c) {
        if ( c >= 'a' && c <= 'z' ) {
            return c;
        } else if ( c >= 'A' && c <= 'Z' ) {
            return (c - 'A' + 'a');
        } else if ( c >= '0' && c <= '9' ) {
            return c;
        }
        return '-';
    }
public:
    bool isPalindrome(string s) {
        int n = s.length();
        for (int i = 0, j = n - 1; i < j;) {
            char a = getChar(s[i]);
            char b = getChar(s[j]);
            cout<<a<<':'<<b<<endl;
            if ( a == '-' && b == '-' ) {
                ++i, --j;
                continue;
            } else if ( a == '-' ) {
                ++i;
                continue;
            } else if ( b == '-' ) {
                --j;
                continue;
            } else {
                ++i, --j;
                if ( a != b ) {
                    return false;
                }
            }
        }
        return true;
    }
};