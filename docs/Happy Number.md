https://leetcode.com/problems/happy-number

# Idea

- Start by checking the sum of squares of all digits in the number.
- If the number is 1, return `true`.
- If the number is repeated, that means it will lead to infinite loop, return `false`.

# Approach 1 (Hash set)

1. Create a has set to store the numbers which have been traced already.
2. Get the sum of squares of all digits and store it in `val`.
3. Check if `val` is $1$.
4. If yes, return `true`.
5. Else, if `val` is in the hash set, return `false`, this will lead to repetition.
6. Else insert `val` in the hash set.
7. Replace the original number by `val`.

**Time Complexity**: $O(n * log(n))$
**Space Complexity**: $O(n)$

```cpp
class Solution {
public:
    int getSumOfSquaresOfDigits (int n) {
        int ans = 0;
        while ( n != 0 ) {
            int k = n % 10;
            ans += (k * k);
            n /= 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        set<int> s;
        while ( n != 1 && s.find(n) == s.end() ) {
            int k = getSumOfSquaresOfDigits(n);
            if ( k == 1 )
                return true;
            if ( s.size() > 0 ) {
                if (s.find(k) != s.end())
                    return false;
            }
            s.insert(n);
            n = k;
        }
        return n == 1;
    }
};
```

# Approach 2 (recursion)

1. If it is a one-digit number, it will satisfy only in case of `1` and `7`, all other digits lead to infinite loop.
2. Repeat this recursively.
3. Get the sum of squares of digits of the number.
4. Check if this value is happy or not.

**Time Complexity**: 
**Space Complexity**: 

```cpp
class Solution {
public:
    int getSumOfSquaresOfDigits (int n) {
        int ans = 0;
        while ( n != 0 ) {
            int k = n % 10;
            ans += (k * k);
            n /= 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        if ( n < 10 )
            return n == 1 || n == 7;
        int k = getSumOfSquaresOfDigits(n);
        return isHappy(k);
    }
};
```