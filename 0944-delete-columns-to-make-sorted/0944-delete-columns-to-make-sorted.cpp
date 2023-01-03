class Solution
{
    bool checkCol(vector<string> strs, int id)
    {
        int n = strs.size();
        for (int i = 0; i < n - 1; ++i)
        {
            if (strs[i][id] > strs[i + 1][id]) return false;
        }
        return true;
    }
    public:
        int minDeletionSize(vector<string> &strs)
        {
            int n = strs[0].length();
            int ans = 0;
            for (int i = 0; i < n; ++i)
                ans += !checkCol(strs, i);
            return ans;
        }
};