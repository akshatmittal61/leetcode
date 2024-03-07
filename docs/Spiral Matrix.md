https://leetcode.com/problems/spiral-matrix/

# Approach 1

1. Assume a hypothetical cursor tracing the matrix in spiral fashion.
2. Create 4 variables to keep track of the cursor limits and initiate them with boundary values -> `top = 0`, `bottom = no_of_rows - 1`, `left = 0`, `right = no_of_columns - 1`
3. Create a direction store, $c$ to store the current direction of the cursor as `east`, `north` and so on.
4. Create a $1-D$ vector, `ans` to store the iteration of a cursor as a row.
5. Start iterating on the matrix, till the size of `ans` is smaller than `m * n` i.e.) any number is left from iteration.
6. Start iterating on the matrix.
7. If the direction is `east`, move cursor from `left` to `right` and push every iterated number in `ans`.
8. At the end of this horizontal move, increment `top` as a row from top has been iterated and update the direction to `south`, since the cursor needs to go downward.
9. Repeat the same for all directions.
10. At the end, return the `ans`.

**Time Complexity**: $O(m*n)$
**Space Complexity**: $O(m*n)$

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0, right = n - 1, bottom = m - 1, left = 0;
        char c = 'e';
        vector<int> ans;
        while ( ans.size() < m * n ) {
            if ( c == 'e' ) {
                for (int i = left; i <= right; ++i) {
                    ans.push_back(matrix[top][i]);
                }
                ++top;
                c = 's';
            } else if ( c == 's' ) {
                for (int i = top; i <= bottom; ++i) {
                    ans.push_back(matrix[i][right]);
                }
                --right;
                c = 'w';
            } else if ( c == 'w' ) {
                for (int i = right; i >= left; --i) {
                    ans.push_back(matrix[bottom][i]);
                }
                --bottom;
                c = 'n';
            } else if ( c == 'n' ) {
                for (int i = bottom; i >= top; --i) {
                    ans.push_back(matrix[i][left]);
                }
                ++left;
                c = 'e';
            }
        }
        return ans;
    }
};
```