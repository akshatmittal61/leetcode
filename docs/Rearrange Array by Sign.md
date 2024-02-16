https://leetcode.com/problems/rearrange-array-elements-by-sign

# Approach 1

1. Create 2 arrays, $pos$ and $neg$.
2. Push all positive numbers in $pos$ and all negative members in $neg$.
3. Create a new array $ans$ and push all positive and negative numbers one by one.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(n)$

```cpp
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos, neg, ans;
        for(int x: nums) {
            if( x > 0 )
                pos.push_back(x);
            else
                neg.push_back(x);
        }
        for( int i = 0; i < n / 2; ++i ) {
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        return ans;
    }
};
```

# Approach 2

1. Create an $ans$ array, and two pointers $pos$ and $neg$, to keep track of positive and negative numbers.
2. Keep track of numbers with their respective pointers.
3. Insert positive and negative numbers alternatively in the $ans$ array.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(n)$

```cpp
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int pos = 0, neg = 0;
        while( pos < n && neg < n ) {
            if(nums[pos] > 0 && nums[neg] < 0) {
                ans.push_back(nums[pos]);
                ans.push_back(nums[neg]);
                ++pos, ++neg;
            } else {
                while(nums[pos] < 0) ++pos;
                while(nums[neg] > 0) ++neg;
            }
        }
        return ans;
    }
};
```
