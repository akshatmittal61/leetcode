https://leetcode.com/problems/length-of-last-word

# Approach 1

1. Create a pointer, $k$ at the end of string.
2. Decrease it until you reach the right-most character, this is to skip the trailing spaces.
3. Put a pointer $l$ at $k$ and decrease it till you find the first non-alphabet character or reach the left-most character.
4. Return the $k - l$.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(1)$

```cpp
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
```