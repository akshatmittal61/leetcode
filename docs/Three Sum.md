https://leetcode.com/problems/3sum

# Approach 1

1. Create a set of vectors to push non-duplicate triplets $v$
2. Create three loops of $i$, $j$, and $k$.
3. Iterate them in loop-in-loop manner.
4. Check for every triplet whether they sum up to $0$ or not.
5. If the triplet sums to $0$, sort it and push it in $v$.
6. After iterating on the array, create a vector $ans$ from the $v$ set.
7. Return $ans$

**Note**: This approach will result in TLE since it takes $n^3log(n)$ time.

**Time Complexity**: $O(n^3log(n))$
**Space Complexity**: $O(1)$

```cpp
class Solution {
public:
    bool _ (vector<int> v, vector<int> a) {
        return v[a[0]] + v[a[1]] + v[a[2]] == 0;
    }
    vector<vector<int>> threeSum(vector<int>& v) {
        sort(v.begin(), v.end());
        int n = v.size();
        set<vector<int>> f;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    vector<int> a = {i, j, k};
                    sort(a.begin(), a.end());
                    if ( _(v, a) && f.find(a) == f.end() )
                        f.insert({v[i], v[j], v[k]});
                }
            }
        }
        vector<vector<int>> ans(f.begin(), f.end());
        return ans;
    }
};
```

# Approach 2

1. 1. Sort the array $nums$
2. Run a loop of $i$ to iterate over the array.
3. Use $nums[i]$ as the pivot element.
4. Now create two pointers $low$ and $high$, where $low$ is positioned at $i+1$ and $high$ at the end of the array i.e.) $n-1$.
5. If the triplet ($nums[i]$, $nums[low]$, $nums[high]$) sums upto 0, sort the triplet and push it in $ans$ vector.
6. To make sure no duplicate triplet is pushed in the answer vetor, decrease $high$ and increase $low$ until you have reached another distinct element.
7. If the triplet sums to greater than 0, decrease the $high$ pointer.
8. If the triplet sums to less than 0, increase the $low$ pointer.
9. To maintain distinct pivot elements, increase $i$ till it reaches the next distinct element.

**Time Complexity**: $O(n^2)$
**Space Complexity**: $O(1)$
