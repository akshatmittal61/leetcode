class Solution
{
    public:
        int threeSumClosest(vector<int> &v, int t)
        {
            sort(v.begin(), v.end());
            int n = v.size();
            int i = 0, j = 0, k = 0;
            int ans = 0, curr = INT_MAX;
            sort(v.begin(), v.end());
            for (int i = 0; i < n - 2; i++)
            {
                j = i + 1, k = n - 1;
                while (j < k)
                {
                    int sum = v[i] + v[j] + v[k];
                    int diff = abs(sum - t);
                    if (diff < curr) curr = diff, ans = sum;
                    if (sum < t) j++;
                    else k--;
                }
            }
            return ans;
        }
};