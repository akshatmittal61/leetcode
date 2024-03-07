https://leetcode.com/problems/maximum-odd-binary-number/

# Approach 1

1. To form an odd number, we need a `1` at the end of string.
2. Count the number of `1s` and `0s` in the binary string.
3. Create an empty string `ans`.
4. To create the maximum number append all `1s` but 1 to `ans`.
5. Append all `0s` to it.
6. Append the last `1` to `ans` to ensure it is an odd number.
7. Return `ans`.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(n)$

```cpp
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        int no = 0;
        for ( int i = 0; i < n; ++i ) {
            if ( s[i] == '1' )
                ++no;
        }
        string ans;
        for ( int i = 0; i < no - 1; ++i )
            ans += '1';
        for ( int i = 0; i < n - no; ++i )
            ans += '0';
        ans += '1';
        return ans;
    }
};
```

# Approach 2

1. To reduce the space complexity, we don't need the `ans` string.
2. Since the length of both strings gonna be same, just overwrite the existing string.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(1)$

```cpp
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        int no = 0;
        for ( int i = 0; i < n; ++i ) {
            if ( s[i] == '1' )
                ++no;
        }
        for ( int i = 0; i < no - 1; ++i )
            s[i] = '1';
        for ( int i = no - 1; i < n - 1; ++i )
            s[i] = '0';
        s[n - 1] = '1';
        return s;
    }
};
```