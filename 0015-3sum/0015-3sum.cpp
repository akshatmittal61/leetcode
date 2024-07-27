class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n - 2; ++i) {
            int low = i + 1, high = n - 1;
            while (low < high) {
                int s = nums[i] + nums[high] + nums[low];
                if (s == 0) {
                    vector<int> v = {nums[i], nums[low], nums[high]};
                    sort(v.begin(), v.end());
                    ans.push_back(v);
                    while(high>low && nums[high] == nums[high - 1]) {
                        --high;
                    }
                    while(low<high && nums[low] == nums[low + 1]) {
                        ++low;
                    }
                    --high, ++low;
                } else if (s > 0) {
                    --high;
                } else {
                    ++low;
                }
            }
            while(i < n - 1 && nums[i] == nums[i + 1]) {
                ++i;
            }
        }
        return ans;
    }
};