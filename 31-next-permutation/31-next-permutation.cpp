class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        vector<int> v = nums;
        int n=nums.size();
        int k = -1;
        for (int i = n - 1; i > 0; --i)
        {
            if (v[i] > v[i - 1])
            {
                k = i - 1;
                break;
            }
        }
        if (k == -1)
        {
            sort(v.begin(), v.end());
            nums=v;
            return;
        }
        vector<int>::iterator it = v.begin();
        sort(it + k + 1, v.end());
        for (int i = k; i < n; ++i)
        {
            if (v[i] > v[k])
            {
                swap(v[i], v[k]);
                break;
            }
        }
        nums=v;
    }
};