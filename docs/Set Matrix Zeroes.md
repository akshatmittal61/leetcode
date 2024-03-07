https://leetcode.com/problems/set-matrix-zeroes/

# Approach 1

1. Create two sets, `r` and `c` to store which rows and columns store zeroes.
2. After that, iterate on the matrix, if the row or column match the index, set it to `0`.

**Time Complexity**: $O(n^2)$
**Space Complexity**: $O(max(m,n))$

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int>r, c;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == 0) {
                    r.insert(i);
                    c.insert(j);
                }
            }
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(r.find(i) != r.end() || c.find(j) != c.end()) {
                    matrix[i][j]=0;
                }
            }
        }
    }
};
```