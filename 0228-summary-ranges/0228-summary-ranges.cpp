class Solution {
    string _(int a, int b) {
        string x;
        x += to_string(a);
        x += "->";
        x += to_string(b);
        return x;
    }
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        if (n == 0) return ans;
        if (n == 1) {
            string x;
            x += to_string(nums[0]);
            return {x};
        }
        int low = 0, high = 0;
        for (int i = 0; i < n; ++i) {
            if (i < n - 1 && nums[i] + 1 == nums[i + 1]) ++high;
            else {
                string x;
                if (high == low) {
                    x += to_string(nums[low]);
                } else {
                    x += _(nums[low], nums[high]);
                }
                ans.push_back(x);
                low = i + 1, high = i + 1;
            }
        }
        // string x;
        // if (low == n - 1) {
        //     x += char(nums[n - 1] + '0');
        // } else {
        //     x += char(nums[low] + '0');
        //     x += "->";
        //     x += char(nums[high] + '0');
        // }
        // ans.push_back(x);
        return ans;
    }
};