https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

# Approach 1

1. Iterate on the complete array.
2. If the next element is greater than previous element, add it as profit.
3. Return the max profit.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(1)$

```cpp
class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int i = 1; i < n; ++i) {
            if( nums[i] > nums[i - 1] )
                ans += nums[i] - nums[i - 1];
        }
        return ans;
    }
};
```