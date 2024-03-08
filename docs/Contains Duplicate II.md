https://leetcode.com/problems/contains-duplicate-ii

# Approach 1

1. Create a hash map to store the indices of a number being repeated.
2. If the index of the current number and one of indices of the current number satisfies the condition, return `true`.
3. Push the current index in the entry of current number.
4. If none of them satisfied the condition, return `false`.

**Time Complexity**: $O(n^2)$
**Space Complexity**: $O(n^2)$

```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, vector<int>> m;
        for (int i = 0; i < n; ++i) {
            if (m[nums[i]].size() > 0) {
                for(auto x: m[nums[i]]) {
                    if ( abs(x - i) <= k )
                        return true;
                }
            }
            m[nums[i]].push_back(i);
        }
        return false;
    }
};
```