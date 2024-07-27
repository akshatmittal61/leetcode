class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int top = 0, right = c - 1, bottom = r - 1, left = 0;
        char dir = 'e';
        vector<int> ans;
        while (top <= bottom && left <= right) {
            if (dir == 'e') {
                for(int i = left; i <= right; ++i) {
                    ans.push_back(matrix[top][i]);
                }
                ++top;
                dir = 's';
            } else if (dir == 's') {
                for(int i = top; i <= bottom; ++i) {
                    ans.push_back(matrix[i][right]);
                }
                --right;
                dir = 'w';
            } else if (dir == 'w') {
                for(int i = right; i >= left; --i) {
                    ans.push_back(matrix[bottom][i]);
                }
                --bottom;
                dir = 'n';
            } else if (dir == 'n') {
                for(int i = bottom; i >= top; --i) {
                    ans.push_back(matrix[i][left]);
                }
                ++left;
                dir = 'e';
            }
        }
        return ans;
    }
};