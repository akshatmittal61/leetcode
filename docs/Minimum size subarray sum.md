https://leetcode.com/problems/minimum-size-subarray-sum

# Approach 1

1. Use sliding window approach
2. Create two pointers, $beg$ and $end$.
3. Create two variables $sum$ to track sum of a window and $ans$ to track minimum length.
4. Iterate till $end$ can reach the length of the array.
5. Add the rear element to sum.
6. If the sum of the current window satisfies the condition and length of window is smaller than $ans$, replace it, remove the $front$ element from current sum and increment the $front$
7. Repeat the above till $front$ reaches the $rear$ and the sum of window remains bigger than target.
8. If the $front$ can't move any further, increment the $rear$.
9. After the iteration, if the $ans$ has a valid value. return that else return $0$.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(1)$

```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int beg = 0, end = 0, sum = 0, ans = n + 1;
        while( end < n ) {
            sum += nums[end];
            while ( beg <= end && sum >= target ) {
                int k = end - beg + 1;
                if ( k < ans )
                    ans = k;
                sum -= nums[beg];
                ++beg;
            }
            ++end;
        }
        if ( ans == n + 1 )
            return 0;
        else
            return ans;
    }
};
```