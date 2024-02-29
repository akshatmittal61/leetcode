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