https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

# Approach 1

1. We will use two pointer approach
2. Create two pointers, $low$ and $high$ and initiate from both ends of array.
3. Keep iterating until $low$ is lesser than $high$.
4. If sum of $low$ and $high$ is equal to $target$, return both position indexes.
5. Else if sum is greater, then decrease the $high$ by $1$.
6. Else increment the $low$.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(1)$

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while ( low < high ) {
            if ( nums[low] + nums[high] == target )
                return {low + 1, high + 1};
            else if ( nums[low] + nums[high] > target )
                --high;
            else
                ++low;
        }
        return {-1, -1};
    }
};
```