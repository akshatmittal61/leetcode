https://leetcode.com/problems/remove-duplicates-from-sorted-array

# Approach 1

1. Iterate on array
2. Search until similar value is found
3. Replace the further values from that point

**Time Complexity**: $O(n)$
**Space Complexity**: $O(1)$

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), k = 0;
        for( int i = 0; i < n; ++i ) {
            int j = i;
            while( j < n && nums[j] == nums[i] )
                ++j;
            i = max(i, j - 1);
            nums[k++] = nums[i];
        }
        return k;
    }
};
```