https://leetcode.com/problems/rotate-array

# Approach 1

1. Create another empty array, $v$ of same size.
2. Iterate array $nums$ from $0$ to $n-k$, and insert that in $v$ from $i+k$
3. Iterate array $nums$ from $0$ to $k$, and insert that in $v$ from $i$, from $nums[n+i-k]$
4. Assign the new array $v$ to $nums$.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(n)$

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        vector<int> v(n, 0);
        for(int i = 0; i < n - k; ++i) {
            v[i + k] = nums[i];
        }
        for(int i = 0; i < k; ++i) {
            v[i] = nums[n + i - k];
        }
        nums = v;
    }
};
```
# Approach 2

**Reverse partial arrays**

1. Flip $nums$ from $0$ to $n-k-1$.
2. Flip $nums$ from $n-k$ to $n-1$.
3. Flip $nums$ from $0$ to $n-1$.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(1)$

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        for(int i = 0, j = n - k - 1; i < j; ++i, --j) {
            swap(nums[i], nums[j]);
        }
        for(int i = n - k, j = n - 1; i < j; ++i, --j) {
            swap(nums[i], nums[j]);
        }
        for(int i = 0, j = n - 1; i < j; ++i, --j) {
            swap(nums[i], nums[j]);
        }
    }
};
```