class Solution
{
    public:
        bool increasingTriplet(vector<int> &v)
        {
            int n = v.size();
            int l, m, r;
            l = m = r = INT_MAX;
            for (int i = 0; i < n; i++)
            {
                if (v[i] <= l) l = v[i];
                else if (v[i] <= m) m = v[i];
                else return true;
            }
            return false;
        }
};