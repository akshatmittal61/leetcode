class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.length(), n = needle.length();
        for (int i = 0; i < h; ++i) {
            int c = 0;
            int j = 0, k = i;
            while( j < n && k < h && haystack[k] == needle[j] )
                ++c, ++j, ++k;
            if (c == n)
                return i;
        }
        return -1;
    }
};