class Solution
{
    public:
        vector<int> decode(vector<int> &v, int first)
        {
            vector<int> ans;
            int n = v.size();
            ans.push_back(first);
            for (int i = 0; i < n; ++i)
                ans.push_back(ans[i] ^ v[i]);
            return ans;
        }
};