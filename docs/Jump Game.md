https://leetcode.com/problems/jump-game

# Approach 1

1. If array is of size 1, return true, you are already at last index.
2. Create a trackable variable, $k$.
3. For every position, calculate the maximum reachable distance from that point.
4. If there is a number which is not last index, is $0$ and is beyond current maximum reachable, return $false$.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(1)$

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), k = 0;
        if(n == 1)
            return true;
        for( int i = 0; i < n; ++i ) {
            k = max(k, i + nums[i]);
            if( nums[i] == 0 && k <= i && i != n - 1 ) {
                return false;
            }
        }
        return k >= n - 1;
    }
};
```