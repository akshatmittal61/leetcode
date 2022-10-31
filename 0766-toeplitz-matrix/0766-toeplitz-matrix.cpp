class Solution
{
    public:
        bool isToeplitzMatrix(vector<vector < int>> &matrix)
        {
            int n = matrix.size(), m = matrix[0].size();
           	//first row
            for (int k = 0; k < m; ++k)
            {
                for (int i = 0, j = k; i < n - 1 && j < m - 1; ++i, ++j)
                {
                    if (matrix[i][j] != matrix[i + 1][j + 1]) return false;
                }
            }
           	//first column
            for (int k = 0; k < n; ++k)
            {
                for (int i = k, j = 0; i < n - 1 && j < m - 1; ++i, ++j)
                {
                    if (matrix[i][j] != matrix[i + 1][j + 1]) return false;
                }
            }
            return true;
        }
};