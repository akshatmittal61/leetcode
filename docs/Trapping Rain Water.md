https://leetcode.com/problems/trapping-rain-water

# Idea
Water can be stored only up to the height, that is the min of max block height and current block height, storing in a cup-like situation.
# Approach 1

1. Start iterating on the complete array.
2. For every block, get the max height of a block on the left and that on the right.
3. Find the min block height among $left\_max$ and $right\_max$.
4. If the max block height is greater than the current block height, add it to the $ans$.
5. Repeat the same for every block.
6. Return the final $ans$.

**Time Complexity**: $O(n^2)$
**Space Complexity**: $O(1)$

```cpp
class Solution {
public:
    int trap(vector<int>& v) {
        int n = v.size(), ans = 0;
        for(int i = 0; i < n; ++i) {
            int lm = 0, rm = 0;
            // get max height from left side
            for(int j = 0; j < i; ++j) {
                lm = max(lm, v[j]);
            }
            // get max height from right side
            for(int j = i; j < n; ++j) {
                rm = max(rm, v[j]);
            }
            // get min height of both
            int lr = min(lm, rm);
            // add to ans, if any amount of water can be added
            ans += max(0, lr - v[i]);
        }
        return ans;
    }
};
```

# Approach 2

1. Instead of calculating max height of left and right side for every element separately, calculate that before the main iteration.
2. Store the value of max height on left and right in separate arrays to be used in the main iteration.
3. In the main iteration, check for the minimum height on left and right side, for the current block.
4. If it is possible to fill water above it, add the amount to the $ans$.
5. Repeat the last step for all blocks.
6. Return $ans$.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(n)$

```cpp
class Solution {
public:
    int trap(vector<int>& v) {
        int n = v.size(), ans = 0;
        vector<int> lm(n, 0), rm(n, 0);
        lm[0] = v[0], rm[n - 1] = v[n - 1];
        for(int i = 1, j = n - 2; i < n && j >= 0; ++i, --j) {
            lm[i] = max(lm[i - 1], v[i]);
            rm[j] = max(rm[j + 1], v[j]);
        }
        for(int i = 0; i < n; ++i) {
            int lr = min(lm[i], rm[i]);
            // add to ans, if any amount of water can be added
            ans += max(0, lr - v[i]);
        }
        return ans;
    }
};
```

# Approach 3

1. Instead of creating arrays for storing the left and right max lengths, check on the fly for one block.
2. Create two pointers, $left$ and $right$, and put one on beginning and another on end respectively.
3. Create 2 more pointers, $left\_max$ and $right\_max$, for storing the max height of blocks checked until certain point.
4. Start iterating from both sides.
5. If the left block's height is smaller than right block's height, check if it is also smaller than $left\_max$.
6. If yes then add to $ans$, the amount of water that can be held on it, else no water can be stored on it and increase $left$ pointer by $1$.
7. Repeat the same for $right$ too.
8. Continue iterating until the $left$ and $right$ meet.
9. Return the $ans$.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(1)$

```cpp
class Solution {
public:
    int trap(vector<int>& v) {
        int n = v.size(), ans = 0;
        int l = 0, r = n - 1;
        int lm = v[0], rm = v[n - 1];
        while(l < r) {
            if(v[l] < v[r]) {
                if(v[l] < lm) {
                    ans += min(lm, v[r]) - v[l];
                } else {
                    lm = v[l];
                }
                ++l;
            } else {
                if(v[r] < rm) {
                    ans += min(rm, v[l]) - v[r];
                } else {
                    rm = v[r];
                }
                --r;
            }
        }
        return ans;
    }
};
```