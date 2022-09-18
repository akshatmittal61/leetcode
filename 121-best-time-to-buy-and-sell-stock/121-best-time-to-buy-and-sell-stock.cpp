class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int p = INT_MIN;
        int q = INT_MAX;
        for (int i = 0; i < n; ++i)
        {
            q = min(q, prices[i]);
            p = max(p, prices[i] - q);
        }
        return p;
    }
};