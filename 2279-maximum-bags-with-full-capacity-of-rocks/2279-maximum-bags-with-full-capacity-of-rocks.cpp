class Solution
{
    public:
        int maximumBags(vector<int> &capacity, vector<int> &rocks, int ar)
        {
            int n = rocks.size();
            vector<int> diff(n), id(n);
            for (int i = 0; i < n; ++i) id[i] = i;
            for (int i = 0; i < n; ++i)
                diff[i] = capacity[i] - rocks[i];
            sort(id.begin(), id.end(), [& ](int i, int j)
            {
                return diff[i] < diff[j];
	});
            int ans = 0;
            for (int i: id)
            {
                if (ar >= diff[i]) ++ans, ar -= diff[i];
                else break;
            }
            return ans;
        }
};