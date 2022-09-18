class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> zr, zc;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    zr.insert(i);
                    zc.insert(j);
                }
            }
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (zr.find(i) != zr.end() || zc.find(j) != zc.end())
                    matrix[i][j] = 0;
            }
        }
    }
};