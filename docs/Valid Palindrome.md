https://leetcode.com/problems/valid-palindrome

# Approach 1

1. Create and empty string $str$, we will use this as the sanitized string.
2. Iterate on the original string.
3. Append only alpha-numeric characters to $str$.
4. For uppercase change them to lowercase characters.
5. Put two pointers $i$ and $j$ on sanitized string on both ends.
6. Start matching both characters.
7. Bring two pointers closer to each other at every step.
8. If any character is not matched, return $false$.
9. If all the characters are matched, return $true$.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(n)$

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for (char c: s) {
            if ( c >= 'a' && c <= 'z' ) {
                str += c;
            } else if ( c >= 'A' && c <= 'Z' ) {
                str += (c - 'A' + 'a');
            } else if ( c >= '0' && c <= '9' ) {
                str += c;
            }
        }
        int n = str.length();
        for (int i = 0, j = n - 1; i < j; ++i, --j) {
            if ( str[i] != str[j] ) {
                return false;
            }
        }
        return true;
    }
};
```

# Approach 2

1. Omit the second string, sanitation of characters can happen on the fly.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(1)$

```cpp
class Solution {
    char getChar(char c) {
        if ( c >= 'a' && c <= 'z' ) {
            return c;
        } else if ( c >= 'A' && c <= 'Z' ) {
            return (c - 'A' + 'a');
        } else if ( c >= '0' && c <= '9' ) {
            return c;
        }
        return '-';
    }
public:
    bool isPalindrome(string s) {
        int n = s.length();
        for (int i = 0, j = n - 1; i < j;) {
            char a = getChar(s[i]);
            char b = getChar(s[j]);
            cout<<a<<':'<<b<<endl;
            if ( a == '-' && b == '-' ) {
                ++i, --j;
                continue;
            } else if ( a == '-' ) {
                ++i;
                continue;
            } else if ( b == '-' ) {
                --j;
                continue;
            } else {
                ++i, --j;
                if ( a != b ) {
                    return false;
                }
            }
        }
        return true;
    }
};
```