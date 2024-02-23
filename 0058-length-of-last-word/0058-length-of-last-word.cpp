class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int k = n - 1;
        while( s[k] == ' ' ) --k;
        int l = k;
        for(l = k; l >= 0 && s[l] != ' '; --l);
        return k - l;
    }
};