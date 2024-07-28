class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i = n - 1;
        if(n == 1) return;
        while (i > 0 && nums[i] < nums[i - 1]) {
            --i;
        }
        if(i == n - 1) {
            swap(nums[i], nums[i - 1]);
            return;
        }
        for (int j = n - 1, k = i; k <= j; ++k, --j) {
            swap(nums[j], nums[k]);
        }
        if(i != 0) {
            int p = i;
            for(int k = i; k < n; ++k) {
                if(nums[k] > nums[i - 1]) {
                    p = k;
                    break;
                }
            }
            swap(nums[p], nums[i - 1]);
        }
    }
};