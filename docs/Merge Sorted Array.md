https://leetcode.com/problems/merge-sorted-array/

# Approach 1

1. Append all `nums2` values in `nums1`.
2. Sort the `nums1`.

**Time Complexity**: $O(n*log(n))$
**Space Complexity**: $O(1)$

# Approach 2

1. Iterate on both arrays, 
2. When the smaller value is found in `nums2`, shift all the values of `nums1` by one. 
3. Insert the value of `nums2` in `nums1`'s new empty place.

**Time Complexity**: $O(n^2)$
**Space Complexity**: $O(1)$
# Approach 3

1. Create a new array `nums3`.
2. Use the 'Merge while sort' strategy for both arrays.
3. Replace the original `nums1` with the completed `nums3`.

**Time Complexity**: $O(m + n)$
**Space Complexity**: $O(m + n)$

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3(m+n, 0);
        int i = 0, j = 0, k = 0;
        while( i < m && j < n ) {
            if( nums1[i] >= nums2[j] ) {
                nums3[k++] = nums2[j++];
            } else {
                nums3[k++] = nums1[i++];
            }
        }
        while ( i < m ) {
            nums3[k++] = nums1[i++];
        }
        while ( j < n ) {
            nums3[k++] = nums2[j++];
        }
        nums1 = nums3;
    }
};
```