https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals

# Approach 1

1. Sort the array.
2. Count the occurrences of every number.
3. Create a $vector$ or integer pairs, and store the count of each number as first and the number itself in the second.
4. Sort the new vector in ascending order of the count.
5. Now reduce the count of least occurring number by comparing against $k$, the number of values to be removed.
6. Continue the process till you have exhausted your $k$.
7. Count the number which still have count greater than 0, and return that.

**Time Complexity**: $O(n log(n))$
**Space Complexity**: $O(log(n))$

```cpp
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        map<int, int> m;
        for(int x: arr) {
            m[x]++;
        }
        vector<pair<int, int>> counts;
        for(auto it: m) {
            counts.push_back({it.second, it.first});
        }
        sort(counts.begin(), counts.end());
        int cc = counts.size();
        for(int i = 0; i < cc && k > 0; ++i) {
            if( counts[i].first <= k ) {
                m[counts[i].second] -= counts[i].first;
                k -= counts[i].first;
            } else {
                m[counts[i].second] -= k;
                k = 0;
            }
        }
        int ans = 0;
        for(auto it: m) {
            if(it.second > 0)
                ++ans;
        }
        return ans;
    }
};
```