https://leetcode.com/problems/h-index

# Approach 1

1. We need to return maximum value of $x$ where 'at least $x$ papers which were published $x$ or more than $x$ times'.
2. Sort the array in ascending order.
3. Start iterating from the last.
4. If the number of citations for this paper i.e.) $nums[i]$ is more than or equal to number of papers with more or equal citations with this one, then just check for the lower one.
5. Else, return the minimum of the previous number of citations, and its count.
6. Although if the highest count is $0$, then it means no citations were ever printed. Just return $0$ in this case.
7. For base cases, if there is only one citations, just check if it was ever printed or not. If it was return $1$ else return $0$.
8. If all the citations are traversed, just return the minimum of number of citations of first element and total number of citations.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(1)$

```cpp
class Solution {
public:
    int hIndex(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            if( nums[0] >= 1 )
                return 1;
            return 0;
        }
        sort(nums.begin(), nums.end());
        for(int i = n - 1; i >= 0; --i) {
            if( nums[i] >= n - i )
                continue;
            else {
                if( i == n - 1 ) return 0;
                return min(nums[i + 1], n - i - 1);
            }
        }
        return min(nums[0], n);
    }
};
```