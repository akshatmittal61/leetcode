class Solution
{
    public:
        vector<int> spiralOrder(vector<vector < int>> &matrix)
        {
            char c = 'e';
            vector<int> ans;
            int m = matrix.size(), n = matrix[0].size();
            int top = 0, down = m - 1, left = 0, right = n - 1;
            while (top <= down && left <= right)
            {
                if (c == 'e')
                {
                    for (int i = left; i <= right; ++i)
                        ans.push_back(matrix[top][i]);
                    c = 's', ++top;
                }
                else if (c == 's')
                {
                    for (int i = top; i <= down; ++i)
                        ans.push_back(matrix[i][right]);
                    c = 'w', --right;
                }
                else if (c == 'w')
                {
                    for (int i = right; i >= left; --i)
                        ans.push_back(matrix[down][i]);
                    c = 'n', --down;
                }
                else if (c == 'n')
                {
                    for (int i = down; i >= top; --i)
                        ans.push_back(matrix[i][left]);
                    c = 'e', ++left;
                }
            }
            return ans;
        }
};