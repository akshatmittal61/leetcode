https://leetcode.com/problems/best-time-to-buy-and-sell-stock

# Approach 1

1. Declare two tracking variables, `min` and `profit`.
2. Update `min` to minimum of `min` and current number.
3. If current profit is greater than `profit`, update `profit` to the current profit.
4. Return the `profit`.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(1)$

```cpp
class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int mn = nums[0], pf = 0;
        for(int i = 0; i < n; ++i) {
            if( nums[i] < mn )
                mn = nums[i];
            if( nums[i] - mn > pf)
                pf = nums[i] - mn;
        }
        return pf;
    }
};
```
