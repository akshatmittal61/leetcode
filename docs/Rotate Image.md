https://leetcode.com/problems/rotate-image/

# Approach 1

1. Create a 2-D matrix and rotate the whole thing manually like [[Spiral Matrix]].

**Time Complexity**: $O(n^2)$
**Space Complexity**: $O(n^2)$
# Approach 2

1. Flip the matrix diagonally.
2. Then, flip the matrix vertically.

**Time Complexity**: $O(n^2)$
**Space Complexity**: $O(1)$

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for ( int i = 0; i < n; ++i ) {
            for ( int j = i + 1; j < n; ++j )
                swap(matrix[i][j], matrix[j][i]);
        }
        for ( int i = 0; i < n; ++i ) {
            for ( int j = 0; j < n / 2; ++j ) {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
};
```