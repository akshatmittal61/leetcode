https://leetcode.com/problems/valid-anagram/

# Approach 1

1. Create a frequency array.
2. Iterate on first string, and increment the frequency of every character.
3. Iterate on the second string, and decrement the frequency of every character.
4. Iterate on the frequency array, if every entry is not `0`, i.e.) the frequency of every character in the first string does not matches frequency of the second string, return `false`.
5. Else return `true`.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(1)$

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        int a[26] = {0};
        for( auto c: s ) a[c - 'a']++;
        for( auto c: t ) a[c - 'a']--;
        for( auto i: a ) {
            if( i != 0 )
                return false;
        }
        return true;
    }
};
```