class Solution {
public:
    bool isValid(char c) {
        if (c >= 'a' && c <= 'z') return true;
        else if (c >= 'A' && c <= 'Z') return true;
        else if (c >= '0' && c <= '9') return true;
        else return false;
    }
    bool isEqual(char a, char b) {
        if (a >= 'A' && a <= 'Z') a = char(a - 'A' + 'a');
        if (b >= 'A' && b <= 'Z') b = char(b - 'A' + 'a');
        return a == b;
    }
    bool isPalindrome(string s) {
        int n = s.length();
        for (int i = 0, j = n - 1; i < j;) {
            if (!isValid(s[i])) {
                ++i;
                continue;
            }
            if (!isValid(s[j])) {
                --j;
                continue;
            }
            if(!isEqual(s[i], s[j])) return false;
            ++i, --j;
        }
        return true;
    }
};