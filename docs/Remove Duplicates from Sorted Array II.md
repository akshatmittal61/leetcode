https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii

# Approach 1

1. Create variables, 
	1. $curr$ -> to keep check of current number
	2. $count$ -> to keep count of current number
	3. $k$  -> the pointer where to write the next number
2. If array has length less than or equal to 2, return it as such.
3. Start counting the repeating numbers.
4. If it just occurs once, insert it on the $k$ place, and increase $k$
5. Else insert on $k$ and $k+1$ place, and increase $k$ by 2.
6. Repeat the same thing after the loop for the last item.
7. Return $k$ pointer.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(1)$

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), k = 0, count = 0, curr = INT_MIN;
        if(n <= 2)
            return n;
        for(int i = 0; i < n; ++i) {
            if( count == 0 ) {
                count++;
                curr = nums[i];
            } else {
                if( nums[i] == curr ) {
                    ++count;
                } else {
                    if( count == 1 ) {
                        nums[k] = nums[i - 1];
                        ++k;
                    } else {
                        nums[k] = nums[i - 1];
                        nums[k + 1] = nums[i - 1];
                        k += 2;
                    }
                    count = 1;
                    curr = nums[i];
                }
            }
        }
        if( count == 1 ) {
            nums[k] = nums[n - 1];
            ++k;
        } else {
            nums[k] = nums[n - 1];
            nums[k + 1] = nums[n - 1];
            k += 2;
        }
        return k;
    }
};
```