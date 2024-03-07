https://leetcode.com/problems/squares-of-a-sorted-array/

# Approach 1

1. Create a vector, `ans`.
2. Iterate on the original array and push the square of all values in `ans`.
3. Sort the `ans` vector.
4. Return `ans`.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(n)$

```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        for ( int x: nums ) {
            ans.push_back(x*x);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
```