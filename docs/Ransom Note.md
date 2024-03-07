https://leetcode.com/problems/ransom-note/

# Approach 1

1. Create two frequency arrays for both ransom and magazine.
2. Count the alphabets in both.
3. If the frequency of any character in magazine is less than that of ransom, return `false`.
4. If frequency of all characters satisfy the condition, return `true`.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(1)$

```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> r(26, 0);
        vector<int> m(26, 0);
        for (auto c: ransomNote) {
            r[c-'a']++;
        }
        for (auto c: magazine) {
            m[c-'a']++;
        }
        for ( int i = 0; i < 26; ++i ) {
            if ( m[i] < r[i] )
                return false;
        }
        return true;
    }
};
```