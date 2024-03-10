https://leetcode.com/problems/intersection-of-two-arrays

# Approach 1

1. Sort both the arrays.
2. Keep two pointers on beginning of both arrays.
3. Start iterating on both.
4. If the number is same, append it in `ans`. 
5. Increment both pointer to reach a distinct value in their respective arrays.
6. If the number is not same, increment the pointer which has lower value.
7. Return `ans`.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(n)$

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int m = nums1.size(), n = nums2.size();
        int i = 0, j = 0;
        vector<int> ans;
        while ( i < m && j < n ) {
            if ( nums1[i] == nums2[j] )  {
                ans.push_back(nums1[i]);
                ++i, ++j;
                while ( i < m && nums1[i - 1] == nums1[i] )
                    ++i;
                while ( j < n && nums2[j - 1] == nums2[j] )
                    ++j;
            }
            else if ( nums1[i] > nums2[j] )
                ++j;
            else
                ++i;
        }
        return ans;
    }
};
```