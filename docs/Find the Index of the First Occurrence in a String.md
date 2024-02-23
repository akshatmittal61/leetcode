https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

# Approach 1

1. Store the size of `haystack` in `h` and that of `needle` in `n`
2. Create a binary matrix of $m*n$ size.
3. Assign $1$ to cells where the characters match, and $0$ else.
4. Iterate on the first row, and check which diagonal is complete $1$.
5. Return index of that first index.
6. If nothing satisfies the condition, return $-1$.

**Time Complexity**: $O(n^2)$
**Space Complexity**: $O(n^2)$

```cpp
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
        for (int i = 0; i < h; ++i) {
            int c = 0;
            int j = 0, k = i;
            while( j < n && k < h && v[j][k] == 1 )
                ++c, ++j, ++k;
            if (c == n)
                return i;
        }
        return -1;
    }
};
```


# Approach 2

1. Omit the binary matrix.
2. Compare the characters of both strings on fly.

**Time Complexity**: $O(n^2)$
**Space Complexity**: $O(1)$

```cpp
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
```