https://leetcode.com/problems/candy

# Approach 1

1. Create $2$ arrays, $left\_to\_right$ and $right\_to\_left$ of $n$ size and initialize them by 1.
2. Iterate on the array from index 1, towards right. Check if the previous kid has higher rating, then give the present kid candies 1 more than previous one and store them in $left\_to\_right$.
3. Repeat the same for $right\_to\_left$.
4. Now iterate from $0$ to $n$, and compare between the the $i^{th}$  value of 2 arrays.
5. Add the maximum value in $ans$.
6. Return $ans$.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(n)$

```cpp
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum = 0;
        vector<int> lr(n, 1), rl(n, 1);
        for(int i = 1;i < n; ++i) {
            if(ratings[i] > ratings[i - 1])
                lr[i] = lr[i - 1] + 1;
        }
        for(int i = n - 1;i > 0; --i) {
            if(ratings[i - 1] > ratings[i])
                rl[i - 1] = rl[i] + 1;
        }
        for(int i = 0; i < n; ++i) {
            sum += max(lr[i], rl[i]);
        }
        return sum;
    }
};
```