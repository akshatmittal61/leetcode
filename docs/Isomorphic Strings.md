https://leetcode.com/problems/isomorphic-strings/

# Approach 1

1. Creating mapping for characters from one string to another.
2. Make sure the mapping is back and forth.
3. Generate new strings from the old string and the new mapping.
4. Check if the mapped strings and the desired results are equal.
5. Return `true` if so, else return `false`.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(n)$

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        map<char, char> p, q;
        for (int i = 0; i < n; ++i)
        {
            p[s[i]] = t[i];
            q[t[i]] = s[i];
        }
        string a = s, b = t;
        for (int i = 0; i < n; ++i)
        {
            a[i] = p[s[i]];
            b[i] = q[t[i]];
        }
        return a == t && b == s;
    }
};
```