https://leetcode.com/problems/majority-element

# Approach 1

1. Create a `map`.
2. Count all the occurrences.
3. Check which value has count greater than half of size of array.
4. **Note**: To calculate half of size of array: $ceil(float(n)/2)$

**Time Complexity**: $O(n)$
**Space Complexity**: $O(n)$

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        int n = nums.size();
        for(auto x: nums) {
            m[x]++;
        }
        for(auto it: m) {
            cout << it.second;
        }
        for(auto it: m) {
            if(it.second >= ceil(float(n)/2))
                return it.first;
        }
        return -1;
    }
};
```

# Approach 2

**Moore Voting Algorithm**

1. Create 2 variables, 
	1. $curr$ to keep track of current element.
	2. $count$ to keep count of current element.
2. Iterate on the array, while checking all the numbers
3. If the number is equal to $curr$, just increment the $count$.
4. Else decrement the count.
5. Also in this case, check, if the $count$ is already 1, then replace the $curr$ with $nums[i]$.
6. Return the $curr$, in the end as the result.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(1)$

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int curr = nums[0], count = 1;
        for( int i = 1; i < n; ++i ) {
            if( nums[i] == curr )
                ++count;
            else {
                if(count == 1) {
                    curr = nums[i];
                }
                count = max(1, count - 1);
            }
        }
        return curr;
    }
};
```
