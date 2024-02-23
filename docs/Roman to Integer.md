https://leetcode.com/problems/roman-to-integer

# Approach 1

1. Create a hashmap to store the indexing of every roman character to its integer.
2. Start iterating on the roman string.
3. According to the Roman integer rules, if the next character is smaller than the current character, subtract the current character from the next character and add the result to the answer.
4. Else, just add the integer of current character to the result.
5. Return the final result.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(1)$

```cpp
class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            if( i < n - 1 && m[s[i]] < m[s[i + 1]] ) {
                ans += m[s[i + 1]] - m[s[i]];
                ++i;
            } else {
                ans += m[s[i]];
            }
        }
        return ans;
    }
};
```