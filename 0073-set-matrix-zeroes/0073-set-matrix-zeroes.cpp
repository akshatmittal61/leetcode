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
                    matrix[i][j] = 0;
                }
            }
        }
    }
};