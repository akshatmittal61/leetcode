https://leetcode.com/problems/reverse-words-in-a-string

# Approach 1

1. Create a vector of string $v$.
2. Iterate on the complete string.
3. If you encounter a space `' '`, skip it.
4. If you encounter an alphabet, create an empty string, and start appending the characters until you reach a space `' '`.
5. Now that a word has been stored inside the new string, push that in $v$.
6. After the complete iteration, start iterating on $v$ from the end and start appending every string in a new string $ans$ with a space `' '` at its end.
7. Return $ans$.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(n)$

```cpp
class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        int n = s.length();
        for(int i = 0; i < n; ++i) {
            if (s[i] == ' ') {
                continue;
            } else {
                string f;
                while( i < n && s[i] != ' ' ) {
                    f += s[i++];
                }
                v.push_back(f);
            }
        }
        string ans;
        int l = v.size();
        for(int i = l - 1; i >= 0; --i) {
            ans += v[i];
            if ( i != 0 ) {
                ans += ' ';
            }
        }
        return ans;
    }
};
```