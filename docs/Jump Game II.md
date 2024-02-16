https://leetcode.com/problems/jump-game-ii

# Approach 1

1. Update the array to contain the maximum reachable state from every index.
2. Also consider that if any earlier value has higher reach-ability, then the current index's reach-ability is already amplified to that point.
3. Now make longest possible jumps from every index, and start every next jump from the earlier point.
4. When you are on the last index or beyond it, that means you have used maximum number of jumps required.
5. Return the count of max no. of jumps.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(1)$

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        for( int i = 1; i < n; ++i ) {
            nums[i] = max(i + nums[i], nums[i - 1]);
        }
        int k = 0, ans = 0;
        while( k < n - 1 ) {
            ++ans;
            k = nums[k];
        }
        return ans;
    }
};
```