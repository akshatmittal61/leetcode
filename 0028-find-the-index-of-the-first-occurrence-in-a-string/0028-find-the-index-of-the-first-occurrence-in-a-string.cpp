class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.length(), n = needle.length();
        int v[n][h];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < h; ++j) {
                if ( haystack[j] == needle[i] )
                    v[i][j] = 1;
                else
                    v[i][j] = 0;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < h; ++j) {
                cout<<v[i][j]<<' ';
            }
            cout<<endl;
        }
        for (int i = 0; i < h; ++i) {
            int c = 0;
            int j = 0, k = i;
            while( j < n && k < h && v[j][k] == 1 )
                ++c, ++j, ++k;
            cout<<i<<' '<<c<<endl;
            if (c == n)
                return i;
        }
        return -1;
    }
};