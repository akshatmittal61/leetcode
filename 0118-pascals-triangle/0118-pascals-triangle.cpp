class Solution
{
    public:
        vector<vector < int>> generate(int nr)
        {
            vector<vector < int>> ans;
            for (int i = 0; i < nr; ++i)
            {
                vector<int> r;
                r.push_back(1);
                for (int j = 1; j < i; ++j)
                    r.push_back(ans[i - 1][j] + ans[i - 1][j - 1]);
                if (i != 0) r.push_back(1);
                ans.push_back(r);
            }
            return ans;
        }
};