class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length(), m = needle.length();
        if (m > n) return -1;
        if (m == n) return haystack == needle ? 0 : -1;
        int k = 0;
        for(int i = 0; i < n; ++i) {
            cout<<i<<' '<<k<<' ';
            if (haystack[i] == needle[k]) {
                ++k;
            } else {
                i = i - k;
                k = 0;
            }
            if (k == m) {
                return i - k + 1;
            }
            cout<<i<<' '<<k<<endl;
        }
        return -1;
    }
};