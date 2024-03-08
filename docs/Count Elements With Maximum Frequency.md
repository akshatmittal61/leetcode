https://leetcode.com/problems/count-elements-with-maximum-frequency

# Approach 1

1. Create a hash map to count frequencies of the numbers in the array.
2. Check for the maximum frequency.
3. Iterate on the hash map, those elements whose frequency matches to that of maximum frequency, add the count of those in `ans`.
4. Return `ans`.

**Time Complexity**: $O(n * log(n))$
**Space Complexity**: $O(n)$

```cpp
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> m;
        for ( auto x: nums ) {
            m[x]++;
        }
        int k = INT_MIN;
        for ( auto it: m ) {
            k = max(k, it.second);
        }
        int ans = 0;
        for ( auto it: m ) {
            if (it.second == k) {
                ans += k;
            }
        }
        return ans;
    }
};
```