class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n=rowIndex;
        vector<vector<int>> ans = {{1}};
        for (int i = 1; i <= n; ++i)
        {
            vector<int> t = {1};
            for (int j = 1; j < i; ++j)
                t.push_back(ans[i - 1][j] + ans[i - 1][j - 1]);
            t.push_back(1);
            ans.push_back(t);
        }
        return ans[rowIndex];
    }
};