https://leetcode.com/problems/longest-common-prefix

# Approach 1

1. Put a pointer $k$ on the column of matrix and a string $ans$ to store the longest common prefix.
2. During $1^{st}$ iteration, calculate the minimum length of all strings. Only continue iterations till that number.
3. In $k^{th}$ iteration, check for $k^{th}$ alphabet in all strings.
4. If at any point, either the length of string has been exhausted, or the $k^{th}$ character of$i^{th}$ is not the same as the $k^{th}$ character of $1^{st}$ string, then we have got the longest possible prefix, return it.
5. If that character is same in all the strings, at the end of the iteration, append it to $ans$.
6. Base Case: Check if array only contains 1 string, if yes, then return it directly.

**Time Complexity**: $O(n^2)$
**Space Complexity**: $O(1)$

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int n = strs.size(), k = 0;
        if ( n == 1 )
            return strs[0];
        int min_length = INT_MAX;
        do {
            for(int i = 0; i < n; ++i) {
                int l = strs[i].length();
                if ( k == 0 && l < min_length )
                    min_length = l;
                if ( l == 0 || l < k )
                    return ans;
                else if ( strs[i][k] != strs[0][k] )
                    return ans;
            }
            ans += strs[0][k];
            ++k;
        } while( k < min_length );
        return ans;
    }
};
```