https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/

# Approach 1

1. Create two pointers at both ends.
2. Start iterating on the string till the beginning pointer is less than ending pointer and the ends are same.
3. For every iteration, check if the letter is similar at both ends.
4. Till then, keep incrementing `i` or decrementing `j` till character is same.
5. Return the length `j - i + 1`.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(1)$

```cpp
class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        int i = 0, j = n - 1;
        while ( i < j && s[i] == s[j] ) {
            char c = s[i];
            while ( i <= j && s[i] == c ) ++i;
            while ( i <= j && s[j] == c ) --j;
        }
        return j - i + 1;
    }
};
```