https://leetcode.com/problems/remove-element

# Approach 1

1. Create a new array `nums2`
2. Iterate on `nums`, and if value is not equal to `val`, push it in new array.
3. Fill the rest of the array till it reaches `n`.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(n)$

# Approach 2

1. Iterate on `nums`.
2. If value is equal to `val`, continue till the same value is found.
3. After that, place the next value.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(1)$

```cpp
int removeElement(vector<int>& nums, int val) {
	int n = nums.size(), k = 0;
	for ( int i = 0; i < n; ++i ) {
		while( i < n && nums[i] == val ) {
			++i;
		}
		if( i < n )
			nums[k++] = nums[i];
	}
	return k;
}
```
