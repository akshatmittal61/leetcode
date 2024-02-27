https://leetcode.com/problems/longest-substring-without-repeating-characters

# Approach 1

1. Create 2 pointers, $i$ and $j$ to keep track of starting and ending points of the current sub-string, put them at first & second characters respectively.
2. Also create $ans$ variable to keep track of longest possible sub-string.
3. Initiate it by $2$ if both the first characters are equal else by $1$.
4. Create a array which tracks the count of each character in the current sub-string, $v$.
5. Initiate it by the count of first two characters, since $i$ and $j$ are at those position right now.
6. Start iterating on the string.
7. For each iteration,
	1. Check if any character is repeated or the next character in the string is already in the current sub-string.
	2. If none of the above condition is true, then our next character is most welcome to be appended in the current sub-string.
	3. To do that, increment the $j$ pointer and increase the count of $j^{th}$ character in the $v$ array by 1.
	4. Else, check if $i$ and $j$ are at the same position.
	5. If so, then just increment both of them by $1$ and update the count in $v$, by decrementing count of previous $i^{th}$ and incrementing the count of new $j^{th}$ character.
	6. After all the processing, update the $ans$ with the length of current sub-string if required to get the max length.
8. Return the $ans$.
9. Handle the base cases in starting.
	1. If the string is empty return 0, no sub-string can be clipped out.
	2. If the string has only 1 character, return that, that character itself satisfies the situation.
	3. If the string only has 2 characters, it will only satisfy the situation if both of them are equal, return `1` else return `0`.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(1)$

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if ( n <= 1 )
            return n;
        if ( n == 2 )
            return s[0] == s[1] ? 1 : 2;
        int i = 0, j = 1;
        int ans = s[0] == s[1] ? 1 : 2;
        int v[255] = {0};
        v[ int(s[0]) ]++;
        v[ int(s[1]) ]++;
        while ( j < n - 1 ) {
            bool check = true;
            for ( int k = i; k <= j; ++k ) {
                if ( s[j + 1] == s[k] || v[ int(s[k]) ] > 1 ) {
                    check = false;
                    break;
                }
            }
            if ( check ) {
                ++j;
                v[ int(s[j]) ]++;
            } else {
                if ( i < j ) {
                    ++i;
                    v[ int(s[i - 1]) ]--;
                } else {
                    ++i, ++j;
                    v[ int(s[j]) ]++;
                    v[ int(s[i - 1]) ]--;
                }
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
```