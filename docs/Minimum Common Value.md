https://leetcode.com/problems/minimum-common-value

# Approach 1

1. Use two pointers, one for each vector.
2. Start iterating on both together till you reach the end of any one.
3. If 2 same values are encountered, return it.
4. Else increment the pointer of vector with smaller value.
5. If no value is found, return `-1`.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(1)$

```cpp
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int i = 0, j = 0;
        while ( i < m && j < n ) {
            if ( nums1[i] == nums2[j] )
                return nums1[i];
            else if ( nums1[i] > nums2[j] )
                ++j;
            else
                ++i;
        }
        return -1;
    }
};
```