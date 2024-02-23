https://leetcode.com/problems/bitwise-and-of-numbers-range

# Approach 1

1. Create a variable $ans$.
2. Iterate on the complete range from left to right, keep calculating the $AND$ of every number with $ans$.
3. Return the final value of $ans$.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(1)$
**Note**: This results into `TLE`, since for the given constraint range, we can run out of memory time.

```cpp
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = left;
        for (int i = left + 1; i <= right; ++i) {
            ans &= i;
        }
        return ans;
    }
};
```

# Approach 2

1. Check if $left$ and $right$ are equal, if yes then the answer is the number itself, return it.
2. If $0$ lies between $left$ and $right$, then the $AND$ of the range will always return $0$. Return $0$.
3. If there is a power of $2$ lying between $left$ and $right$, then while checking in the bit form, the trailing will be made $0$ by $2^x$ and any single number preceding that $2^x$, will make the it's $1$ to $0$. Hence return $0$ if $left < 2^x <= right$.
4. If the $left$ is a $2^x$, then check if $2^{x+1}$ is in the range.
5. If yes, then they will cancel each others' bits, thus making the result $0$.
6. If no, then all the other bits will be made $0$ by the trailing $0s$ of $2^x$, return $left$.
7. If none of the above conditions satisfy, then definitely the range has size less than $2^{z+1} - 2^x$, and will never result into a `TLE`.
8. Calculate the $AND$ of the range by brute force.
9. Return the final answer.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(1)$

```cpp
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if (left == right) {
            return left;
        }
        if (left <=0 && right >= 0) {
            return 0;
        }
        double l_log = log2(left);
        double r_log = log2(right);
        int log_left = ceil(l_log);
        int log_right = floor(r_log);
        if ( l_log < log_left && log_left <= r_log )
            return 0;
        if ( l_log == log_left ) {
            if( log_right > log_left ) {
                return 0;
            } else {
                return left;
            }
        }
        long long int ans = left;
        for (long long int i = left + 1; i <= right; ++i) {
            if ( ans == 0 )
                return 0;
            ans &= i;
        }
        return ans;
    }
};
```

# Approach 3

1. Create a count variable $k$.
2. Start a $while$ loop against the condition whether $left$ is equal to $right$ or not.
3. Start left shifting $left$ and $right$ by 1 in each iteration.
4. This will remove all the non-similar bits, one by one from the right side.
5. Make sure to increment the counter $k$ on every iteration.
6. After the loop, $k$ is storing the count of dissimilar bits.
7. When operated under $AND$, thy will result to $0$.
8. Append $k$ zeroes to the new $left$.
9. Return the final answer.

**Time Complexity**: $O(log(n))$
**Space Complexity**: $O(1)$

```cpp
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int k = 0;
        while(left != right) {
            left >>= 1;
            right >>= 1;
            ++k;
        }
        return (left << k);
    }
};
```