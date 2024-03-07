https://leetcode.com/problems/two-sum

# Approach 1

1. Create a hash-map.
2. Start iterating on the array.
3. Check if the difference between `target` and current number is there in the map.
4. If yes, then you found the pair, return the `index` and the value of the difference in the map.
5. Else, insert the value of the value of $i^{th}$ element in the map with $i^{th}$ index.

**Time Complexity**: $O(n * log(n))$
**Space Complexity**: $O(n)$

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            int k = target - nums[i];
            if( m.find(k) != m.end() ) {
                return {i, m[k]};
            } else {
                m[nums[i]] = i;
            }
        }
        return {};
    }
};
```