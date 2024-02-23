https://leetcode.com/problems/zigzag-conversion

# Approach 1

![](https://www.toni-develops.com/external-files/assets/svg/zig-zag-pattern.svg)
![](https://www.toni-develops.com/external-files/assets/svg/zig-zag-pattern-2.svg)
All steps are for case of $numRows = 4$
1. In the first and last row, we are adding $2*(n-1)$ after every index, starting at 0. For e.g.) 0 -> 6 -> 12.
2. From the second to last second row, the following pattern is followed.
	1. Start from $i^{th}$ index, for example for $2^{nd}$ row, start from $1$.
	2. If going towards upwards, add $2*(n-i-1)$.
	3. Else add $2*i$.
	4. For example, in row $2^{nd}$, 1 -> 5 -> 7 -> 11 -> 13
3. At every iteration append it to $ans$.
4. Return $ans$.
5. Base Case: if $numRows$ is $1$, return the original string as such.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(n)$

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if ( numRows == 1 )
            return s;
        int n = s.length();
        string ans;
        for (int i = 0; i < numRows; ++i) {
            int j = i;
            bool up = true;
            while ( j < n ) {
                ans += s[j];
                if ( i == 0 || i == numRows - 1 ) {
                    j += 2 * (numRows - 1);
                } else {
                    if (up) {
                        j += (2 * ( numRows - i - 1 ));
                    } else  {
                        j += (2 * i);
                    }
                    up = !up;
                }
            }
        }
        return ans;
    }
};
```