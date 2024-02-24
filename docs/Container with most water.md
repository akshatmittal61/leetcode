https://leetcode.com/problems/container-with-most-water

# Approach 1

1. We will use two pointer approach.
2. Create two pointers $low$ and $high$ and put them on both ends of array.
3. Keep iterating on array, until $low$ is lesser than $high$.
4. Calculate the area for every $low$ and $high$, by `(high - low) * min(v[low], v[high])`
5. If current area is bigger than $ans$, replace it.
6. If height of $low$ block is higher, decrement $high$ and vice versa.
7. Return final $ans$.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(1)$

```cpp
class Solution {
public:
    int maxArea(vector<int>& v) {
        int n = v.size();
        int ans = INT_MIN;
        int low = 0, high = n - 1;
        while ( low < high ) {
            int k = (high - low) * min(v[low], v[high]);
            if ( k > ans )
                ans = k;
            if ( v[low] > v[high] )
                --high;
            else
                ++low;
        }
        return ans;
    }
};
```