class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1) return;
        int big = n - 1, small = 0;
        for (int i = n - 1; i > 0; --i) {
            if (nums[i] <= nums[i - 1]) {
                big = i - 1;
            } else {
                break;
            }
        }
        if (big == n - 1) {
            swap(nums[n - 1], nums[n - 2]);
            return;
        }
        for (int i = big, j = n - 1; i < j; ++i, --j) {
            swap(nums[i], nums[j]);
        }
        if (big == 0) {
            return;
        }
        int bigger = big;
        for (int i = big; i <= n - 1; ++i) {
            if (nums[i] > nums[big - 1]) {
                bigger = i;
                break;
            }
        }
        swap(nums[bigger], nums[big - 1]);
    }
};